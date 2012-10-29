#ifndef __HOME_DATABASEMANAGER_H__
#define __HOME_DATABASEMANAGER_H__

#include <string>

namespace Home
{
	class DbUser;
	class Database;

	class DatabaseManager
	{
	public:
		DatabaseManager(Database* db);

		bool insert(DbUser& user) const;

		bool update(DbUser& user) const;

		bool selectByUsername(DbUser& user, const std::string& username) const;
		bool selectById(DbUser& user, int id) const;

		bool isUsernameTaken(const std::string& username) const;

	private:
		bool select(DbUser& user, const char* command) const;

		Database* mDb;
	};
}

#endif
