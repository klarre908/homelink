#ifndef __HOME_ACTION_H__
#define __HOME_ACTION_H__

namespace Home
{
	class Database;
	class Script;

	class Action
	{
	public:
		Action(Database* db, Script* script);

		void onAction();

	private:
		Database* mDb;
		Script* mScript;
	};
}

#endif
