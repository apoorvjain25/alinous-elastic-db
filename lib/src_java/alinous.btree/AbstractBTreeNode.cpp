#include "include/global.h"


#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.lock/LockObject.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
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
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree.scan/AbstractNodeIterator.h"
#include "alinous.btree.scan/NodeIterator.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree.scan/MaxNodeIterator.h"
#include "alinous.btree/BTreeMaxNode.h"
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





bool AbstractBTreeNode::__init_done = __init_static_variables();
bool AbstractBTreeNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractBTreeNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractBTreeNode::AbstractBTreeNode(int numNodes, IArrayObject<NodeRef>* nodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw()  : IObject(ctx), AbstractNode(sync, loader, fifoElement, ctx), length(0), nodeUsed(0), nodes(nullptr), nodeHandler(nullptr)
{
	this->length = numNodes;
	if(nodes == nullptr)
	{
		__GC_MV(this, &(this->nodes), ArrayAllocator<NodeRef>::allocate(ctx, numNodes + 2), IArrayObject<NodeRef>);
	}
		else 
	{
		__GC_MV(this, &(this->nodes), nodes, IArrayObject<NodeRef>);
	}
	__GC_MV(this, &(this->loader), loader, BTreeNodeLoader);
	__GC_MV(this, &(this->nodeHandler), (new(ctx) BTreeNodeHandler(this->nodes, this->nodeUsed, this->length, loader, this, ctx)), BTreeNodeHandler);
}
void AbstractBTreeNode::__construct_impl(int numNodes, IArrayObject<NodeRef>* nodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	this->length = numNodes;
	if(nodes == nullptr)
	{
		__GC_MV(this, &(this->nodes), ArrayAllocator<NodeRef>::allocate(ctx, numNodes + 2), IArrayObject<NodeRef>);
	}
		else 
	{
		__GC_MV(this, &(this->nodes), nodes, IArrayObject<NodeRef>);
	}
	__GC_MV(this, &(this->loader), loader, BTreeNodeLoader);
	__GC_MV(this, &(this->nodeHandler), (new(ctx) BTreeNodeHandler(this->nodes, this->nodeUsed, this->length, loader, this, ctx)), BTreeNodeHandler);
}
 AbstractBTreeNode::~AbstractBTreeNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractBTreeNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractBTreeNode", L"~AbstractBTreeNode");
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	__e_obj1.add(this->nodeHandler, this);
	nodeHandler = nullptr;
	if(!prepare){
		return;
	}
	AbstractNode::__releaseRegerences(true, ctx);
}
void AbstractBTreeNode::setNode(NodeRef* ref, int index, ThreadContext* ctx) throw() 
{
	this->nodes->set(ref,index, ctx);
}
bool AbstractBTreeNode::isHasLeaf(ThreadContext* ctx) throw() 
{
	return false;
}
IBTreeNode* AbstractBTreeNode::getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx)
{
	this->nodeHandler->load(ctx);
	int pos = this->nodeHandler->nodeToGoDown(key, ctx);
	IBTreeNode* node = this->nodes->get(pos)->node;
	return node;
}
int AbstractBTreeNode::getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx)
{
	this->nodeHandler->load(ctx);
	int pos = this->nodeHandler->nodeToGoDown(key, ctx);
	return pos;
}
NodeRef* AbstractBTreeNode::get(int index, ThreadContext* ctx) throw() 
{
	return this->nodes->get(index);
}
int AbstractBTreeNode::getNodeUsed(ThreadContext* ctx) throw() 
{
	return nodeUsed;
}
void AbstractBTreeNode::setNodeUsed(int nodeUsed, ThreadContext* ctx) throw() 
{
	this->nodeUsed = nodeUsed;
	this->nodeHandler->setNodeUsed(nodeUsed, ctx);
}
bool AbstractBTreeNode::isFull(ThreadContext* ctx) throw() 
{
	return this->nodeUsed == this->length;
}
IBTreeNode* AbstractBTreeNode::split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx)
{
	this->nodeHandler->load(ctx);
	this->nodeHandler->putNode(newNode, true, false, ctx);
	int mid = this->length / 2;
	IBTreeKey* key = this->nodes->get(mid - 1)->node->getKey(ctx);
	BTreeNode* smaller = loader->newNode(key, this->length, ctx);
	for(int i = 0; i != mid; i ++ )
	{
		smaller->move(this->nodes->get(i)->node, ctx);
	}
	smaller->setNodeUsed(mid, ctx);
	this->nodeHandler->removeNode(0, mid, ctx);
	loader->saveBTreeNode(static_cast<IBTreeNode*>(this), ctx);
	loader->saveBTreeNode(smaller, ctx);
	return smaller;
}
void AbstractBTreeNode::addNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	this->nodeHandler->load(ctx);
	this->nodeHandler->putNode(newNode, false, false, ctx);
}
void AbstractBTreeNode::endUse(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->sync, ctx);
		doEndUseWithoutLock(ctx);
	}
}
void AbstractBTreeNode::unloadChildren(ThreadContext* ctx)
{
	this->nodeHandler->unload(ctx);
}
void AbstractBTreeNode::__cleanUp(ThreadContext* ctx){
}
}}

