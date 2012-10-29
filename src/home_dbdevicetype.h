#ifndef __HOME_DBDEVICETYPE_H__
#define __HOME_DBDEVICETYPE_H__

#include <string>
#include "home_datetime.h"

namespace Home
{
	class DbDeviceType
	{
	public:
		DbDeviceType();
		DbDeviceType(const DbDeviceType& dbDeviceType);

		inline void setId(int id);
		inline void setDateCreated(const DateTime& date);
		inline void setName(const std::string& name);
		inline void setDescription(const std::string& description);

		inline int getId() const;
		inline const DateTime& getDateCreated() const;
		inline const std::string& getName() const;
		inline const std::string& getDescription() const;

	private:
		int mId;
		DateTime mDateCreated;
		std::string mName;
		std::string mDescription;
	};

	// -------------------------------------------------------------------------
	inline void DbDeviceType::setId(int id)
	{
		mId = id;
	}

	// -------------------------------------------------------------------------
	inline void DbDeviceType::setDateCreated(const DateTime& date)
	{
		mDateCreated = date;
	}

	// -------------------------------------------------------------------------
	inline void DbDeviceType::setName(const std::string& name)
	{
		mName = name;
	}

	// -------------------------------------------------------------------------
	inline void DbDeviceType::setDescription(const std::string& description)
	{
		mDescription = description;
	}

	// -------------------------------------------------------------------------
	inline int DbDeviceType::getId() const
	{
		return mId;
	}

	// -------------------------------------------------------------------------
	inline const DateTime& DbDeviceType::getDateCreated() const
	{
		return mDateCreated;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbDeviceType::getName() const
	{
		return mName;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbDeviceType::getDescription() const
	{
		return mDescription;
	}
}

#endif
