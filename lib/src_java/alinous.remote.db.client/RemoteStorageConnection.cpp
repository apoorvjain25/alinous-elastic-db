#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace client {





bool RemoteStorageConnection::__init_done = __init_static_variables();
bool RemoteStorageConnection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteStorageConnection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteStorageConnection::RemoteStorageConnection(SocketConnectionPool* pool, RemoteStorageConnectionInfo* info, ThreadContext* ctx) throw()  : IObject(ctx), ISocketConnection(ctx), pool(nullptr), info(nullptr), socket(nullptr)
{
	__GC_MV(this, &(this->pool), pool, SocketConnectionPool);
	__GC_MV(this, &(this->info), info, RemoteStorageConnectionInfo);
}
void RemoteStorageConnection::__construct_impl(SocketConnectionPool* pool, RemoteStorageConnectionInfo* info, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->pool), pool, SocketConnectionPool);
	__GC_MV(this, &(this->info), info, RemoteStorageConnectionInfo);
}
 RemoteStorageConnection::~RemoteStorageConnection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteStorageConnection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteStorageConnection", L"~RemoteStorageConnection");
	__e_obj1.add(this->pool, this);
	pool = nullptr;
	__e_obj1.add(this->info, this);
	info = nullptr;
	__e_obj1.add(this->socket, this);
	socket = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteStorageConnection::connect(ThreadContext* ctx)
{
	__GC_MV(this, &(this->socket), (new(ctx) AlinousSocket(info->getHost(ctx), info->getPort(ctx), ctx))->init(ctx), AlinousSocket);
	RemoteStorageConnectCommand* cmd = (new(ctx) RemoteStorageConnectCommand(ctx));
	cmd->sendCommand(this->socket, ctx);
	if(!cmd->isConnected(ctx))
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3482(), ctx));
	}
}
void RemoteStorageConnection::close(ThreadContext* ctx) throw() 
{
	this->pool->returnConnection(this, ctx);
}
void RemoteStorageConnection::dispose(ThreadContext* ctx) throw() 
{
	{
		try
		{
			this->socket->close(ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
AlinousSocket* RemoteStorageConnection::getSocket(ThreadContext* ctx) throw() 
{
	return socket;
}
}}}}
