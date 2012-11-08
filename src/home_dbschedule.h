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
		~DbSchedule();

		inline void setId(int id);
		inline void setDateCreated(const DateTime& dateCreated);
		inline void setName(const std::string& name);
		inline void setMinutes(const std::string& minutes);
		inline void setHours(const std::string& hours);
		inline void setMonths(const std::string& months);
		inline void setWeekDays(const std::string& days);
		inline void setYears(const std::string& years);
		inline void setActive(bool active);
		inline void setAction(DbAction* action);

		inline int getId() const;
		inline const DateTime& getDateCreated() const;
		inline const std::string& getName() const;
		inline const std::string& getMinutes() const;
		inline const std::string& getHours() const;
		inline const std::string& getMonths() const;
		inline const std::string& getWeekDays() const;
		inline const std::string& getYears() const;
		inline bool isActive() const;
		inline DbAction* getAction() const;

	private:
		DbSchedule(const DbSchedule& dbSchedule);

		int mId;
		DateTime mDateCreated;
		std::string mName;
		std::string mMinutes;
		std::string mHours;
		std::string mMonths;
		std::string mWeekDays;
		std::string mYears;
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
	inline void DbSchedule::setName(const std::string& name)
	{
		mName = name;
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
	inline void DbSchedule::setMonths(const std::string& months)
	{
		mMonths = months;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setWeekDays(const std::string& weekDays)
	{
		mWeekDays = weekDays;
	}

	// -------------------------------------------------------------------------
	inline void DbSchedule::setYears(const std::string& years)
	{
		mYears = years;
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
	inline const std::string& DbSchedule::getName() const
	{
		return mName;
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
	inline const std::string& DbSchedule::getMonths() const
	{
		return mMonths;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbSchedule::getWeekDays() const
	{
		return mWeekDays;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbSchedule::getYears() const
	{
		return mYears;
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
