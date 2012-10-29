#include "home_dbdevice.h"
#include "home_dbdevicetype.h"

namespace Home
{
	// -------------------------------------------------------------------------
	DbDevice::DbDevice()
		: mId(0)
		, mDbDeviceType(0)
	{
	}

	// -------------------------------------------------------------------------
	DbDevice::DbDevice(const DbDevice& dbDevice)
	{
		mId = dbDevice.mId;
		mDateCreated = dbDevice.mDateCreated;
		mName = dbDevice.mName;
		mDbDeviceType = dbDevice.mDbDeviceType;
	}

	// -------------------------------------------------------------------------
	DbDevice::~DbDevice()
	{
		delete mDbDeviceType;
	}
}
