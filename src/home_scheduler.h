#ifndef __HOME_SCHEDULER_H__
#define __HOME_SCHEDULER_H__

#include <vector>

namespace Home
{
	class ScheduleEvent;

	class Scheduler
	{
	public:
		Scheduler();
		~Scheduler();

		void addEvent(ScheduleEvent* event);
		bool removeEvent(int id);
		void clearEvents();

		void update();

	private:
		std::vector<ScheduleEvent*> mEvents;
	};
}

#endif
