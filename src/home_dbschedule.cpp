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
	}

	// -------------------------------------------------------------------------
	DbSchedule::~DbSchedule()
	{
		delete mAction;
	}
}
