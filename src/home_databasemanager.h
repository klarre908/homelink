#ifndef __HOME_DATABASEMANAGER_H__
#define __HOME_DATABASEMANAGER_H__

namespace Home
{
	class DbUser;
	class Database;

	class DatabaseManager
	{
	public:
		DatabaseManager(Database* db);

		bool load(DbUser& user, int id) const;

	private:
		Database* mDb;
	};
}

#endif
