#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"

namespace alinous {namespace compile {namespace expression {





bool AdditiveExpression::__init_done = __init_static_variables();
bool AdditiveExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AdditiveExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AdditiveExpression::AdditiveExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractCollectionExpression(ctx)
{
}
void AdditiveExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AdditiveExpression::~AdditiveExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AdditiveExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* AdditiveExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* variable = machine->resolveExpression(this->first, debug, ctx);
	if(variable == nullptr || variable->isArray(ctx))
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1037(), ctx));
	}
	if(variable->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	variable = variable->copy(ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SubExpression* subexp = this->expressions->get(i, ctx);
		IAlinousVariable* operand = machine->resolveExpression(subexp->getExp(ctx), debug, ctx)->copy(ctx);
		switch(subexp->getOp(ctx)) {
		case AbstractExpression::MINUS:
			variable = variable->minus(operand, ctx);
			break ;
		default:
			variable = variable->add(operand, ctx);
			break ;
		}
	}
	return variable;
}
bool AdditiveExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int AdditiveExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::additiveExpression;
}
void AdditiveExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void AdditiveExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__AdditiveExpression, ctx);
	__writeData(buff, ctx);
}
void AdditiveExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__AdditiveExpression, ctx);
	__toFileEntry(builder, ctx);
}
void AdditiveExpression::includes(IExpressionFactory* arg0, ThreadContext* ctx) throw() 
{
}
void AdditiveExpression::__cleanUp(ThreadContext* ctx){
}
}}}

