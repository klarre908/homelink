#include <cstdio>
#include "home_core.h"

int main()
{
	printf("Home\n");
	printf("----\n");

	Home::Core core;

#ifdef WIN32
	core.create("homelink.conf");
#else
	core.create("/etc/homelink.conf");
#endif

	core.run();

	printf("Shutting down...\n");
	printf("Bye!\n");

	return 0;
}
