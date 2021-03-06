#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/TableIndexValue.h"

namespace alinous {namespace db {namespace table {





const TableIndexValue::ValueFetcher TableIndexValue:: __fetcher = (TableIndexValue::ValueFetcher(nullptr));
bool TableIndexValue::__init_done = __init_static_variables();
bool TableIndexValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableIndexValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableIndexValue::TableIndexValue(long long oid, long long position, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), oid(0), position(0)
{
	this->oid = oid;
	this->position = position;
}
void TableIndexValue::__construct_impl(long long oid, long long position, ThreadContext* ctx) throw() 
{
	this->oid = oid;
	this->position = position;
}
 TableIndexValue::~TableIndexValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableIndexValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableIndexValue", L"~TableIndexValue");
	if(!prepare){
		return;
	}
}
void TableIndexValue::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeValue::TYPE_TABLE_INDEX_VALUE, ctx);
	builder->putLong(this->position, ctx);
	builder->putLong(this->oid, ctx);
}
int TableIndexValue::diskSize(ThreadContext* ctx)
{
	return IBTreeValue::TYPE_SIZE + 8 + 8;
}
IValueFetcher* TableIndexValue::getFetcher(ThreadContext* ctx) throw() 
{
	return fetcher;
}
bool TableIndexValue::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->oid == (dynamic_cast<TableIndexValue*>(obj))->oid && this->position == (dynamic_cast<TableIndexValue*>(obj))->position;
}
long long TableIndexValue::getOid(ThreadContext* ctx) throw() 
{
	return oid;
}
void TableIndexValue::setOid(long long oid, ThreadContext* ctx) throw() 
{
	this->oid = oid;
}
long long TableIndexValue::getPosition(ThreadContext* ctx) throw() 
{
	return position;
}
void TableIndexValue::setPosition(long long position, ThreadContext* ctx) throw() 
{
	this->position = position;
}
void TableIndexValue::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace db {namespace table {





bool TableIndexValue::ValueFetcher::__init_done = __init_static_variables();
bool TableIndexValue::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableIndexValue::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableIndexValue::ValueFetcher::ValueFetcher(ThreadContext* ctx) throw()  : IObject(ctx), IValueFetcher(ctx)
{
}
void TableIndexValue::ValueFetcher::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TableIndexValue::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableIndexValue::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* TableIndexValue::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	long long position = fetcher->fetchLong(ctx);
	long long oid = fetcher->fetchLong(ctx);
	return (new(ctx) TableIndexValue(oid, position, ctx));
}
void TableIndexValue::ValueFetcher::__cleanUp(ThreadContext* ctx){
}
}}}

