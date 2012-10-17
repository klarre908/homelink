#ifndef __HOME_DATABASE_H__
#define __HOME_DATABASE_H__

typedef struct st_mysql MYSQL;

namespace Home
{
	class Database
	{
	public:
		Database(const char* address
				, unsigned int port
				, const char* user
				, const char* passwd
				, const char* db);
		~Database();

		void openTable(const char* name);
		void closeTable();

	private:
		MYSQL* mMySql;
	};
}

#endif
