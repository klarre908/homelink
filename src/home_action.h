#ifndef __HOME_ACTION_H__
#define __HOME_ACTION_H__

namespace Home
{
	class Database;

	class Action
	{
	public:
		virtual void onAction(Database* db) = 0;
	};
}

#endif
