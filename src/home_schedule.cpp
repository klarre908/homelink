#include "home_schedule.h"
#include "home_action.h"
#include "home_datetime.h"

namespace Home
{
	// -------------------------------------------------------------------------
	Schedule::Schedule(Action* action)
		: mMinute(ULONG_MAX)
		, mHour(ULONG_MAX)
		, mWeekDays(static_cast<unsigned int>(WEEKDAY_ALL))
		, mMonths(static_cast<unsigned int>(MONTH_ALL))
		, mAction(action)
	{
	}

	// -------------------------------------------------------------------------
	bool Schedule::update(const DateTime& date)
	{
		unsigned int minute = (unsigned int)date.getMinutes();
		unsigned int hour = (unsigned int)date.getHours();
		unsigned int weekDay = (unsigned int)(1 << (date.getWeekDay() - 1));
		unsigned int month = (unsigned int)(1 << (date.getMonth() - 1));

		if(mMinute != ULONG_MAX && mMinute != minute)
			return false;

		if(mHour != ULONG_MAX && mHour != hour)
			return false;

		if((mWeekDays & weekDay) == 0)
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
	void Schedule::setWeekDays(int weekDays)
	{
		mWeekDays = weekDays;
	}

	// -------------------------------------------------------------------------
	void Schedule::setMonths(int months)
	{
		mMonths = months;
	}

	// -------------------------------------------------------------------------
	void Schedule::addWeekDay(WeekDay weekDay)
	{
		mWeekDays |= weekDay;
	}

	// -------------------------------------------------------------------------
	void Schedule::addMonth(Month month)
	{
		mMonths |= month;
	}

	// -------------------------------------------------------------------------
	void Schedule::removeWeekDay(WeekDay weekDay)
	{
		mWeekDays ^= weekDay;
	}

	// -------------------------------------------------------------------------
	void Schedule::removeMonth(Month month)
	{
		mMonths ^= month;
	}

	// -------------------------------------------------------------------------
	void Schedule::run()
	{
		mAction->onAction();
	}
}
