#include "home_switchdimaction.h"

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
		//system("tdtool --dim value id");
	}
}
