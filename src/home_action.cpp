#include "home_action.h"
#include "home_script.h"

namespace Home
{
	// -------------------------------------------------------------------------
	Action::Action(Database* db, Script* script)
		: mDb(db)
		, mScript(script)
	{
	}

	// -------------------------------------------------------------------------
	void Action::onAction()
	{
		mScript->execute();
		// TODO: Execute script and log to database.
	}
}
