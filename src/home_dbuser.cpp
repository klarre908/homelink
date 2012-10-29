#include "home_dbuser.h"

namespace Home
{
	// -------------------------------------------------------------------------
	DbUser::DbUser()
		: mId(0)
	{
	}

	// -------------------------------------------------------------------------
	DbUser::DbUser(const DbUser& dbUser)
	{
		mId = dbUser.mId;
		mDateCreated = dbUser.mDateCreated;
		mUsername = dbUser.mUsername;
		mPassword = dbUser.mPassword;
		mEmail = dbUser.mEmail;
		mFirstName = dbUser.mFirstName;
		mLastName = dbUser.mLastName;
		mLastLogin = dbUser.mLastLogin;
		mExpires = dbUser.mExpires;
	}
}
