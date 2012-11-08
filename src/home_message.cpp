#include "home_message.h"
#include "home_action.h"

namespace Home
{
	// -------------------------------------------------------------------------
	Message::Message(const std::string& client
			, const std::string& username
			, const std::string& password
			, const std::string& ip)
		: mClient(client)
		, mUsername(username)
		, mPassword(password)
		, mIp(ip)
	{
	}

	// -------------------------------------------------------------------------
	void Message::addAction(Action* action)
	{
		mActions.push_back(action);
	}

	// -------------------------------------------------------------------------
	void Message::executeActions(Database* db)
	{
		for(std::vector<Action*>::iterator i = mActions.begin()
				; i != mActions.end(); ++i)
		{
			(*i)->onAction();
			delete *i;
		}

		mActions.clear();
	}
}
