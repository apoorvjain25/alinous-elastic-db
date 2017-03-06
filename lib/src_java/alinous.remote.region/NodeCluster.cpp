#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.region/NodeReference.h"
#include "alinous.remote.region/NodeTableReference.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.system.config.remote/Region.h"
#include "alinous.remote.monitor/NodeInfo.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.region/NodeCluster.h"
#include "alinous.remote.region/NodeTableClaster.h"
#include "alinous.remote.region/NodeRegionSchema.h"
#include "alinous.remote.region/RegionShardPart.h"
#include "alinous.remote.region/RegionShardTable.h"
#include "alinous.remote.region/NodeReferenceManager.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.region/NodeRegionResponceAction.h"
#include "alinous.remote.region/NodeRegionResponceActionFactory.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.region/RegionInsertExecutor.h"
#include "alinous.remote.region/RegionTpcExecutorPool.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.remote.region/RegionTableLockManager.h"

namespace alinous {namespace remote {namespace region {





bool NodeCluster::__init_done = __init_static_variables();
bool NodeCluster::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeCluster", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeCluster::NodeCluster(ThreadContext* ctx) throw()  : IObject(ctx), nodes(GCUtils<List<NodeReference> >::ins(this, (new(ctx) ArrayList<NodeReference>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void NodeCluster::__construct_impl(ThreadContext* ctx) throw() 
{
}
 NodeCluster::~NodeCluster() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeCluster::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeCluster", L"~NodeCluster");
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	if(!prepare){
		return;
	}
}
SchemasStructureInfoData* NodeCluster::getSchemeInfo(String* region, ThreadContext* ctx)
{
	SchemasStructureInfoData* last = nullptr;
	int maxLoop = this->nodes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeReference* noderef = this->nodes->get(i, ctx);
		SchemasStructureInfoData* data = noderef->getSchemeInfo(region, ctx);
		if(last == nullptr)
		{
			last = data;
		}
				else 
		{
			last->join(data, ctx);
		}
	}
	return last;
}
void NodeCluster::update(RegionNodeInfo* refinfo, ThreadContext* ctx) throw() 
{
	List<NodeInfo>* list = refinfo->getNodes(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeInfo* info = list->get(i, ctx);
		NodeReference* ref = getNode(info->getHost(ctx), info->getPort(ctx), info->isIpv6(ctx), ctx);
		if(ref == nullptr)
		{
			ref = (new(ctx) NodeReference(info->getHost(ctx), info->getPort(ctx), info->isIpv6(ctx), ctx));
			ref->initConnectionPool(ctx);
			this->nodes->add(ref, ctx);
		}
	}
	List<NodeReference>* dellist = (new(ctx) ArrayList<NodeReference>(ctx));
	maxLoop = this->nodes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeReference* ref = this->nodes->get(i, ctx);
		if(!refinfo->containsNode(ref->getHost(ctx), ref->getPort(ctx), ref->isIpv6(ctx), ctx))
		{
			dellist->add(ref, ctx);
		}
	}
	maxLoop = dellist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeReference* ref = dellist->get(i, ctx);
		this->nodes->remove(ref, ctx);
		ref->dispose(ctx);
	}
}
NodeReference* NodeCluster::getNode(String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	int maxLoop = this->nodes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeReference* ref = this->nodes->get(i, ctx);
		if(ref->getHost(ctx)->equals(host, ctx) && ref->getPort(ctx) == port && ref->isIpv6(ctx) == ipv6)
		{
			return ref;
		}
	}
	return nullptr;
}
void NodeCluster::addNode(NodeReference* nodeRef, ThreadContext* ctx) throw() 
{
	this->nodes->add(nodeRef, ctx);
}
List<NodeReference>* NodeCluster::getNodes(ThreadContext* ctx) throw() 
{
	return nodes;
}
void NodeCluster::dispose(ThreadContext* ctx) throw() 
{
	int maxLoop = this->nodes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeReference* node = this->nodes->get(i, ctx);
		node->dispose(ctx);
	}
}
void NodeCluster::__cleanUp(ThreadContext* ctx){
}
}}}

