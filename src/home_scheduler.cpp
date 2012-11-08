#include "home_scheduler.h"
#include "home_schedule.h"
#include "home_datetime.h"

namespace Home
{
	// -------------------------------------------------------------------------
	Scheduler::Scheduler()
	{
	}

	// -------------------------------------------------------------------------
	Scheduler::~Scheduler()
	{
		clearSchedules();
	}

	// -------------------------------------------------------------------------
	void Scheduler::addSchedule(Schedule* event)
	{
		mSchedules.push_back(event);
	}

	// -------------------------------------------------------------------------
	void Scheduler::clearSchedules()
	{
		for(std::vector<Schedule*>::iterator i = mSchedules.begin()
				; i != mSchedules.end(); ++i)
		{
			delete *i;
		}

		mSchedules.clear();
	}

	// -------------------------------------------------------------------------
	void Scheduler::update()
	{
		std::vector<Schedule*> toRun;
		DateTime date = DateTime(DateTime::now());

		for(std::vector<Schedule*>::iterator i = mSchedules.begin()
				; i != mSchedules.end(); ++i)
		{
			if((*i)->update(date))
				toRun.push_back(*i);
		}

		for(std::vector<Schedule*>::iterator i = toRun.begin()
				; i != toRun.end(); ++i)
		{
			(*i)->run();
		}
	}
}
