#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool PreIncrementExpression::__init_done = __init_static_variables();
bool PreIncrementExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"PreIncrementExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 PreIncrementExpression::~PreIncrementExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void PreIncrementExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"PreIncrementExpression", L"~PreIncrementExpression");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool PreIncrementExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr && !this->exp->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool PreIncrementExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->exp != nullptr && !this->exp->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool PreIncrementExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		return this->exp->analyse(context, leftValue, ctx);
	}
	return true;
}
IExpression* PreIncrementExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void PreIncrementExpression::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
IAlinousVariable* PreIncrementExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* variable = machine->resolveExpression(this->exp, debug, ctx);
	if(variable == nullptr || variable->isArray(ctx))
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_973(), ctx));
	}
	if(variable->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	IntegerVariable* operand = (new(ctx) IntegerVariable(1, ctx));
	IAlinousVariable* val = variable->add(operand, ctx);
	variable->substitute(val, ctx);
	return variable;
}
ExpressionSourceId* PreIncrementExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->exp->getSourceId(ctx)->getType(ctx), ctx));
}
bool PreIncrementExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int PreIncrementExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::preIncrementExpression;
}
}}}
