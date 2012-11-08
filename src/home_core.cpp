#include "home_core.h"
#include "home_configreader.h"
#include "home_database.h"
#include "home_databasemanager.h"
#include "home_dbschedule.h"
#include "home_script.h"
#include "home_messagedispatcher.h"
#include "home_dbaction.h"
#include "home_socket.h"
#include "home_scheduler.h"
#include "home_schedule.h"
#include "home_util.h"
#include "home_action.h"

namespace Home
{
	// -------------------------------------------------------------------------
	Core::Core()
		: mDb(0)
		, mDbManager(0)
		, mConfigReader(0)
		, mScheduler(0)
	{
	}

	// -------------------------------------------------------------------------
	Core::~Core()
	{
		delete mScheduler;
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

		if(!mScheduler)
			mScheduler = new Scheduler();

		updateScheduler();
	}

	// -------------------------------------------------------------------------
	void Core::run()
	{
		MessageDispatcher dispatcher(mDb);
		Socket socket(4111, &dispatcher);

		unsigned long long timer = DateTime::getSecsSinceEpoch();
		bool isDone = false;
		while(!isDone)
		{
			if(!socket.listen(2000))
			{
			}

			unsigned long long time = DateTime::getSecsSinceEpoch();
			while((time - timer) > 60)
			{
				timer += 60;
				updateScheduler();
				mScheduler->update();
				printf("Updating schedules\n");
			}
		}
	}

	// -------------------------------------------------------------------------
	void Core::updateScheduler()
	{
		std::vector<DbSchedule*> schedules;
		mDbManager->selectAll(schedules);
		mScheduler->clearSchedules();

		for(std::vector<DbSchedule*>::iterator i = schedules.begin()
				; i != schedules.end(); ++i)
		{
			DbAction* dbAction = (*i)->getAction();
			Action* action = new Action(mDb, new Script(dbAction->getContent()));
			Schedule* schedule = new Schedule(action);
			if((*i)->getMinutes() != "*")
				schedule->setMinute(Util::s2i((*i)->getMinutes()));
			if((*i)->getHours() != "*")
				schedule->setHour(Util::s2i((*i)->getHours()));
			if((*i)->getWeekDays() != "*")
				schedule->setWeekDays(Util::s2i((*i)->getWeekDays()));
			if((*i)->getMonths() != "*")
				schedule->setMonths(Util::s2i((*i)->getMonths()));

			mScheduler->addSchedule(schedule);

			delete *i;
		}

		schedules.clear();
	}
}
