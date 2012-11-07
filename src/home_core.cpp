#include "home_core.h"
#include "home_configreader.h"
#include "home_database.h"
#include "home_databasemanager.h"
#include "home_messagedispatcher.h"
#include "home_socket.h"

namespace Home
{
	// -------------------------------------------------------------------------
	Core::Core()
		: mDb(0)
		, mDbManager(0)
		, mConfigReader(0)
	{
	}

	// -------------------------------------------------------------------------
	Core::~Core()
	{
		delete mDbManager;
		delete mDb;
		delete mConfigReader;
	}

	// -------------------------------------------------------------------------
	void Core::create(const char* filename)
	{
		if(!mConfigReader)
			mConfigReader = new ConfigReader(filename);

		if(!mDb)
		{
			mDb = new Database(mConfigReader->get("db_host").c_str()
						, mConfigReader->geti("db_port")
						, mConfigReader->get("db_user").c_str()
						, mConfigReader->get("db_passwd").c_str()
						, mConfigReader->get("db_database").c_str());
		}

		if(!mDbManager)
			mDbManager = new DatabaseManager(mDb);
	}

	// -------------------------------------------------------------------------
	void Core::run()
	{
		MessageDispatcher dispatcher(mDb);
		Socket socket(4111, &dispatcher);

		bool isDone = false;
		while(!isDone)
		{
			if(!socket.listen(2000))
			{
			}
		}
	}
}
