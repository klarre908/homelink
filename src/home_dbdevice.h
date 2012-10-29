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
		inline DbDeviceType* getDbDeviceType() const;

	private:
		int mId;
		DateTime mDateCreated;
		std::string mName;
		DbDeviceType* mDbDeviceType;
	};
}

#endif
