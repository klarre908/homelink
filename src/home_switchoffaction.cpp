#include "home_switchoffaction.h"
#include "home_util.h"

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
		system(("tdtool --off " + Util::toString(mId)).c_str());
	}
}
