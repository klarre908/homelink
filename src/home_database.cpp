#include "home_database.h"
#ifdef WIN32
#	include "my_global.h"
#	include "mysql.h"
#	include "errmsg.h"
#else
#	include <mysql/my_global.h>
#	include <mysql/mysql.h>
#endif

namespace Home
{
	// -------------------------------------------------------------------------
	Database::Database(const char* address
			, unsigned int port
			, const char* user
			, const char* passwd
			, const char* db)
	{
		mMySql = mysql_init(0);

		if(mMySql == 0)
		{
			printf("Failed to initialize MySQL\n");

			return;
		}

		mMySql = mysql_real_connect(mMySql, address, user, passwd, db, port, 0, 0);

		if(mMySql == 0)
		{
			printf("Failed to connect to database %s@%s:%d\n", user, address, port);

			return;
		}
	}

	// -------------------------------------------------------------------------
	Database::~Database()
	{
		mysql_close(mMySql);
	}

	// -------------------------------------------------------------------------
	int Database::query(const char* command) const
	{
		int result = mysql_query(mMySql, command);

		switch(result)
		{
		case CR_COMMANDS_OUT_OF_SYNC:
			break;
		}

		return result;
	}

	// -------------------------------------------------------------------------
	MYSQL_RES* Database::getResult() const
	{
		return mysql_store_result(mMySql);
	}

	// -------------------------------------------------------------------------
	unsigned long long Database::getNumRows(MYSQL_RES* result) const
	{
		return mysql_num_rows(result);
	}

	// -------------------------------------------------------------------------
	unsigned int Database::getNumFields(MYSQL_RES* result) const
	{
		return mysql_num_fields(result);
	}

	// -------------------------------------------------------------------------
	MYSQL_ROW Database::getRow(MYSQL_RES* result) const
	{
		return mysql_fetch_row(result);
	}
}
