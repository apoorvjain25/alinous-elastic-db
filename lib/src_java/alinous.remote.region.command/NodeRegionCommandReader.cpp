#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {





bool NodeRegionCommandReader::__init_done = __init_static_variables();
bool NodeRegionCommandReader::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionCommandReader", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionCommandReader::~NodeRegionCommandReader() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionCommandReader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
AbstractNodeRegionCommand* NodeRegionCommandReader::readFromStream(InputStream* stream, ThreadContext* ctx)
{
	int type = readInt(stream, ctx);
	AbstractNodeRegionCommand* cmd = nullptr;
	switch(type) {
	case AbstractNodeRegionCommand::TYPE_FINISH:
		cmd = (new(ctx) NodeRegionFinishConnectionCommand(ctx));
		break ;
	case AbstractNodeRegionCommand::TYPE_TERMINATE:
		cmd = (new(ctx) NodeRegionTerminateCommand(ctx));
		break ;
	case AbstractNodeRegionCommand::TYPE_VOID:
		cmd = (new(ctx) NodeRegionVoidCommand(ctx));
		break ;
	default:
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3474(), ctx));
		break;
	}
	cmd->readFromStream(stream, ctx);
	return cmd;
}
int NodeRegionCommandReader::readInt(InputStream* stream, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* intbytes = ArrayAllocatorPrimitive<char>::allocatep(ctx, 4);
	stream->read(intbytes, ctx);
	ByteBuffer* buff = ByteBuffer::wrap(intbytes, ctx);
	return buff->getInt(ctx);
}
}}}}
