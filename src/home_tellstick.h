#ifndef __HOME_TELLSTICK_H__
#define __HOME_TELLSTICK_H__

namespace Home
{
	class Tellstick
	{
	public:
		Tellstick();

		void onActionOn(int id);
		void onActionOff(int id);
		void onActionDim(int id, unsigned char value);
	};
}

#endif
