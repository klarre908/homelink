#ifndef __HOME_SCHEDULER_H__
#define __HOME_SCHEDULER_H__

#include <vector>

namespace Home
{
	class DateTime;
	class Schedule;

	class Scheduler
	{
	public:
		Scheduler();
		~Scheduler();

		void addSchedule(Schedule* schedule);
		void clearSchedules();

		void update();

	private:
		std::vector<Schedule*> mSchedules;
	};
}

#endif
