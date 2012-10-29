#include "home_dbschedule.h"
#include "home_dbaction.h"

namespace Home
{
	// -------------------------------------------------------------------------
	DbSchedule::DbSchedule()
		: mId(0)
		, mActive(true)
		, mAction(0)
	{
	}

	// -------------------------------------------------------------------------
	DbSchedule::DbSchedule(const DbSchedule& dbSchedule)
	{
		mId = dbSchedule.mId;
		mDateCreated = dbSchedule.mDateCreated;
		mMinutes = dbSchedule.mMinutes;
		mHours = dbSchedule.mHours;
		mDayOfMonth = dbSchedule.mDayOfMonth;
		mMonth = dbSchedule.mMonth;
		mDayOfWeek = dbSchedule.mDayOfWeek;
		mYear = dbSchedule.mYear;
		mActive = dbSchedule.mActive;
		mAction = dbSchedule.mAction;
	}

	// -------------------------------------------------------------------------
	DbSchedule::~DbSchedule()
	{
		delete mAction;
	}
}
