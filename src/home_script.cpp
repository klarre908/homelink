#include "home_script.h"
#include <cstdio>

namespace Home
{
	// -------------------------------------------------------------------------
	Script::Script(const std::string& content)
		: mContent(content)
	{
	}

	// -------------------------------------------------------------------------
	void Script::execute()
	{
		// TODO: Execute script.
		printf("Script: '%s'\n", mContent.c_str());
	}
}
