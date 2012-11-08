#ifndef __HOME_SCHEDULE_H__
#define __HOME_SCHEDULE_H__

#include "home_constants.h"

namespace Home
{
	class Action;
	class DateTime;

	class Schedule
	{
	public:
		enum WeekDay
		{
			WEEKDAY_NONE      = 0,
			WEEKDAY_MONDAY    = 1 << 0,
			WEEKDAY_TUESDAY   = 1 << 1,
			WEEKDAY_WEDNESDAY = 1 << 2,
			WEEKDAY_THURSDAY  = 1 << 3,
			WEEKDAY_FRIDAY    = 1 << 4,
			WEEKDAY_SATURDAY  = 1 << 5,
			WEEKDAY_SUNDAY    = 1 << 6,
			WEEKDAY_ALL       = ULONG_MAX,
		};

		enum Month
		{
			MONTH_NONE      = 0,
			MONTH_JANUARY   = 1 << 0,
			MONTH_FEBRUARY  = 1 << 1,
			MONTH_MARCH     = 1 << 2,
			MONTH_APRIL     = 1 << 3,
			MONTH_MAY       = 1 << 4,
			MONTH_JUNE      = 1 << 5,
			MONTH_JULY      = 1 << 6,
			MONTH_AUGUST    = 1 << 7,
			MONTH_SEPTEMBER = 1 << 8,
			MONTH_OCTOBER   = 1 << 9,
			MONTH_NOVEMBER  = 1 << 10,
			MONTH_DECEMBER  = 1 << 11,
			MONTH_ALL       = ULONG_MAX,
		};

		Schedule(Action* action);

		bool update(const DateTime& date);

		void setMinute(int minute);
		void setHour(int hour);
		void setWeekDays(int weekDays);
		void setMonths(int months);

		void addWeekDay(WeekDay weekDay);
		void addMonth(Month month);

		void removeWeekDay(WeekDay weekDay);
		void removeMonth(Month month);

		void run();

	private:
		unsigned int mMinute; // 0-59
		unsigned int mHour; // 0-23
		unsigned int mWeekDays;
		unsigned int mMonths;

		Action* mAction;
	};
}

#endif
