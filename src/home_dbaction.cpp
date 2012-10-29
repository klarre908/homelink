#include "home_dbaction.h"

namespace Home
{
	// -------------------------------------------------------------------------
	DbAction::DbAction()
		: mId(0)
	{
	}

	// -------------------------------------------------------------------------
	DbAction::DbAction(const DbAction& dbAction)
	{
		mId = dbAction.mId;
		mDateCreated = dbAction.mDateCreated;
		mName = dbAction.mName;
		mContent = dbAction.mContent;
	}
}
