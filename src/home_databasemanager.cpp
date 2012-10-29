#include "home_databasemanager.h"
#include "home_database.h"
#include "home_dbuser.h"
#include "home_util.h"
#include <cstdio>

namespace Home
{
	// -------------------------------------------------------------------------
	DatabaseManager::DatabaseManager(Home::Database *db)
		: mDb(db)
	{
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::load(DbUser& user, int id) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM users WHERE id='%d';", id);
		if(mDb->query(buffer))
			return false;

		if(MYSQL_RES* result = mDb->getResult())
		{
			unsigned int numFields = mDb->getNumFields(result);
			if(MYSQL_ROW row = mDb->getRow(result))
			{
				if(char* id = row[0])
					user.setId(Util::s2i(id));
				//if(char* date_created = row[1])
				//	user.setDateCreated(DateTime(date_created));
				if(char* username = row[2])
					user.setUsername(username);
				if(char* password = row[3])
					user.setPassword(password);
				if(char* email = row[4])
					user.setEmail(email);
				if(char* first_name = row[5])
					user.setFirstName(first_name);
				if(char* last_name = row[6])
					user.setLastName(last_name);
				//if(char* last_login = row[7])
				//	user.setLastLogin(DateTime(last_login));
				//if(char* expires = row[8])
				//	user.setExpires(expires);
			}
		}
		else
			return false;

		return true;
	}
}
