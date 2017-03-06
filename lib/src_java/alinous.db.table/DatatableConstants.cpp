#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/DatabaseException.h"
#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "java.sql/Timestamp.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.table/TableIndexValue.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table/IndexInsertJob.h"
#include "alinous.db.table/OidIndexJob.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table.lockmonitor/DBThreadMonitor.h"
#include "alinous.db.table/DatabaseTable.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.table/OidPublisherFactory.h"
#include "alinous.db.table/LocalOidCounter.h"
#include "alinous.db.table/LocalOidPublisher.h"
#include "alinous.db.table/DatatableConstants.h"

namespace alinous {namespace db {namespace table {




constexpr const int DatatableConstants::capacity;
constexpr const int DatatableConstants::BLOCK_SIZE;
constexpr const int DatatableConstants::maxCache;
bool DatatableConstants::__init_done = __init_static_variables();
bool DatatableConstants::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatatableConstants", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatatableConstants::DatatableConstants(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void DatatableConstants::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DatatableConstants::~DatatableConstants() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatatableConstants::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void DatatableConstants::__cleanUp(ThreadContext* ctx){
}
}}}

