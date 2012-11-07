#include "home_databasemanager.h"
#include "home_database.h"
#include "home_dbaction.h"
#include "home_dbdevice.h"
#include "home_dbdevicetype.h"
#include "home_dbschedule.h"
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
	bool DatabaseManager::insert(const DbAction& action) const
	{
		char buffer[1024];
		sprintf(buffer, "INSERT INTO actions (date_created,name,content) VALUES ('%s','%s','%s');"
				, DateTime::now().c_str()
				, action.getName().c_str()
				, action.getContent().c_str());

		if(mDb->query(buffer))
			return false;

		return true;
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::insert(const DbUser& user) const
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
	bool DatabaseManager::insert(const DbDeviceType& type) const
	{
		char buffer[1024];
		sprintf(buffer, "INSERT INTO device_types (date_created,name,description) VALUES ('%s','%s','%s');"
				, DateTime::now().c_str()
				, type.getName().c_str()
				, type.getDescription().c_str());

		if(mDb->query(buffer))
			return false;

		return true;
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::insert(const DbDevice& device) const
	{
		char buffer[1024];
		sprintf(buffer, "INSERT INTO devices (date_created,name,device_type_id) VALUES ('%s','%s','%d');"
				, DateTime::now().c_str()
				, device.getName().c_str()
				, device.getDbDeviceType().getId());

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
	bool DatabaseManager::selectByName(DbAction& action, const std::string& name) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM actions WHERE name='%s';", name.c_str());

		return select(action, buffer);
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::selectById(DbAction& action, int id) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM actions WHERE id='%d';", id);

		return select(action, buffer);
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
	bool DatabaseManager::selectByName(DbDevice& device, const std::string& name) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM devices WHERE name='%s';", name.c_str());

		return select(device, buffer);
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::selectById(DbDevice& device, int id) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM devices WHERE id='%d';", id);

		return select(device, buffer);
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::selectByName(DbDeviceType& type, const std::string& name) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM device_types WHERE name='%s';", name.c_str());

		return select(type, buffer);
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::selectById(DbDeviceType& type, int id) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM device_types WHERE id='%d';", id);

		return select(type, buffer);
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::selectByName(DbSchedule& schedule, const std::string& name) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM schedules WHERE name='%s';", name.c_str());

		return select(schedule, buffer);
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::selectById(DbSchedule& schedule, int id) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM schedules WHERE id='%d';", id);

		return select(schedule, buffer);
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::selectAll(std::vector<DbSchedule>& schedules) const
	{
		char buffer[1024];
		sprintf(buffer, "SELECT * FROM schedules;");

		return select(schedules, buffer);
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
	bool DatabaseManager::select(DbAction& action, const char* command) const
	{
		if(mDb->query(command))
			return false;

		if(MYSQL_RES* result = mDb->getResult())
		{
			if(MYSQL_ROW row = mDb->getRow(result))
			{
				if(char* id = row[0])
					action.setId(Util::s2i(id));
				if(char* date_created = row[1])
					action.setDateCreated(DateTime(date_created));
				if(char* name = row[2])
					action.setName(name);
				if(char* content = row[3])
					action.setContent(content);
			}
		}
		else
			return false;

		return true;
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::select(DbUser& user, const char* command) const
	{
		if(mDb->query(command))
			return false;

		if(MYSQL_RES* result = mDb->getResult())
		{
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

	// -------------------------------------------------------------------------
	bool DatabaseManager::select(DbDevice& device, const char* command) const
	{
		if(mDb->query(command))
			return false;

		if(MYSQL_RES* result = mDb->getResult())
		{
			if(MYSQL_ROW row = mDb->getRow(result))
			{
				if(char* id = row[0])
					device.setId(Util::s2i(id));
				if(char* date_created = row[1])
					device.setDateCreated(DateTime(date_created));
				if(char* name = row[2])
					device.setName(name);
				if(char* device_type_id = row[3])
				{
					DbDeviceType* type = new DbDeviceType();
					if(selectById(*type, Util::s2i(device_type_id)))
						device.setDbDeviceType(type);
					else
						delete type;
				}
			}
		}

		return true;
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::select(DbDeviceType& type, const char* command) const
	{
		if(mDb->query(command))
			return false;

		if(MYSQL_RES* result = mDb->getResult())
		{
			if(MYSQL_ROW row = mDb->getRow(result))
			{
				if(char* id = row[0])
					type.setId(Util::s2i(id));
				if(char* date_created = row[1])
					type.setDateCreated(DateTime(date_created));
				if(char* name = row[2])
					type.setName(name);
				if(char* description = row[3])
					type.setDescription(description);
			}
		}
		else
			return false;

		return true;
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::select(DbSchedule& schedule, const char* command) const
	{
		if(mDb->query(command))
			return false;

		if(MYSQL_RES* result = mDb->getResult())
		{
			if(MYSQL_ROW row = mDb->getRow(result))
			{
				if(char* id = row[0])
					schedule.setId(Util::s2i(id));
				if(char* date_created = row[1])
					schedule.setDateCreated(DateTime(date_created));
				if(char* name = row[2])
					schedule.setName(name);
				if(char* minutes = row[3])
					schedule.setMinutes(minutes);
				if(char* hours = row[4])
					schedule.setHours(hours);
				if(char* day_of_week = row[5])
					schedule.setDayOfWeek(day_of_week);
				if(char* month = row[6])
					schedule.setMonth(month);
				if(char* year = row[7])
					schedule.setYear(year);
				if(char* active = row[8])
					schedule.setActive(Util::s2b(active));
				if(char* action_id = row[9])
				{
					DbAction* action = new DbAction();
					if(selectById(*action, Util::s2i(action_id)))
						schedule.setAction(action);
					else
						delete action;
				}
			}
		}
		else
			return false;

		return true;
	}

	// -------------------------------------------------------------------------
	bool DatabaseManager::select(std::vector<DbSchedule>& schedules, const char* command) const
	{
		if(mDb->query(command))
			return false;

		if(MYSQL_RES* result = mDb->getResult())
		{
			while(MYSQL_ROW row = mDb->getRow(result))
			{
				schedules.push_back(DbSchedule());
				DbSchedule& schedule = schedules.back();
				if(char* id = row[0])
					schedule.setId(Util::s2i(id));
				if(char* date_created = row[1])
					schedule.setDateCreated(DateTime(date_created));
				if(char* name = row[2])
					schedule.setName(name);
				if(char* minutes = row[3])
					schedule.setMinutes(minutes);
				if(char* hours = row[4])
					schedule.setHours(hours);
				if(char* day_of_week = row[5])
					schedule.setDayOfWeek(day_of_week);
				if(char* month = row[6])
					schedule.setMonth(month);
				if(char* year = row[7])
					schedule.setYear(year);
				if(char* active = row[8])
					schedule.setActive(Util::s2b(active));
				if(char* action_id = row[9])
				{
					DbAction* action = new DbAction();
					if(selectById(*action, Util::s2i(action_id)))
						schedule.setAction(action);
					else
						delete action;
				}
			}
		}
		else
			return false;

		return true;
	}
}
