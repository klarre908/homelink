#ifndef __HOME_CORE_H__
#define __HOME_CORE_H__

namespace Home
{
	class Database;
	class DatabaseManager;
	class ConfigReader;

	class Core
	{
	public:
		Core();
		~Core();

		void create(const char* filename);

		void run();

	private:
		Database* mDb;
		DatabaseManager* mDbManager;
		ConfigReader* mConfigReader;
	};
}

#endif
