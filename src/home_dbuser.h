#ifndef __HOME_DBUSER_H__
#define __HOME_DBUSER_H__

#include <string>
#include "home_datetime.h"

namespace Home
{
	class DbUser
	{
	public:
		DbUser();
		DbUser(const DbUser& dbUser);

		inline void setId(int id);
		inline void setDateCreated(const DateTime& date);
		inline void setUsername(const std::string& username);
		inline void setPassword(const std::string& password);
		inline void setEmail(const std::string& email);
		inline void setFirstName(const std::string& firstName);
		inline void setLastName(const std::string& lastName);
		inline void setLastLogin(const DateTime& date);
		inline void setExpires(const DateTime& date);

		inline int getId() const;
		inline const DateTime& getDateCreated() const;
		inline const std::string& getUsername() const;
		inline const std::string& getPassword() const;
		inline const std::string& getEmail() const;
		inline const std::string& getFirstName() const;
		inline const std::string& getLastName() const;
		inline const DateTime& getLastLogin() const;
		inline const DateTime& getExpires() const;

	private:
		int mId;
		DateTime mDateCreated;
		std::string mUsername;
		std::string mPassword;
		std::string mEmail;
		std::string mFirstName;
		std::string mLastName;
		DateTime mLastLogin;
		DateTime mExpires;
	};

	// -------------------------------------------------------------------------
	inline void DbUser::setId(int id)
	{
		mId = id;
	}

	// -------------------------------------------------------------------------
	inline void DbUser::setDateCreated(const DateTime& date)
	{
		mDateCreated = date;
	}

	// -------------------------------------------------------------------------
	inline void DbUser::setUsername(const std::string& username)
	{
		mUsername = username;
	}

	// -------------------------------------------------------------------------
	inline void DbUser::setPassword(const std::string& password)
	{
		mPassword = password;
	}

	// -------------------------------------------------------------------------
	inline void DbUser::setEmail(const std::string& email)
	{
		mEmail = email;
	}

	// -------------------------------------------------------------------------
	inline void DbUser::setFirstName(const std::string& firstName)
	{
		mFirstName = firstName;
	}

	// -------------------------------------------------------------------------
	inline void DbUser::setLastName(const std::string& lastName)
	{
		mLastName = lastName;
	}

	// -------------------------------------------------------------------------
	inline void DbUser::setLastLogin(const DateTime& date)
	{
		mLastLogin = date;
	}

	// -------------------------------------------------------------------------
	inline void DbUser::setExpires(const DateTime& date)
	{
		mExpires = date;
	}

	// -------------------------------------------------------------------------
	inline int DbUser::getId() const
	{
		return mId;
	}

	// -------------------------------------------------------------------------
	inline const DateTime& DbUser::getDateCreated() const
	{
		return mDateCreated;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbUser::getUsername() const
	{
		return mUsername;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbUser::getPassword() const
	{
		return mPassword;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbUser::getEmail() const
	{
		return mEmail;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbUser::getFirstName() const
	{
		return mFirstName;
	}

	// -------------------------------------------------------------------------
	inline const std::string& DbUser::getLastName() const
	{
		return mLastName;
	}

	// -------------------------------------------------------------------------
	inline const DateTime& DbUser::getLastLogin() const
	{
		return mLastLogin;
	}

	// -------------------------------------------------------------------------
	inline const DateTime& DbUser::getExpires() const
	{
		return mExpires;
	}
}

#endif
