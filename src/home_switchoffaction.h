#ifndef __HOME_SWITCHOFFACTION_H__
#define __HOME_SWITCHOFFACTION_H__

#include "home_action.h"

namespace Home
{
	class SwitchOffAction : public Action
	{
	public:
		SwitchOffAction(int id);

		virtual void onAction(Database* db);

	private:
		int mId;
	};
}

#endif
