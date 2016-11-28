#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {





bool AbstractSQLCollectionExpression::__init_done = __init_static_variables();
bool AbstractSQLCollectionExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSQLCollectionExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSQLCollectionExpression::AbstractSQLCollectionExpression(ThreadContext* ctx) throw()  : IObject(ctx), ISQLExpression(ctx), first(nullptr), expressions(GCUtils<ArrayList<SQLSubExpression> >::ins(this, (new(ctx) ArrayList<SQLSubExpression>(ctx)), ctx, __FILEW__, __LINE__, L"")), asName(nullptr)
{
}
void AbstractSQLCollectionExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractSQLCollectionExpression::~AbstractSQLCollectionExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSQLCollectionExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractSQLCollectionExpression", L"~AbstractSQLCollectionExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->expressions, this);
	expressions = nullptr;
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	if(!prepare){
		return;
	}
	ISQLExpression::__releaseRegerences(true, ctx);
}
ISQLExpression* AbstractSQLCollectionExpression::getFirst(ThreadContext* ctx) throw() 
{
	return first;
}
void AbstractSQLCollectionExpression::setFirst(ISQLExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, ISQLExpression);
}
ArrayList<SQLSubExpression>* AbstractSQLCollectionExpression::getExpressions(ThreadContext* ctx) throw() 
{
	return expressions;
}
void AbstractSQLCollectionExpression::addSubExpression(SQLSubExpression* exp, ThreadContext* ctx) throw() 
{
	this->expressions->add(exp, ctx);
}
bool AbstractSQLCollectionExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
bool AbstractSQLCollectionExpression::isConstant(ThreadContext* ctx) throw() 
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
bool AbstractSQLCollectionExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr)
	{
		this->first->analyse(context, leftValue, ctx);
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->expressions->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
bool AbstractSQLCollectionExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->first != nullptr)
	{
		this->first->analyseSQL(context, leftValue, debug, ctx);
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->expressions->get(i, ctx)->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool AbstractSQLCollectionExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && this->first->hasTable(table, ctx))
	{
		return true;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		bool ans = this->expressions->get(i, ctx)->hasTable(table, ctx);
		if(ans)
		{
			return true;
		}
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* AbstractSQLCollectionExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->first != nullptr)
	{
		ArrayList<ScanTableColumnIdentifier>* sublist = this->first->getColumns(ctx);
		if(sublist != nullptr)
		{
			list->addAll(sublist, ctx);
		}
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		list = SQLAnalyseContext::joinList(list, this->expressions->get(i, ctx), ctx);
	}
	return list;
}
int AbstractSQLCollectionExpression::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getLine(ctx);
}
int AbstractSQLCollectionExpression::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getStartPosition(ctx);
}
int AbstractSQLCollectionExpression::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndLine(ctx);
}
int AbstractSQLCollectionExpression::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndPosition(ctx);
}
AbstractSrcElement* AbstractSQLCollectionExpression::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getParent(ctx);
}
void AbstractSQLCollectionExpression::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpression::setParent(parent, ctx);
}
bool AbstractSQLCollectionExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* AbstractSQLCollectionExpression::getAsName(ThreadContext* ctx) throw() 
{
	return this->asName;
}
void AbstractSQLCollectionExpression::setAsName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), name, String);
}
}}}}
