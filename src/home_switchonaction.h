#ifndef __HOME_SWITCHONACTION_H__
#define __HOME_SWITCHONACTION_H__

#include "home_action.h"

namespace Home
{
	class SwitchOnAction : public Action
	{
	public:
		SwitchOnAction(int id);

		virtual void onAction(Database* db);

	private:
		int mId;
	};
}

#endif
