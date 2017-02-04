#include "includes.h"


namespace alinous {namespace btree {





bool BTreeNode::__init_done = __init_static_variables();
bool BTreeNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeNode::BTreeNode(IBTreeKey* key, int numNodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw()  : IObject(ctx), AbstractBTreeNode(numNodes, nullptr, sync, loader, fifoElement, ctx), key(nullptr)
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
void BTreeNode::__construct_impl(IBTreeKey* key, int numNodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
 BTreeNode::~BTreeNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeNode", L"~BTreeNode");
	__e_obj1.add(this->key, this);
	key = nullptr;
	if(!prepare){
		return;
	}
	AbstractBTreeNode::__releaseRegerences(true, ctx);
}
int BTreeNode::nodeSize(ThreadContext* ctx)
{
	int total = this->key->size(ctx);
	total += 1 + 4 + 4 + (this->length * 8) + 8;
	return total;
}
FileStorageEntry* BTreeNode::toFileStorageEntry(FileStorageEntryBuilder* builder, FileStorageEntry* entry, ThreadContext* ctx)
{
	builder->reloadBuffer(nodeSize(ctx), ctx);
	builder->putByte(IBTreeNode::BTREE_TYPE_NODE, ctx);
	this->key->appendToEntry(builder, ctx);
	builder->putInt(this->length, ctx);
	builder->putInt(this->nodeUsed, ctx);
	int maxLoop = this->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		if(this->nodes->get(i) != nullptr)
		{
			builder->putLong(this->nodes->get(i)->filePointer, ctx);
		}
				else 
		{
			builder->putLong((long long)0, ctx);
		}
	}
	return builder->toEntry(entry, this->getFilePointer(ctx), ctx);
}
IBTreeNode* BTreeNode::addLeafNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1653(), ctx));
}
IBTreeKey* BTreeNode::getKey(ThreadContext* ctx) throw() 
{
	return this->key;
}
void BTreeNode::move(IBTreeNode* node, ThreadContext* ctx)
{
	this->nodeHandler->load(ctx);
	this->nodeHandler->putNode(node, false, true, ctx);
}
INodeIterator* BTreeNode::iterator(bool endStart, ThreadContext* ctx)
{
	return (new(ctx) NodeIterator(loader, getFilePointer(ctx), endStart, ctx));
}
char BTreeNode::getNodeType(ThreadContext* ctx) throw() 
{
	return IBTreeNode::BTREE_TYPE_NODE;
}
void BTreeNode::printNode(StringBuffer* buff, int level, ThreadContext* ctx)
{
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1654(), ctx)->append(getKey(ctx)->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1640(), ctx);
	int nextLevel = level + 1;
	int maxLoop = this->nodeUsed;
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeRef* ref = this->nodes->get(i);
		IBTreeNode* node = this->loader->loadBTreeNode(ref->filePointer, ctx);
		node->printNode(buff, nextLevel, ctx);
		node->endUse(ctx);
	}
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1655(), ctx);
}
bool BTreeNode::removeChild(IBTreeKey* key, ThreadContext* ctx)
{
	bool removedKey = false;
	loadChildren(ctx);
	IBTreeNode* deletedNode = this->nodeHandler->removeNode(key, ctx);
	if(deletedNode != nullptr)
	{
		this->loader->deleteBTreeNode(deletedNode, ctx);
		deletedNode->endUse(ctx);
	}
	if(this->nodeUsed == 0)
	{
		return true;
	}
	if(this->key->equals(key, ctx))
	{
		__GC_MV(this, &(this->key), this->nodes->get(this->nodeUsed - 1)->node->getKey(ctx), IBTreeKey);
		removedKey = true;
	}
	return removedKey;
}
bool BTreeNode::isEmpty(ThreadContext* ctx) throw() 
{
	return this->nodeUsed == 0;
}
void BTreeNode::setKey(IBTreeKey* key, ThreadContext* ctx)
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
bool BTreeNode::hasMaxNode(ThreadContext* ctx) throw() 
{
	return false;
}
void BTreeNode::loadChildren(ThreadContext* ctx)
{
	this->nodeHandler->load(ctx);
}
ArrayList<IBTreeValue>* BTreeNode::getValues(ThreadContext* ctx) throw() 
{
	return nullptr;
}
IBTreeNode* BTreeNode::fromFetcher(FileStorageEntryFetcher* fetcher, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx)
{
	IBTreeKey* key = KeyValueFactory::keyFromFetcher(fetcher, ctx);
	int numNodes = fetcher->fetchInt(ctx);
	int nodeUsed = fetcher->fetchInt(ctx);
	BTreeNode* node = (new(ctx) BTreeNode(key, numNodes, sync, loader, fifoElement, ctx));
	node->setNodeUsed(nodeUsed, ctx);
	for(int i = 0; i != numNodes; ++i)
	{
		NodeRef* ref = (new(ctx) NodeRef(fetcher->fetchLong(ctx), ctx));
		node->setNode(ref, i, ctx);
	}
	return node;
}
}}

