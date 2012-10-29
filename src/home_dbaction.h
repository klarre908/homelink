#ifndef __HOME_DBACTION_H__
#define __HOME_DBACTION_H__

#include <string>
#include "home_datetime.h"

namespace Home
{
	class DbAction
	{
	public:
		inline void setId(int id);
		inline void setDateCreated(const DateTime& date);
		inline void setName(const std::string& name);
		inline void setContent(const std::string& content);

		inline int getId() const;
		inline const DateTime& getDateCreated() const;
		inline const std::string& getName() const;
		inline const std::string& getContent() const;

	private:
		int mId;
		DateTime mDateCreated;
		std::string mName;
		std::string mContent;
	};

	// -------------------------------------------------------------------------
	inline void DbAction::setId(int id)
	{
		mId = id;
	}

	// -------------------------------------------------------------------------
	inline void DbAction::setDateCreated(const DateTime& date)
	{
		mDateCreated = date;
	}

	// -------------------------------------------------------------------------
	inline void DbAction::setName(const std::string& name)
	{
		mName = name;
	}

	// -------------------------------------------------------------------------
	inline void DbAction::setContent(const std::string& content)
	{
		mContent = content;
	}

	// -------------------------------------------------------------------------
	inline int DbAction::getId() const
	{
		return mId;
	}

	// -------------------------------------------------------------------------
	inline const DateTime& DbAction::getDateCreated() const
	{
		return mDateCreated;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbAction::getName() const
	{
		return mName;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbAction::getContent() const
	{
		return mContent;
	}
}

#endif
