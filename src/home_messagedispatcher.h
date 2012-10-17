#ifndef __HOME_MESSAGEDISPATCHER_H__
#define __HOME_MESSAGEDISPATCHER_H__

#include "home_messagelistener.h"

namespace Home
{
	class Database;

	class MessageDispatcher : public MessageListener
	{
	public:
		MessageDispatcher(Database* db);

		virtual void onMessage(const char* message, const std::string& fromIp);

	private:
		Database* mDb;
	};
}

#endif
