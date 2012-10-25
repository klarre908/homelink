#include <iostream>
#include <string.h>
#include <cstdio>
#include "home_socket.h"
#include "home_messagedispatcher.h"
#include "home_database.h"
#include "home_configreader.h"

int main()
{
	printf("Home\n");
	printf("----\n");

	Home::ConfigReader configs("/etc/homelink.conf");

	Home::Database db = Home::Database(configs.get("db_host").c_str()
			, configs.geti("db_port")
			, configs.get("db_user").c_str()
			, configs.get("db_passwd").c_str()
			, configs.get("db_database").c_str());

	Home::MessageDispatcher* dispatcher = new Home::MessageDispatcher(&db);
	Home::Socket socket(4111, dispatcher);

	while(true)
	{
		if(!socket.listen(2000))
		{
		}
	}

	printf("Shutting down...\n");

	delete dispatcher;

	printf("Bye!\n");

	return 0;
}
