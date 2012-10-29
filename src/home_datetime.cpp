#include "home_datetime.h"
#include "home_util.h"
#include <ctime>
#include <cassert>

namespace Home
{
	// -------------------------------------------------------------------------
	DateTime::DateTime()
		: mSeconds(0)
		, mMinutes(0)
		, mHours(0)
		, mDay(0)
		, mMonth(0)
		, mYear(0)
	{
	}

	// -------------------------------------------------------------------------
	DateTime::DateTime(const DateTime& dateTime)
	{
		mSeconds = dateTime.mSeconds;
		mMinutes = dateTime.mMinutes;
		mHours   = dateTime.mHours;
		mDay     = dateTime.mDay;
		mMonth   = dateTime.mMonth;
		mYear    = dateTime.mYear;
	}

	// -------------------------------------------------------------------------
	DateTime::DateTime(int seconds
			, int minutes
			, int hours
			, int day
			, int month
			, int year)
	{
		set(seconds, minutes, hours, day, month, year);
	}

	// -------------------------------------------------------------------------
	DateTime::DateTime(const std::string& date)
	{
		set(date);
	}

	// -------------------------------------------------------------------------
	void DateTime::set(int seconds
			, int minutes
			, int hours
			, int day
			, int month
			, int year)
	{
		mSeconds = seconds;
		mMinutes = minutes;
		mHours   = hours;
		mDay     = day;
		mMonth   = month;
		mYear    = year;
	}

	// -------------------------------------------------------------------------
	void DateTime::set(const std::string& formatted)
	{
		assert(formatted.length() == 19);

		mYear    = Util::s2i(formatted.substr( 0, 4));
		mMonth   = Util::s2i(formatted.substr( 5, 2));
		mDay     = Util::s2i(formatted.substr( 8, 2));
		mHours   = Util::s2i(formatted.substr(11, 2));
		mMinutes = Util::s2i(formatted.substr(14, 2));
		mSeconds = Util::s2i(formatted.substr(17, 2));
	}

	// -------------------------------------------------------------------------
	std::string DateTime::now()
	{
		time_t t = time(0);
		struct tm* now = localtime(&t);

		int seconds = now->tm_sec;
		int minutes = now->tm_min;
		int hours   = now->tm_hour;
		int day     = now->tm_mday;
		int month   = now->tm_mon + 1;
		int year    = now->tm_year + 1900;

		return getFormatted(seconds, minutes, hours, day, month, year);
	}

	// -------------------------------------------------------------------------
	std::string DateTime::getFormatted(int seconds
			, int minutes
			, int hours
			, int day
			, int month
			, int year)
	{
		std::string str;

		str.reserve(19);
		str += Util::toString(year) + "-";
		str += (month   < 10 ? ("0" + Util::toString(month))   : Util::toString(month)) + "-";
		str += (day     < 10 ? ("0" + Util::toString(day))     : Util::toString(day)) + " ";
		str += (hours   < 10 ? ("0" + Util::toString(hours))   : Util::toString(hours)) + ":";
		str += (minutes < 10 ? ("0" + Util::toString(minutes)) : Util::toString(minutes)) + ":";
		str += (seconds < 10 ? ("0" + Util::toString(seconds)) : Util::toString(seconds));

		return str;
	}

	// -------------------------------------------------------------------------
	std::string DateTime::getFormatted() const
	{
		return getFormatted(getSeconds()
				, getMinutes()
				, getHours()
				, getDay()
				, getMonth()
				, getYear());
	}

	// -------------------------------------------------------------------------
	bool DateTime::isNull() const
	{
		return mSeconds == mMinutes == mHours == mDay == mMonth == mYear == 0;
	}
}
