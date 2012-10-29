#include "home_dbdevicetype.h"

namespace Home
{
	// -------------------------------------------------------------------------
	DbDeviceType::DbDeviceType()
		: mId(0)
	{
	}

	// -------------------------------------------------------------------------
	DbDeviceType::DbDeviceType(const DbDeviceType& dbDeviceType)
	{
		mId = dbDeviceType.mId;
		mDateCreated = dbDeviceType.mDateCreated;
		mName = dbDeviceType.mName;
		mDescription = dbDeviceType.mDescription;
	}
}
