#ifndef __HOME_SOCKET_H__
#define __HOME_SOCKET_H__

#include <netlink/socket_group.h>

namespace NL
{
	class Socket;
	class SocketGroup;
}

namespace Home
{
	class MessageListener;

	class Socket
	{
	public:
		Socket(unsigned int port, MessageListener* listener);
		~Socket();

		bool listen(unsigned int ms);

	private:
		class OnAccept : public NL::SocketGroupCmd
		{
		private:
			virtual void exec(NL::Socket* socket, NL::SocketGroup* group, void* reference);
		};

		class OnRead : public NL::SocketGroupCmd
		{
		public:
			OnRead(MessageListener* listener, NL::Socket* server);

		private:
			virtual void exec(NL::Socket* socket, NL::SocketGroup* group, void* reference);

			MessageListener* mListener;
			NL::Socket* mServer;
		};

		class OnDisconnect : public NL::SocketGroupCmd
		{
		private:
			virtual void exec(NL::Socket* socket, NL::SocketGroup* group, void* reference);
		};

		OnAccept* mOnAccept;
		OnRead* mOnRead;
		OnDisconnect* mOnDisconnect;
		NL::SocketGroup* mGroup;
		NL::Socket* mSocket;
	};
}

#endif
