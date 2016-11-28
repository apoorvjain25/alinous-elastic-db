#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {





bool SQLFrom::__init_done = __init_static_variables();
bool SQLFrom::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLFrom", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLFrom::~SQLFrom() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLFrom::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLFrom", L"~SQLFrom");
	__e_obj1.add(this->join, this);
	join = nullptr;
	if(!prepare){
		return;
	}
	ISQLExpression::__releaseRegerences(true, ctx);
}
bool SQLFrom::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->join != nullptr && !this->join->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLFrom::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLFrom::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->join != nullptr)
	{
		this->join->analyse(context, leftValue, ctx);
	}
	return true;
}
IJoin* SQLFrom::getJoin(ThreadContext* ctx) throw() 
{
	return join;
}
void SQLFrom::setJoin(IJoin* join, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->join), join, IJoin);
}
IAlinousVariable* SQLFrom::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
ExpressionSourceId* SQLFrom::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
bool SQLFrom::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLFrom::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	this->join->analyseSQLTables(context, false, debug, ctx);
	this->join->analyzeSQL(context, debug, ctx);
	return true;
}
bool SQLFrom::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return this->join->hasTable(table, ctx);
}
ArrayList<ScanTableColumnIdentifier>* SQLFrom::getColumns(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLFrom::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLFrom::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLFrom::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* SQLFrom::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLFrom::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
int SQLFrom::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getLine(ctx);
}
int SQLFrom::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getStartPosition(ctx);
}
int SQLFrom::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndLine(ctx);
}
int SQLFrom::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndPosition(ctx);
}
AbstractSrcElement* SQLFrom::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getParent(ctx);
}
void SQLFrom::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpression::setParent(parent, ctx);
}
bool SQLFrom::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLFrom::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1006(), ctx));
}
bool SQLFrom::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* SQLFrom::getAsName(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void SQLFrom::setAsName(String* name, ThreadContext* ctx) throw() 
{
}
int SQLFrom::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLFrom;
}
}}}}
