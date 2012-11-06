#ifndef __HOME_DBDEVICE_H__
#define __HOME_DBDEVICE_H__

#include <string>
#include "home_datetime.h"

namespace Home
{
	class DbDeviceType;

	class DbDevice
	{
	public:
		DbDevice();
		DbDevice(const DbDevice& dbDevice);
		~DbDevice();

		inline void setId(int id);
		inline void setDateCreated(const DateTime& date);
		inline void setName(const std::string& name);
		inline void setDbDeviceType(DbDeviceType* dbDeviceType);

		inline int getId() const;
		inline const DateTime& getDateCreated() const;
		inline const std::string& getName() const;
		inline const DbDeviceType& getDbDeviceType() const;

	private:
		int mId;
		DateTime mDateCreated;
		std::string mName;
		DbDeviceType* mDbDeviceType;
	};

	// -------------------------------------------------------------------------
	inline void DbDevice::setId(int id)
	{
		mId = id;
	}

	// -------------------------------------------------------------------------
	inline void DbDevice::setDateCreated(const DateTime& date)
	{
		mDateCreated = date;
	}

	// -------------------------------------------------------------------------
	inline void DbDevice::setName(const std::string& name)
	{
		mName = name;
	}

	// -------------------------------------------------------------------------
	inline void DbDevice::setDbDeviceType(DbDeviceType* dbDeviceType)
	{
		mDbDeviceType = dbDeviceType;
	}

	// -------------------------------------------------------------------------
	inline int DbDevice::getId() const
	{
		return mId;
	}

	// -------------------------------------------------------------------------
	inline const DateTime& DbDevice::getDateCreated() const
	{
		return mDateCreated;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbDevice::getName() const
	{
		return mName;
	}

	// -------------------------------------------------------------------------
	inline const DbDeviceType& DbDevice::getDbDeviceType() const
	{
		return *mDbDeviceType;
	}
}

#endif
