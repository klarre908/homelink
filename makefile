homelink:
	g++ \
		src/home_configreader.cpp \
		src/home_database.cpp \
		src/home_message.cpp \
		src/home_messagedispatcher.cpp \
		src/home_socket.cpp \
		src/home_switchdimaction.cpp \
		src/home_switchoffaction.cpp \
		src/home_switchonaction.cpp \
		src/main.cpp \
		-o homelink \
		-I./src \
		-I./3rdparty/netLink/include \
		-I./3rdparty/rapidxml-1.13
