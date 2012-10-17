#include "home_socket.h"
#include "home_messagelistener.h"
#include <netlink/socket.h>
#include <netlink/socket_group.h>

namespace Home
{
	// -------------------------------------------------------------------------
	void Socket::OnAccept::exec(NL::Socket* socket, NL::SocketGroup* group
			, void* /*reference*/)
	{
		NL::Socket* newConnection = socket->accept();
		group->add(newConnection);

		printf("Client (id=%d) connected\n", newConnection->socketHandler());
	}

	// -------------------------------------------------------------------------
	Socket::OnRead::OnRead(MessageListener* listener, NL::Socket* server)
		: mListener(listener)
		, mServer(server)
	{
	}

	// -------------------------------------------------------------------------
	void Socket::OnRead::exec(NL::Socket* socket, NL::SocketGroup* group
			, void* /*reference*/)
	{
		printf("Incoming data from client (id=%d)\n", socket->socketHandler());

		char buffer[4096];
		memset(buffer, 0, sizeof(buffer));
		socket->read(buffer, sizeof(buffer));
		size_t msgLen = strlen(buffer);

		if(mListener)
			mListener->onMessage(buffer, socket->hostTo());

		for(size_t i = 1; i < group->size(); ++i)
		{
			if(group->get(i) != socket)
				group->get(i)->send(buffer, msgLen + 1);
		}

		group->remove(socket);
		socket->disconnect();
	}

	// -------------------------------------------------------------------------
	void Socket::OnDisconnect::exec(NL::Socket* socket, NL::SocketGroup* group
			, void* /*reference*/)
	{
		group->remove(socket);

		printf("Client (id=%d) disconnected\n", socket->socketHandler());

		delete socket;
	}

	// -------------------------------------------------------------------------
	Socket::Socket(unsigned int port, MessageListener* listener)
	{
		NL::init();

		mSocket = new NL::Socket(port);
		mGroup = new NL::SocketGroup();

		mOnAccept = new OnAccept();
		mOnRead = new OnRead(listener, mSocket);
		mOnDisconnect = new OnDisconnect();

		mGroup->setCmdOnAccept(mOnAccept);
		mGroup->setCmdOnRead(mOnRead);
		mGroup->setCmdOnDisconnect(mOnDisconnect);
		mGroup->add(&*mSocket);
	}

	// -------------------------------------------------------------------------
	Socket::~Socket()
	{
		delete mSocket;
		delete mGroup;

		delete mOnDisconnect;
		delete mOnRead;
		delete mOnAccept;
	}

	// -------------------------------------------------------------------------
	bool Socket::listen(unsigned int ms)
	{
		return mGroup->listen(ms);
	}
}
