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
	bool DatabaseManager::insert(DbUser& user) const
	{
		char buffer[1024];
		sprintf(buffer, "INSERT INTO users (date_created,username,password,email,first_name,last_name) VALUES ('%s','%s','%s','%s','%s','%s');"
				, DateTime::now().c_str()
				, user.getUsername().c_str()
				, user.getPassword().c_str()
				, user.getEmail().c_str()
				, user.getFirstName().c_str()
				, user.getLastName().c_str());

		if(mDb->query(buffer))
			return false;

		return true;
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::update(DbUser& user) const
	{
		char buffer[1024];
		sprintf(buffer, "UPDATE users SET username='%s',password='%s',email='%s',first_name='%s',last_name='%s' WHERE id='%s';"
			, user.getUsername().c_str()
			, user.getPassword().c_str()
			, user.getEmail().c_str()
			, user.getFirstName().c_str()
			, user.getLastName().c_str()
			, Util::toString(user.getId()).c_str());

		if(mDb->query(buffer))
			return false;

		return true;
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::selectByUsername(DbUser& user, const std::string& username) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM users WHERE username='%s';", username.c_str());

		return select(user, buffer);
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::selectById(DbUser& user, int id) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM users WHERE id='%d';", id);

		return select(user, buffer);
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::isUsernameTaken(const std::string& username) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT COUNT(username) FROM users WHERE username='%s';"
				, username.c_str());

		if(mDb->query(buffer))
			return false;

		if(MYSQL_RES* result = mDb->getResult())
		{
			if(MYSQL_ROW row = mDb->getRow(result))
			{
				if(char* count = row[0])
				{
					if(strcmp(count, "0") != 0)
						return true;
				}
			}
		}

		return false;
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::select(DbUser& user, const char* command) const
	{
		if(mDb->query(command))
			return false;

		if(MYSQL_RES* result = mDb->getResult())
		{
			unsigned int numFields = mDb->getNumFields(result);
			if(MYSQL_ROW row = mDb->getRow(result))
			{
				if(char* id = row[0])
					user.setId(Util::s2i(id));
				if(char* date_created = row[1])
					user.setDateCreated(DateTime(date_created));
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
				if(char* last_login = row[7])
					user.setLastLogin(DateTime(last_login));
				if(char* expires = row[8])
					user.setExpires(DateTime(expires));
			}
		}
		else
			return false;

		return true;
	}
}
