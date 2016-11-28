#include "includes.h"


namespace alinous {namespace db {namespace table {





bool IndexInsertJob::__init_done = __init_static_variables();
bool IndexInsertJob::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexInsertJob", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexInsertJob::IndexInsertJob(TableIndex* tableIndex, DatabaseRecord* dbrecord, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), tableIndex(nullptr), dbrecord(nullptr)
{
	__GC_MV(this, &(this->tableIndex), tableIndex, TableIndex);
	__GC_MV(this, &(this->dbrecord), dbrecord, DatabaseRecord);
}
void IndexInsertJob::__construct_impl(TableIndex* tableIndex, DatabaseRecord* dbrecord, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableIndex), tableIndex, TableIndex);
	__GC_MV(this, &(this->dbrecord), dbrecord, DatabaseRecord);
}
 IndexInsertJob::~IndexInsertJob() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexInsertJob::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IndexInsertJob", L"~IndexInsertJob");
	__e_obj1.add(this->tableIndex, this);
	tableIndex = nullptr;
	__e_obj1.add(this->dbrecord, this);
	dbrecord = nullptr;
	if(!prepare){
		return;
	}
}
void IndexInsertJob::execute(ThreadContext* ctx)
{
	this->tableIndex->addIndexValue(this->dbrecord, ctx);
}
}}}
