#include "home_switchoffaction.h"

namespace Home
{
	// -------------------------------------------------------------------------
	SwitchOffAction::SwitchOffAction(int id)
		: mId(id)
	{
	}

	// -------------------------------------------------------------------------
	void SwitchOffAction::onAction(Database* db)
	{
		//system("tdtool --on id");
	}
}
