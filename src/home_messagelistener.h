#ifndef __HOME_MESSAGELISTENER_H__
#define __HOME_MESSAGELISTENER_H__

#include <string>

namespace Home
{
	class MessageListener
	{
	public:
		virtual void onMessage(const char* message, const std::string& fromIp) = 0;
	};
}

#endif
