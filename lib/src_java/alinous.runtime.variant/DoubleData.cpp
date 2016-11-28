#include "includes.h"


namespace alinous {namespace runtime {namespace variant {





String* DoubleData::TAG_NAME = ConstStr::getCNST_STR_1159();
bool DoubleData::__init_done = __init_static_variables();
bool DoubleData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DoubleData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DoubleData::DoubleData(double data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(0)
{
	this->data = data;
}
void DoubleData::__construct_impl(double data, ThreadContext* ctx) throw() 
{
	this->data = data;
}
 DoubleData::~DoubleData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DoubleData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DoubleData", L"~DoubleData");
	if(!prepare){
		return;
	}
}
void DoubleData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, Double::toString(this->data, ctx), node, ctx));
	node->addAttribute(attr, ctx);
}
int DoubleData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_DOUBLE;
}
String* DoubleData::getString(ThreadContext* ctx) throw() 
{
	return Double::toString(this->data, ctx);
}
long long DoubleData::getLong(ThreadContext* ctx) throw() 
{
	return ((long long)this->data);
}
int DoubleData::getInt(ThreadContext* ctx) throw() 
{
	return ((int)this->data);
}
short DoubleData::getShort(ThreadContext* ctx) throw() 
{
	return ((short)this->data);
}
wchar_t DoubleData::getChar(ThreadContext* ctx) throw() 
{
	return ((wchar_t)this->data);
}
char DoubleData::getByte(ThreadContext* ctx) throw() 
{
	return ((char)this->data);
}
float DoubleData::getFloat(ThreadContext* ctx) throw() 
{
	return ((float)this->data);
}
double DoubleData::getDouble(ThreadContext* ctx) throw() 
{
	return this->data;
}
bool DoubleData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data > (double)0;
}
BigDecimal* DoubleData::getBigDecimal(ThreadContext* ctx) throw() 
{
	return (new(ctx) BigDecimal(this->data, ctx));
}
TimeOnlyTimestamp* DoubleData::getTime(ThreadContext* ctx) throw() 
{
	return (new(ctx) TimeOnlyTimestamp(((long long)this->data), ctx));
}
Timestamp* DoubleData::getTimestamp(ThreadContext* ctx) throw() 
{
	return (new(ctx) Timestamp(((long long)this->data), ctx));
}
int DoubleData::bufferSize(ThreadContext* ctx) throw() 
{
	return 8;
}
void DoubleData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putDouble(this->data, ctx);
}
bool DoubleData::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
int DoubleData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	double sub = this->data - variant->getDouble(ctx);
	return sub >= (double)0 ? ((int)sub) : -1;
}
DoubleData* DoubleData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
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
	DoubleData* data = nullptr;
	{
		try
		{
			String* str = attr->toString(ctx);
			double val = Double::parseDouble(str, ctx);
			data = (new(ctx) DoubleData(val, ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return data;
}
int DoubleData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}
