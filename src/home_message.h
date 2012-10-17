#ifndef __HOME_MESSAGE_H__
#define __HOME_MESSAGE_H__

#include <string>
#include <vector>

namespace Home
{
	class Action;
	class Database;

	class Message
	{
	public:
		Message(const std::string& client
				, const std::string& username
				, const std::string& password
				, const std::string& ip);

		void addAction(Action* action);

		void executeActions(Database* db);

	private:
		std::string mClient;
		std::string mUsername;
		std::string mPassword;
		std::string mIp;

		std::vector<Action*> mActions;
	};
}

#endif
