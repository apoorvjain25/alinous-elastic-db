#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool AbstractCollectionExpression::__init_done = __init_static_variables();
bool AbstractCollectionExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractCollectionExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractCollectionExpression::AbstractCollectionExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), first(nullptr), expressions(GCUtils<ArrayList<SubExpression> >::ins(this, (new(ctx) ArrayList<SubExpression>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AbstractCollectionExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractCollectionExpression::~AbstractCollectionExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractCollectionExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractCollectionExpression", L"~AbstractCollectionExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->expressions, this);
	expressions = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
void AbstractCollectionExpression::setFirst(IExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, IExpression);
}
ArrayList<SubExpression>* AbstractCollectionExpression::getExpressions(ThreadContext* ctx) throw() 
{
	return expressions;
}
void AbstractCollectionExpression::addSubExpression(SubExpression* exp, ThreadContext* ctx) throw() 
{
	this->expressions->add(exp, ctx);
}
bool AbstractCollectionExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && !this->first->isConstant(ctx))
	{
		return false;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->expressions->get(i, ctx)->isConstant(ctx))
		{
			return false;
		}
	}
	return true;
}
bool AbstractCollectionExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->first != nullptr && !this->first->visit(visitor, this, ctx))
	{
		return false;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->expressions->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool AbstractCollectionExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr)
	{
		return first->analyse(context, leftValue, ctx);
	}
	return true;
}
ExpressionSourceId* AbstractCollectionExpression::getSourceId(ThreadContext* ctx) throw() 
{
	AlinousType* type = this->first->getSourceId(ctx)->getType(ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SubExpression* subexp = this->expressions->get(i, ctx);
		AlinousType* subType = subexp->getSourceId(ctx)->getType(ctx);
		if(subType->getType(ctx) > type->getType(ctx))
		{
			type = subType;
		}
	}
	return (new(ctx) ExpressionSourceId(nullptr, this, type, ctx));
}
}}}
