#include "include/global.h"


#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.lock/LockObject.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
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
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer/FifoList.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.buffer/HashArrayList.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree.scan/AbstractNodeIterator.h"
#include "alinous.btree.scan/LeafContainerIterator.h"
#include "alinous.btree/AbstractBTreeLeafContainer.h"
#include "alinous.btree/BTreeMaxLeafContainer.h"
#include "alinous.btree/BTreeValues.h"
#include "alinous.btree/KeyValue.h"
#include "alinous.btree/BTreeLeafNode.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/BTreeLeafContainer.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/TimestampValue.h"
#include "alinous.btree/IntKey.h"
#include "alinous.btree/IntValue.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.trx.scan/PadddingRecord.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table/LocalOidCounter.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.table/LocalOidPublisher.h"
#include "alinous.db.table/TableIndexValue.h"
#include "alinous.btree/StringValue.h"
#include "alinous.btree/DoubleValue.h"
#include "alinous.btree/LongKey.h"
#include "alinous.btree/StringKey.h"
#include "alinous.btree/DoubleKey.h"
#include "alinous.btree/TimestampKey.h"
#include "alinous.btree/KeyValueFactory.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/BTreeMachine.h"

namespace alinous {namespace btree {





bool KeyValueFactory::__init_done = __init_static_variables();
bool KeyValueFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"KeyValueFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 KeyValueFactory::KeyValueFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void KeyValueFactory::__construct_impl(ThreadContext* ctx) throw() 
{
}
 KeyValueFactory::~KeyValueFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void KeyValueFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
BTreeValues* KeyValueFactory::valuesFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	BTreeValues* values = (new(ctx) BTreeValues(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IBTreeValue* val = valueFromFetcher(fetcher, ctx);
		values->addValue(val, ctx);
	}
	return values;
}
IBTreeValue* KeyValueFactory::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	IBTreeValue* value = nullptr;
	int valueType = fetcher->fetchInt(ctx);
	switch(valueType) {
	case IBTreeValue::TYPE_INT:
		value = (new(ctx) IntValue(fetcher->fetchInt(ctx), ctx));
		break ;
	case IBTreeValue::TYPE_LONG:
		value = (new(ctx) LongValue(fetcher->fetchLong(ctx), ctx));
		break ;
	case IBTreeValue::TYPE_STRING:
		value = (new(ctx) StringValue(fetcher->fetchString(ctx), ctx));
		break ;
	case IBTreeValue::TYPE_TIMESTAMP:
		value = (new(ctx) TimestampValue(fetcher->fetchLong(ctx), ctx));
		break ;
	case IBTreeValue::TYPE_DOUBLE:
		value = (new(ctx) DoubleValue(fetcher->fetchDouble(ctx), ctx));
		break ;
	case IBTreeValue::TYPE_SCHEME:
		{
			try
			{
				value = SchemaManager::valueFromFetcher(fetcher, ctx);
			}
			catch(AlinousDbException* e)
			{
				throw (new(ctx) VariableException(ConstStr::getCNST_STR_1657(), e, ctx));
			}
		}
		break ;
	case IBTreeValue::TYPE_CACHE_RECORD:
		value = CachedRecord::valueFromFetcher(fetcher, ctx);
		break ;
	case IBTreeValue::TYPE_DATABASE_RECORD:
		value = DatabaseRecord::valueFromFetcher(fetcher, ctx);
		break ;
	case IBTreeValue::TYPE_SCAN_RESULT_RECORD:
		value = ScanResultRecord::valueFromFetcher(fetcher, ctx);
		break ;
	case IBTreeValue::TYPE_DOM_VARIABLE_RECORD:
		value = DomVariable::valueFromFetcher(fetcher, ctx);
		break ;
	case IBTreeValue::TYPE_TABLE_INDEX_VALUE:
		value = TableIndexValue::fetcher->valueFromFetcher(fetcher, ctx);
		break ;
	case IBTreeValue::TYPE_PADDING_RECORD:
		value = PadddingRecord::fromFetcher(fetcher, ctx);
		break ;
	case IBTreeValue::TYPE_LOCAL_ID_PUBLISHER:
		value = LocalOidPublisher::fromFetcher(fetcher, ctx);
		break ;
	}
	return value;
}
IBTreeKey* KeyValueFactory::keyFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	int keyType = fetcher->fetchInt(ctx);
	IBTreeKey* key = 0;
	switch(keyType) {
	case IBTreeKey::TYPE_INT:
		key = (new(ctx) IntKey(fetcher->fetchInt(ctx), ctx));
		break ;
	case IBTreeKey::TYPE_LONG:
		key = (new(ctx) LongKey(fetcher->fetchLong(ctx), ctx));
		break ;
	case IBTreeKey::TYPE_STRING:
		key = (new(ctx) StringKey(fetcher->fetchString(ctx), ctx));
		break ;
	case IBTreeKey::TYPE_DOUBLE:
		key = (new(ctx) DoubleKey(fetcher->fetchDouble(ctx), ctx));
		break ;
	case IBTreeKey::TYPE_TIMESTAMP:
		key = (new(ctx) TimestampKey(fetcher->fetchLong(ctx), ctx));
		break ;
	case IBTreeKey::TYPE_BTREE_INDEX_KEY:
		key = BTreeIndexKey::fetchFromEntry(fetcher, ctx);
		break ;
	default:
		key = nullptr;
		break ;
	}
	return key;
}
void KeyValueFactory::__cleanUp(ThreadContext* ctx){
}
}}

