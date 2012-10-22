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
		3rdparty/netLink/src/core.cc \
		3rdparty/netLink/src/smart_buffer.cc \
		3rdparty/netLink/src/socket.cc \
		3rdparty/netLink/src/socket_group.cc \
		3rdparty/netLink/src/util.cc \
		-o homelink \
		-I./src \
		-I./3rdparty/netLink/include \
		-I./3rdparty/rapidxml-1.13 \
		-lmysqlpp \
		-lmysqlclient_r

