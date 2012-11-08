#ifndef __HOME_SCRIPT_H__
#define __HOME_SCRIPT_H__

#include <string>

namespace Home
{
	class Script
	{
	public:
		Script(const std::string& content);

		void execute();

	private:
		std::string mContent;
	};
}

#endif
