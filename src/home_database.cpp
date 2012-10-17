#include "home_database.h"
#include <my_global.h>
#include <mysql.h>

namespace Home
{
	// -------------------------------------------------------------------------
	Database::Database(const char* address
			, unsigned int port
			, const char* user
			, const char* passwd
			, const char* db)
	{
		MYSQL* mMySql = mysql_init(0);

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

		MYSQL_RES* res_set; /* Create a pointer to recieve the return value.*/
		MYSQL_ROW row;  /* Assign variable for rows. */
		mysql_query(mMySql, "SELECT * FROM movies");

		unsigned int i = 0; /* Create a counter for the rows */
		res_set = mysql_store_result(mMySql); /* Receive the result and store it in res_set */
		unsigned int numrows = mysql_num_rows(res_set); /* Create the count to print all rows */

		while ((row = mysql_fetch_row(res_set)) != NULL)
		{
			printf("%s\n",row[i] != NULL ?
			row[i] : "NULL"); /* Print the row data */
		}
	}

	// -------------------------------------------------------------------------
	Database::~Database()
	{
		mysql_close(mMySql);   /* Close and shutdown */
	}
}
