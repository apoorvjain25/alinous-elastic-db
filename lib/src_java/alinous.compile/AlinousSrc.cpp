#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.compile/DebugProbeSection.h"
#include "alinous.compile/DebugProbe.h"
#include "alinous.compile/TokenMgrError.h"
#include "alinous.compile/ParseException.h"
#include "alinous.compile/JavaCharStream.h"
#include "alinous.compile/AlinousPlusParserConstants.h"
#include "alinous.compile/AlinousPlusParserTokenManager.h"
#include "alinous.compile/AlinousPlusParser.h"

namespace alinous {namespace compile {





bool AlinousSrc::__init_done = __init_static_variables();
bool AlinousSrc::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousSrc", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousSrc::AlinousSrc(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx), includes(GCUtils<ArrayList<IncludePreprocessor> >::ins(this, (new(ctx) ArrayList<IncludePreprocessor>(ctx)), ctx, __FILEW__, __LINE__, L"")), statements(GCUtils<ArrayList<StatementList> >::ins(this, (new(ctx) ArrayList<StatementList>(ctx)), ctx, __FILEW__, __LINE__, L"")), declares(GCUtils<ArrayList<IDeclare> >::ins(this, (new(ctx) ArrayList<IDeclare>(ctx)), ctx, __FILEW__, __LINE__, L"")), functionDeclares(GCUtils<ArrayList<AlinousFunction> >::ins(this, (new(ctx) ArrayList<AlinousFunction>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AlinousSrc::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousSrc::~AlinousSrc() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousSrc::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousSrc", L"~AlinousSrc");
	__e_obj1.add(this->includes, this);
	includes = nullptr;
	__e_obj1.add(this->statements, this);
	statements = nullptr;
	__e_obj1.add(this->declares, this);
	declares = nullptr;
	__e_obj1.add(this->functionDeclares, this);
	functionDeclares = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
void AlinousSrc::addInclude(IncludePreprocessor* inc, ThreadContext* ctx) throw() 
{
	this->includes->add(inc, ctx);
}
ArrayList<IncludePreprocessor>* AlinousSrc::getIncludes(ThreadContext* ctx) throw() 
{
	return this->includes;
}
void AlinousSrc::addDeclare(IDeclare* dec, ThreadContext* ctx) throw() 
{
	this->declares->add(dec, ctx);
	if((dynamic_cast<AlinousFunction*>(dec) != 0))
	{
		this->functionDeclares->add(static_cast<AlinousFunction*>(dec), ctx);
	}
}
ArrayList<IDeclare>* AlinousSrc::getDeclares(ThreadContext* ctx) throw() 
{
	return declares;
}
void AlinousSrc::addStatementList(StatementList* list, ThreadContext* ctx) throw() 
{
	this->statements->add(list, ctx);
}
ArrayList<StatementList>* AlinousSrc::getStatements(ThreadContext* ctx) throw() 
{
	return statements;
}
ArrayList<AlinousFunction>* AlinousSrc::getFunctionDeclares(ThreadContext* ctx) throw() 
{
	return functionDeclares;
}
bool AlinousSrc::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	int maxLoop = this->includes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->includes->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->statements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->statements->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->declares->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->declares->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool AlinousSrc::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	int maxLoop = this->includes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IncludePreprocessor* inc = this->includes->get(i, ctx);
		inc->analyse(context, leftValue, ctx);
	}
	maxLoop = this->declares->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->declares->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->statements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->statements->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
void AlinousSrc::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousElement* element = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(element == nullptr || !((dynamic_cast<IncludePreprocessor*>(element) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_945(), ctx));
		}
		this->includes->add(static_cast<IncludePreprocessor*>(element), ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousElement* element = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(element == nullptr || !((dynamic_cast<IDeclare*>(element) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_946(), ctx));
		}
		this->declares->add(static_cast<IDeclare*>(element), ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousElement* element = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(element == nullptr || !((dynamic_cast<StatementList*>(element) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_947(), ctx));
		}
		this->statements->add(static_cast<StatementList*>(element), ctx);
	}
}
void AlinousSrc::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__AlinousSrc, ctx);
	int maxLoop = this->includes->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IncludePreprocessor* inc = this->includes->get(i, ctx);
		inc->writeData(buff, ctx);
	}
	maxLoop = this->declares->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDeclare* dec = this->declares->get(i, ctx);
		dec->writeData(buff, ctx);
	}
	maxLoop = this->statements->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		StatementList* list = this->statements->get(i, ctx);
		list->writeData(buff, ctx);
	}
}
int AlinousSrc::getLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getLine(ctx);
}
int AlinousSrc::getStartPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getStartPosition(ctx);
}
int AlinousSrc::getEndLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndLine(ctx);
}
int AlinousSrc::getEndPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndPosition(ctx);
}
AbstractSrcElement* AlinousSrc::getParent(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getParent(ctx);
}
void AlinousSrc::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IAlinousElement::setParent(parent, ctx);
}
void AlinousSrc::__cleanUp(ThreadContext* ctx){
}
}}

