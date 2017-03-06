#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"

namespace alinous {namespace compile {namespace sql {namespace ddl {





constexpr const int ColumnTypeDescriptor::INT;
constexpr const int ColumnTypeDescriptor::LONG;
constexpr const int ColumnTypeDescriptor::VARCHAR;
constexpr const int ColumnTypeDescriptor::TEXT;
constexpr const int ColumnTypeDescriptor::DOUBLE;
constexpr const int ColumnTypeDescriptor::DATE;
constexpr const int ColumnTypeDescriptor::TIME;
constexpr const int ColumnTypeDescriptor::TIMESTAMP;
constexpr const int ColumnTypeDescriptor::BLOB;
constexpr const int ColumnTypeDescriptor::BIG_DECIMAL;
bool ColumnTypeDescriptor::__init_done = __init_static_variables();
bool ColumnTypeDescriptor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ColumnTypeDescriptor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ColumnTypeDescriptor::ColumnTypeDescriptor(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx), length(nullptr), typeName(nullptr), typeNum(-1)
{
}
void ColumnTypeDescriptor::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ColumnTypeDescriptor::~ColumnTypeDescriptor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ColumnTypeDescriptor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ColumnTypeDescriptor", L"~ColumnTypeDescriptor");
	__e_obj1.add(this->length, this);
	length = nullptr;
	__e_obj1.add(this->typeName, this);
	typeName = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
bool ColumnTypeDescriptor::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->length != nullptr && !this->length->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
ISQLExpression* ColumnTypeDescriptor::getLength(ThreadContext* ctx) throw() 
{
	return length;
}
void ColumnTypeDescriptor::setLength(ISQLExpression* length, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->length), length, ISQLExpression);
}
String* ColumnTypeDescriptor::getTypeName(ThreadContext* ctx) throw() 
{
	return typeName;
}
void ColumnTypeDescriptor::setTypeName(String* typeName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->typeName), typeName, String);
	this->typeNum = toTypeNum(typeName, ctx);
}
int ColumnTypeDescriptor::getTypeNum(ThreadContext* ctx) throw() 
{
	if(this->typeNum < 0)
	{
		this->typeNum = toTypeNum(typeName, ctx);
	}
	return typeNum;
}
bool ColumnTypeDescriptor::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->length != nullptr)
	{
		this->length->analyse(context, leftValue, ctx);
	}
	return true;
}
int ColumnTypeDescriptor::getLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getLine(ctx);
}
int ColumnTypeDescriptor::getStartPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getStartPosition(ctx);
}
int ColumnTypeDescriptor::getEndLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndLine(ctx);
}
int ColumnTypeDescriptor::getEndPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndPosition(ctx);
}
AbstractSrcElement* ColumnTypeDescriptor::getParent(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getParent(ctx);
}
void ColumnTypeDescriptor::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IAlinousElement::setParent(parent, ctx);
}
void ColumnTypeDescriptor::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->length), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->typeName), buff->getString(ctx), String);
	}
	this->typeNum = buff->getInt(ctx);
}
void ColumnTypeDescriptor::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__Unique, ctx);
	bool isnull = (this->length == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->length->writeData(buff, ctx);
	}
	isnull = (this->typeName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->typeName, ctx);
	}
	buff->putInt(this->typeNum, ctx);
}
int ColumnTypeDescriptor::toTypeNum(String* str, ThreadContext* ctx) throw() 
{
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1056(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1057(), ctx))
	{
		return INT;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1058(), ctx))
	{
		return LONG;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1059(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1060(), ctx))
	{
		return VARCHAR;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1061(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1062(), ctx))
	{
		return TEXT;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1063(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1064(), ctx))
	{
		return DOUBLE;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1065(), ctx))
	{
		return DOUBLE;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1066(), ctx))
	{
		return TIMESTAMP;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1067(), ctx))
	{
		return TIME;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1068(), ctx))
	{
		return BIG_DECIMAL;
	}
	return -1;
}
void ColumnTypeDescriptor::__cleanUp(ThreadContext* ctx){
}
}}}}

