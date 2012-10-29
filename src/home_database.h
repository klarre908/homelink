#ifndef __HOME_DATABASE_H__
#define __HOME_DATABASE_H__

typedef struct st_mysql MYSQL;
typedef struct st_mysql_res MYSQL_RES;
typedef char** MYSQL_ROW;

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

		int query(const char* command) const;
		MYSQL_RES* getResult() const;
		unsigned long long getNumRows(MYSQL_RES* result) const;
		unsigned int getNumFields(MYSQL_RES* result) const;
		MYSQL_ROW getRow(MYSQL_RES* result) const;

	private:
		MYSQL* mMySql;
	};
}

#endif
