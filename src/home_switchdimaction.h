#ifndef __HOME_SWITCHDIMACTION_H__
#define __HOME_SWITCHDIMACTION_H__

#include "home_action.h"

namespace Home
{
	class SwitchDimAction : public Action
	{
	public:
		SwitchDimAction(int id, unsigned char value);

		virtual void onAction(Database* db);

	private:
		int mId;
		unsigned char mValue;
	};
}

#endif
