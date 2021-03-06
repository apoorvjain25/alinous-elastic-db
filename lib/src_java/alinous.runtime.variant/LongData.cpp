#include "include/global.h"


#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/Attribute.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/IVariantData.h"
#include "alinous.runtime.variant/StringData.h"
#include "alinous.runtime.variant/LongData.h"
#include "alinous.runtime.variant/IntData.h"
#include "alinous.runtime.variant/ShortData.h"
#include "alinous.runtime.variant/ByteData.h"
#include "alinous.runtime.variant/FloatData.h"
#include "alinous.runtime.variant/DoubleData.h"
#include "alinous.runtime.variant/BigDecimalData.h"
#include "alinous.runtime.variant/TimeData.h"
#include "alinous.runtime.variant/TimestampData.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.variant/CharData.h"
#include "alinous.runtime.variant/VariantDataFactory.h"

namespace alinous {namespace runtime {namespace variant {





String* LongData::TAG_NAME = ConstStr::getCNST_STR_1260();
bool LongData::__init_done = __init_static_variables();
bool LongData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LongData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LongData::LongData(long long data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(0)
{
	this->data = data;
}
void LongData::__construct_impl(long long data, ThreadContext* ctx) throw() 
{
	this->data = data;
}
 LongData::LongData(ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(0)
{
}
void LongData::__construct_impl(ThreadContext* ctx) throw() 
{
}
 LongData::~LongData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LongData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LongData", L"~LongData");
	if(!prepare){
		return;
	}
}
void LongData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, Long::toString(this->data, ctx), node, ctx));
	node->addAttribute(attr, ctx);
}
int LongData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_LONG;
}
String* LongData::getString(ThreadContext* ctx) throw() 
{
	return Long::toString(this->data, ctx);
}
long long LongData::getLong(ThreadContext* ctx) throw() 
{
	return this->data;
}
int LongData::getInt(ThreadContext* ctx) throw() 
{
	return ((int)this->data);
}
short LongData::getShort(ThreadContext* ctx) throw() 
{
	return ((short)this->data);
}
wchar_t LongData::getChar(ThreadContext* ctx) throw() 
{
	return ((wchar_t)this->data);
}
char LongData::getByte(ThreadContext* ctx) throw() 
{
	return ((char)this->data);
}
float LongData::getFloat(ThreadContext* ctx) throw() 
{
	return this->data;
}
double LongData::getDouble(ThreadContext* ctx) throw() 
{
	return this->data;
}
bool LongData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data > (long long)0;
}
BigDecimal* LongData::getBigDecimal(ThreadContext* ctx) throw() 
{
	return (new(ctx) BigDecimal(this->data, ctx));
}
TimeOnlyTimestamp* LongData::getTime(ThreadContext* ctx) throw() 
{
	return (new(ctx) TimeOnlyTimestamp(this->data, ctx));
}
Timestamp* LongData::getTimestamp(ThreadContext* ctx) throw() 
{
	return (new(ctx) Timestamp(this->data, ctx));
}
int LongData::bufferSize(ThreadContext* ctx) throw() 
{
	return 8;
}
void LongData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putLong(this->data, ctx);
}
bool LongData::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
int LongData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	long long sub = this->data - variant->getLong(ctx);
	return sub >= (long long)0 ? ((int)sub) : -1;
}
void LongData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	this->data = buff->getLong(ctx);
}
void LongData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(IVariantData::TYPE_LONG, ctx);
	buff->putLong(this->data, ctx);
}
LongData* LongData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(TAG_NAME, ctx))
	{
		return nullptr;
	}
	IVariableValue* attr = node->getAttributeValue(IVariantData::ATTR_VALUE, ctx);
	if(attr == nullptr)
	{
		return nullptr;
	}
	LongData* data = nullptr;
	{
		try
		{
			String* str = attr->toString(ctx);
			long long val = Long::parseLong(str, ctx);
			data = (new(ctx) LongData(val, ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return data;
}
void LongData::__cleanUp(ThreadContext* ctx){
}
int LongData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}

