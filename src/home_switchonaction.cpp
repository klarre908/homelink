#include "home_switchonaction.h"
#include "home_util.h"

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
		system(("tdtool --on " + Util::toString(mId)).c_str());
	}
}
