#include "home_schedule.h"

namespace Home
{
	// -------------------------------------------------------------------------
	Schedule::Schedule()
		: mMinute(ULONG_MAX)
		, mHour(ULONG_MAX)
		, mDaysOfWeek(static_cast<unsigned int>(DAY_ALL))
		, mMonths(static_cast<unsigned int>(MONTH_ALL))
	{
	}

	// -------------------------------------------------------------------------
	bool Schedule::isSatisfied(unsigned int minute
			, unsigned int hour
			, Day day
			, Month month) const
	{
		if(mMinute != ULONG_MAX && mMinute != minute)
			return false;

		if(mHour != ULONG_MAX && mHour != hour)
			return false;

		if((mDaysOfWeek & day) == 0)
			return false;

		if((mMonths & month) == 0)
			return false;

		return true;
	}

	// -------------------------------------------------------------------------
	void Schedule::setMinute(int minute)
	{
		mMinute = minute;
	}

	// -------------------------------------------------------------------------
	void Schedule::setHour(int hour)
	{
		mHour = hour;
	}

	// -------------------------------------------------------------------------
	void Schedule::setDaysOfWeek(int days)
	{
		mDaysOfWeek = days;
	}

	// -------------------------------------------------------------------------
	void Schedule::setMonths(int months)
	{
		mMonths = months;
	}

	// -------------------------------------------------------------------------
	void Schedule::addDayOfWeek(Day day)
	{
		mDaysOfWeek |= day;
	}

	// -------------------------------------------------------------------------
	void Schedule::addMonth(Month month)
	{
		mMonths |= month;
	}

	// -------------------------------------------------------------------------
	void Schedule::removeDayOfWeek(Day day)
	{
		mDaysOfWeek ^= day;
	}

	// -------------------------------------------------------------------------
	void Schedule::removeMonth(Month month)
	{
		mMonths ^= month;
	}
}
