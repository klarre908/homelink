#ifndef __HOME_DATABASEMANAGER_H__
#define __HOME_DATABASEMANAGER_H__

#include <string>
#include <vector>

#include "home_dbschedule.h"

namespace Home
{
	class DbAction;
	class DbDevice;
	class DbDeviceType;
	class DbSchedule;
	class DbUser;
	class Database;

	class DatabaseManager
	{
	public:
		DatabaseManager(Database* db);

		bool insert(const DbAction& action) const;
		bool insert(const DbUser& user) const;
		bool insert(const DbDeviceType& type) const;
		bool insert(const DbDevice& device) const;
		bool insert(const DbSchedule& schedule) const;

		bool update(DbUser& user) const;

		bool selectByName(DbAction& action, const std::string& name) const;
		bool selectById(DbAction& action, int id) const;

		bool selectByUsername(DbUser& user, const std::string& username) const;
		bool selectById(DbUser& user, int id) const;

		bool selectByName(DbDevice& device, const std::string& name) const;
		bool selectById(DbDevice& device, int id) const;

		bool selectByName(DbDeviceType& type, const std::string& name) const;
		bool selectById(DbDeviceType& type, int id) const;

		bool selectByName(DbSchedule& schedule, const std::string& name) const;
		bool selectById(DbSchedule& schedule, int id) const;
		bool selectAll(std::vector<DbSchedule>& schedules) const;

		bool isUsernameTaken(const std::string& username) const;

	private:
		bool select(DbAction& action, const char* command) const;
		bool select(DbUser& user, const char* command) const;
		bool select(DbDevice& device, const char* command) const;
		bool select(DbDeviceType& type, const char* command) const;
		bool select(DbSchedule& schedule, const char* command) const;
		bool select(std::vector<DbSchedule>& schedules, const char* command) const;

		Database* mDb;
	};
}

#endif
