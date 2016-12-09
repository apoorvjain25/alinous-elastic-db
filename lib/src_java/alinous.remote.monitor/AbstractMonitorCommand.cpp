#include "includes.h"


namespace alinous {namespace remote {namespace monitor {





constexpr const int AbstractMonitorCommand::TYPE_VOID;
constexpr const int AbstractMonitorCommand::TYPE_FINISH;
constexpr const int AbstractMonitorCommand::TYPE_TERMINATE;
bool AbstractMonitorCommand::__init_done = __init_static_variables();
bool AbstractMonitorCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractMonitorCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractMonitorCommand::~AbstractMonitorCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractMonitorCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractMonitorCommand", L"~AbstractMonitorCommand");
	if(!prepare){
		return;
	}
}
int AbstractMonitorCommand::getType(ThreadContext* ctx) throw() 
{
	return type;
}
}}}
