#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {





bool SchemasStructureInfoData::__init_done = __init_static_variables();
bool SchemasStructureInfoData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SchemasStructureInfoData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SchemasStructureInfoData::SchemasStructureInfoData(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), schemas(GCUtils<Map<String,SchemaData> >::ins(this, (new(ctx) HashMap<String,SchemaData>(ctx)), ctx, __FILEW__, __LINE__, L"")), schemaVersion(0)
{
}
void SchemasStructureInfoData::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SchemasStructureInfoData::~SchemasStructureInfoData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SchemasStructureInfoData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SchemasStructureInfoData", L"~SchemasStructureInfoData");
	__e_obj1.add(this->schemas, this);
	schemas = nullptr;
	if(!prepare){
		return;
	}
}
void SchemasStructureInfoData::join(SchemasStructureInfoData* data, ThreadContext* ctx) throw() 
{
	Map<String,SchemaData>* dataSchemas = data->schemas;
	Iterator<String>* it = dataSchemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* name = it->next(ctx);
		SchemaData* schemaData = dataSchemas->get(name, ctx);
		SchemaData* lastSchemaData = findLocalSchema(name, schemaData, ctx);
		if(lastSchemaData == schemaData)
		{
			continue;
		}
		lastSchemaData->join(schemaData, ctx);
	}
	long long ver = data->getSchemaVersion(ctx);
	if(this->schemaVersion < ver)
	{
		this->schemaVersion = ver;
	}
}
bool SchemasStructureInfoData::hasSchema(String* name, ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->schemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		if(key->equals(name, ctx))
		{
			return false;
		}
	}
	return false;
}
void SchemasStructureInfoData::addScheme(SchemaData* value, ThreadContext* ctx) throw() 
{
	this->schemas->put(value->getName(ctx), value, ctx);
}
Map<String,SchemaData>* SchemasStructureInfoData::getSchemas(ThreadContext* ctx) throw() 
{
	return schemas;
}
void SchemasStructureInfoData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SchemaData* data = (new(ctx) SchemaData(ctx));
		data->readData(buff, ctx);
		this->schemas->put(data->getName(ctx), data, ctx);
	}
	this->schemaVersion = buff->getLong(ctx);
}
void SchemasStructureInfoData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = this->schemas->size(ctx);
	buff->putInt(maxLoop, ctx);
	Iterator<String>* it = this->schemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* schemeName = it->next(ctx);
		SchemaData* data = this->schemas->get(schemeName, ctx);
		data->writeData(buff, ctx);
	}
	buff->putLong(this->schemaVersion, ctx);
}
long long SchemasStructureInfoData::getSchemaVersion(ThreadContext* ctx) throw() 
{
	return schemaVersion;
}
void SchemasStructureInfoData::setSchemaVersion(long long schemaVersion, ThreadContext* ctx) throw() 
{
	this->schemaVersion = schemaVersion;
}
SchemaData* SchemasStructureInfoData::findLocalSchema(String* name, SchemaData* schemaData, ThreadContext* ctx) throw() 
{
	SchemaData* data = this->schemas->get(name, ctx);
	if(data == nullptr)
	{
		data = schemaData;
		this->schemas->put(name, schemaData, ctx);
	}
	return data;
}
void SchemasStructureInfoData::__cleanUp(ThreadContext* ctx){
}
}}}}}}

