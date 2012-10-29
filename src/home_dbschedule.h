#ifndef __HOME_DBSCHEDULE_H__
#define __HOME_DBSCHEDULE_H__

#include <string>
#include "home_datetime.h"

namespace Home
{
	class DbAction;

	class DbSchedule
	{
	public:
		DbSchedule();
		DbSchedule(const DbSchedule& dbSchedule);
		~DbSchedule();

		inline void setId(int id);
		inline void setDateCreated(const DateTime& dateCreated);
		inline void setMinutes(const std::string& minutes);
		inline void setHours(const std::string& hours);
		inline void setDayOfMonth(const std::string& dayOfMonth);
		inline void setMonth(const std::string& month);
		inline void setDayOfWeek(const std::string& dayOfWeek);
		inline void setYear(const std::string& year);
		inline void setActive(bool active);
		inline void setAction(DbAction* action);

		inline int getId() const;
		inline const DateTime& getDateCreated() const;
		inline const std::string& getMinutes() const;
		inline const std::string& getHours() const;
		inline const std::string& getDayOfMonth() const;
		inline const std::string& getMonth() const;
		inline const std::string& getDayOfWeek() const;
		inline const std::string& getYear() const;
		inline bool isActive() const;
		inline DbAction* getAction() const;

	private:
		int mId;
		DateTime mDateCreated;
		std::string mMinutes;
		std::string mHours;
		std::string mDayOfMonth;
		std::string mMonth;
		std::string mDayOfWeek;
		std::string mYear;
		bool mActive;
		DbAction* mAction;
	};

	// -------------------------------------------------------------------------
	inline void DbSchedule::setId(int id)
	{
		mId = id;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setDateCreated(const DateTime& dateCreated)
	{
		mDateCreated = dateCreated;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setMinutes(const std::string& minutes)
	{
		mMinutes = minutes;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setHours(const std::string& hours)
	{
		mHours = hours;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setDayOfMonth(const std::string& dayOfMonth)
	{
		mDayOfMonth = dayOfMonth;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setMonth(const std::string& month)
	{
		mMonth = month;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setDayOfWeek(const std::string& dayOfWeek)
	{
		mDayOfWeek = dayOfWeek;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setYear(const std::string& year)
	{
		mYear = year;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setActive(bool active)
	{
		mActive = active;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setAction(DbAction* action)
	{
		mAction = action;
	}

	// -------------------------------------------------------------------------
	inline int DbSchedule::getId() const
	{
		return mId;
	}

	// -------------------------------------------------------------------------
	inline const DateTime& DbSchedule::getDateCreated() const
	{
		return mDateCreated;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbSchedule::getMinutes() const
	{
		return mMinutes;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbSchedule::getHours() const
	{
		return mHours;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbSchedule::getDayOfMonth() const
	{
		return mDayOfMonth;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbSchedule::getMonth() const
	{
		return mMonth;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbSchedule::getDayOfWeek() const
	{
		return mDayOfWeek;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbSchedule::getYear() const
	{
		return mYear;
	}

	// -------------------------------------------------------------------------
	inline bool DbSchedule::isActive() const
	{
		return mActive;
	}

	// -------------------------------------------------------------------------
	inline DbAction* DbSchedule::getAction() const
	{
		return mAction;
	}
}

#endif
