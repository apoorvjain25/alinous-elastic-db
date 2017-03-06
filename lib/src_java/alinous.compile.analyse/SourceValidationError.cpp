#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.analyse/SourceValidationError.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.compile.analyse/ClassDeclareHolder.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.analyse/TypedVariableDeclareSource.h"
#include "alinous.compile.analyse/TableColumnIdentifier.h"

namespace alinous {namespace compile {namespace analyse {





constexpr const int SourceValidationError::ERROR;
constexpr const int SourceValidationError::WARNING;
constexpr const int SourceValidationError::INFO;
bool SourceValidationError::__init_done = __init_static_variables();
bool SourceValidationError::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SourceValidationError", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SourceValidationError::SourceValidationError(ThreadContext* ctx) throw()  : IObject(ctx), type(0), message(nullptr), src(nullptr)
{
}
void SourceValidationError::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SourceValidationError::~SourceValidationError() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SourceValidationError::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SourceValidationError", L"~SourceValidationError");
	__e_obj1.add(this->message, this);
	message = nullptr;
	__e_obj1.add(this->src, this);
	src = nullptr;
	if(!prepare){
		return;
	}
}
int SourceValidationError::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void SourceValidationError::setType(int type, ThreadContext* ctx) throw() 
{
	this->type = type;
}
String* SourceValidationError::getMessage(ThreadContext* ctx) throw() 
{
	return message;
}
void SourceValidationError::setMessage(String* message, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->message), message, String);
}
IAlinousElement* SourceValidationError::getSrc(ThreadContext* ctx) throw() 
{
	return src;
}
void SourceValidationError::setSrc(IAlinousElement* src, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->src), src, IAlinousElement);
}
void SourceValidationError::__cleanUp(ThreadContext* ctx){
}
}}}

