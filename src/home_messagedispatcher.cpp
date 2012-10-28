#include "home_messagedispatcher.h"
#include "home_message.h"
#include "home_switchonaction.h"
#include "home_switchoffaction.h"
#include "home_switchdimaction.h"
#include "home_util.h"
#include <string>
#include <rapidxml.hpp>
#include <cstdio>

namespace Home
{
	// -------------------------------------------------------------------------
	MessageDispatcher::MessageDispatcher(Database* db)
		: mDb(db)
	{
	}

	// -------------------------------------------------------------------------
	void MessageDispatcher::onMessage(const char* message, const std::string& fromIp)
	{
		std::string msg = message;
		std::size_t p = msg.find("\r\n\r\n");
		if(p != std::string::npos)
		{
			std::string body = msg.substr(p + 4);

			rapidxml::xml_document<> doc;
			doc.parse<0>((char*)body.c_str());
			if(rapidxml::xml_node<>* message = doc.first_node("message"))
			{
				const char* sClient = 0;
				const char* sUsername = 0;
				const char* sPassword = 0;
				Message* m = 0;
				if(rapidxml::xml_node<>* header = message->first_node("header"))
				{
					if(rapidxml::xml_node<>* client = header->first_node("client"))
						sClient = client->value(); 
					if(rapidxml::xml_node<>* username = header->first_node("username"))
						sUsername = username->value();
					if(rapidxml::xml_node<>* password = header->first_node("password"))
						sPassword = password->value();
				}

				if(sClient && sUsername && sPassword)
					m = new Message(sClient, sUsername, sPassword, fromIp);

				if(rapidxml::xml_node<>* body = message->first_node("body"))
				{
					if(rapidxml::xml_node<>* actions = body->first_node("actions"))
					{
						rapidxml::xml_node<>* action = actions->first_node("action");
						while(action)
						{
							std::string t;
							if(rapidxml::xml_attribute<>* type = action->first_attribute("type"))
							{
								if(const char* value = type->value())
									t = value;
							}

							if(t == "set_permission")
								;
							else if(t == "set_switch")
							{
								std::string sId;
								std::string sValue;
								if(rapidxml::xml_node<>* id = action->first_node("id"))
									sId = id->value();
								if(rapidxml::xml_node<>* value = action->first_node("value"))
									sValue = value->value();
								if(!sId.empty() && !sValue.empty())
								{
									if(sValue == "on")
										m->addAction(new SwitchOnAction(Util::s2i(sId)));
									else if(sValue == "off")
										m->addAction(new SwitchOffAction(Util::s2i(sId)));
									else
									{
										printf(sId.c_str());
										printf(sValue.c_str());
										m->addAction(new SwitchDimAction(Util::s2i(sId), (unsigned char)Util::s2i(sValue)));
									}
								}
							}
							else if(t == "get_switches_status")
								;

							action = action->next_sibling("action");
						}
					}
				}

				if(m)
				{
					m->executeActions(mDb);
					delete m;
				}
				else
					printf("Invalid message received");
			}
		}
	}
}

/*
<?xml version="1.0" encoding="UTF-8"?>
<message>
	<header>
		<client>Mozilla Firefox</client>
		<username>Jason Storhed</username>
		<password>anvc334e9vcij903vkclv09</password>
	</header>
	<body>
		<actions>
			<action type="set_profile">cousy</action>
			<action type="set_permission"></action>
			<action type="set_switch">
				<id></id>
				<value>255</value>
			</action>
			<action type="get_switches_status" />
		</actions>
	</body>
</message>
*/
