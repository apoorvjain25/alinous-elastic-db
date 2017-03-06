#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/CatchBlock.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/FinallyBlock.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/ThrowStatement.h"
#include "alinous.compile.stmt/TryBlock.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"

namespace alinous {namespace compile {namespace stmt {





bool WhileStatement::__init_done = __init_static_variables();
bool WhileStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"WhileStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 WhileStatement::WhileStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), label(nullptr), exp(nullptr), exec(nullptr)
{
}
void WhileStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 WhileStatement::~WhileStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void WhileStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"WhileStatement", L"~WhileStatement");
	__e_obj1.add(this->label, this);
	label = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->exec, this);
	exec = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void WhileStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool WhileStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->label != nullptr && !this->label->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->exp != nullptr && !this->exp->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->exec != nullptr && !this->exec->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool WhileStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->label != nullptr)
	{
		this->label->analyse(context, leftValue, ctx);
	}
	if(this->exp != nullptr)
	{
		this->exp->analyse(context, leftValue, ctx);
	}
	if(this->exec != nullptr)
	{
		this->exec->analyse(context, leftValue, ctx);
	}
	return true;
}
IStatement::StatementType WhileStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::WHILE_STATEMENT;
}
LabeledStatement* WhileStatement::getLabel(ThreadContext* ctx) throw() 
{
	return label;
}
void WhileStatement::setLabel(LabeledStatement* label, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->label), label, LabeledStatement);
}
IExpression* WhileStatement::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void WhileStatement::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
IStatement* WhileStatement::getExec(ThreadContext* ctx) throw() 
{
	return exec;
}
void WhileStatement::setExec(IStatement* exec, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exec), exec, IStatement);
}
void WhileStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<LabeledStatement*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1098(), ctx));
		}
		__GC_MV(this, &(this->label), static_cast<LabeledStatement*>(el), LabeledStatement);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<IExpression*>(el), IExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IStatement*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1099(), ctx));
		}
		__GC_MV(this, &(this->exec), static_cast<IStatement*>(el), IStatement);
	}
}
void WhileStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__WhileStatement, ctx);
	bool isnull = (this->label == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->label->writeData(buff, ctx);
	}
	isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
	isnull = (this->exec == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exec->writeData(buff, ctx);
	}
}
void WhileStatement::__cleanUp(ThreadContext* ctx){
}
}}}

