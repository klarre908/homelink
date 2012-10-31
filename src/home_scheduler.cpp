#include "home_scheduler.h"

namespace Home
{
	// -------------------------------------------------------------------------
	Scheduler::Scheduler()
	{
	}

	// -------------------------------------------------------------------------
	Scheduler::~Scheduler()
	{
		clearEvents();
	}

	// -------------------------------------------------------------------------
	void Scheduler::addEvent(ScheduleEvent* event)
	{
		mEvents.push_back(event);
	}

	// -------------------------------------------------------------------------
	bool Scheduler::removeEvent(int id)
	{
		for(std::vector<ScheduleEvent*>::iterator i = mEvents.begin()
				; i != mEvents.end(); ++i)
		{
/*			if((*i)->getId() == id)
			{
				delete *i;
				mEvents.erase(i);

				return true;
			}*/
		}

		return false;
	}

	// -------------------------------------------------------------------------
	void Scheduler::clearEvents()
	{
		for(std::vector<ScheduleEvent*>::iterator i = mEvents.begin()
				; i != mEvents.end(); ++i)
		{
			delete *i;
		}

		mEvents.clear();
	}

	// -------------------------------------------------------------------------
	void Scheduler::update()
	{
		for(std::vector<ScheduleEvent*>::iterator i = mEvents.begin()
				; i != mEvents.end(); ++i)
		{
			// TODO: Evaluate and execute events here.
		}
	}
}
