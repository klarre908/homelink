#include "home_switchonaction.h"

namespace Home
{
	// -------------------------------------------------------------------------
	SwitchOnAction::SwitchOnAction(int id)
		: mId(id)
	{
	}

	// -------------------------------------------------------------------------
	void SwitchOnAction::onAction(Database* db)
	{
		//system("tdtool --on id");
	}
}
