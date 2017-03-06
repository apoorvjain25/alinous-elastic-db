#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/DomArray.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/ISqlStatement.h"
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
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db.trx/CreateIndexMetadata.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.remote.region.client.transaction/AbstractRemoteClientTransaction.h"
#include "alinous.remote.region.client.transaction/RemoteClientReadCommittedTrx.h"
#include "alinous.remote.region.client.transaction/RemoteClientSerializableTrx.h"
#include "alinous.remote.region.client.transaction/RemoteClientRepeatableReadTrx.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {





bool AbstractRemoteClientTransaction::__init_done = __init_static_variables();
bool AbstractRemoteClientTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractRemoteClientTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractRemoteClientTransaction::AbstractRemoteClientTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw()  : IObject(ctx), DbTransaction(mgr, tmpDir, database, core, commitId, vctx, ctx)
{
}
void AbstractRemoteClientTransaction::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
}
 AbstractRemoteClientTransaction::~AbstractRemoteClientTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractRemoteClientTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DbTransaction::__releaseRegerences(true, ctx);
}
bool AbstractRemoteClientTransaction::isRemote(ThreadContext* ctx) throw() 
{
	return true;
}
void AbstractRemoteClientTransaction::createTable(TableSchema* schema, ThreadContext* ctx)
{
	if(schema->getregionName(ctx) == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3602(), ctx));
	}
	DbTransaction::createTable(schema, ctx);
}
void AbstractRemoteClientTransaction::commitUpdateInsert(long long newCommitId, ThreadContext* ctx)
{
	if(this->trxStorageManager->isHasOperation(ctx))
	{
		{
			try
			{
				this->trxStorageManager->commitRemote(this, newCommitId, ctx);
			}
			catch(IOException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1712(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1712(), e, ctx));
			}
			catch(VariableException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1712(), e, ctx));
			}
			catch(BTreeException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1712(), e, ctx));
			}
		}
	}
	this->trxStorageManager->reset(ctx);
}
void AbstractRemoteClientTransaction::__cleanUp(ThreadContext* ctx){
}
}}}}}

