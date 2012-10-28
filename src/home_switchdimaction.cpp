#include "home_switchdimaction.h"
#include "home_util.h"

namespace Home
{
	// -------------------------------------------------------------------------
	SwitchDimAction::SwitchDimAction(int id, unsigned char value)
		: mId(id)
		, mValue(value)
	{
	}

	// -------------------------------------------------------------------------
	void SwitchDimAction::onAction(Database* db)
	{
		system(("tdtool -v " + Util::toString(mValue) + " -d " + Util::toString(mId)).c_str());
	}
}
