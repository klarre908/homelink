#ifndef __HOME_SCHEDULE_H__
#define __HOME_SCHEDULE_H__

#include "home_constants.h"

namespace Home
{
	class Schedule
	{
	public:
		enum Day
		{
			DAY_NONE      = 0,
			DAY_MONDAY    = 1 << 0,
			DAY_TUESDAY   = 1 << 1,
			DAY_WEDNESDAY = 1 << 2,
			DAY_THURSDAY  = 1 << 3,
			DAY_FRIDAY    = 1 << 4,
			DAY_SATURDAY  = 1 << 5,
			DAY_SUNDAY    = 1 << 6,
			DAY_ALL       = ULONG_MAX,
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

		Schedule();

		bool isSatisfied(unsigned int minute
				, unsigned int hour
				, Day day
				, Month month) const;

		void setMinute(int minute);
		void setHour(int hour);
		void setDaysOfWeek(int days);
		void setMonths(int months);

		void addDayOfWeek(Day day);
		void addMonth(Month month);

		void removeDayOfWeek(Day day);
		void removeMonth(Month month);

	private:
		unsigned int mMinute; // 0-59
		unsigned int mHour; // 0-23
		unsigned int mDaysOfWeek;
		unsigned int mMonths;
	};
}

#endif
