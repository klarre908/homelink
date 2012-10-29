#ifndef __HOME_DATETIME_H__
#define __HOME_DATETIME_H__

#include <string>

namespace Home
{
	// 2010-06-13 18:43:44
	class DateTime
	{
	public:
		DateTime();
		DateTime(const DateTime& dateTime);
		DateTime(int seconds
				, int minutes
				, int hours
				, int day
				, int month
				, int year);
		DateTime(const std::string& date);

		void set(int seconds
				, int minutes
				, int hours
				, int day
				, int month
				, int year);
		void set(const std::string& formatted);

		static std::string now();
		static std::string getFormatted(int seconds
				, int minutes
				, int hours
				, int day
				, int month
				, int year);
		std::string getFormatted() const;

		inline int getSeconds() const;
		inline int getMinutes() const;
		inline int getHours() const;
		inline int getDay() const;
		inline int getMonth() const;
		inline int getYear() const;

		bool isNull() const;

	private:
		int mSeconds;
		int mMinutes;
		int mHours;
		int mDay;
		int mMonth;
		int mYear;
	};

	// -------------------------------------------------------------------------
	inline int DateTime::getSeconds() const
	{
		return mSeconds;
	}

	// -------------------------------------------------------------------------
	inline int DateTime::getMinutes() const
	{
		return mMinutes;
	}

	// -------------------------------------------------------------------------
	inline int DateTime::getHours() const
	{
		return mHours;
	}

	// -------------------------------------------------------------------------
	inline int DateTime::getDay() const
	{
		return mDay;
	}

	// -------------------------------------------------------------------------
	inline int DateTime::getMonth() const
	{
		return mMonth;
	}

	// -------------------------------------------------------------------------
	inline int DateTime::getYear() const
	{
		return mYear;
	}
}

#endif
