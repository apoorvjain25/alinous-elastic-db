#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath/NumberValue.h"
#include "alinous.html.xpath/XpathFunction.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"

namespace alinous {namespace html {namespace xpath {namespace match {





bool MatchCandidatesCollection::__init_done = __init_static_variables();
bool MatchCandidatesCollection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MatchCandidatesCollection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MatchCandidatesCollection::MatchCandidatesCollection(ThreadContext* ctx) throw()  : IObject(ctx), candidatesList(GCUtils<ArrayList<MatchCandidate> >::ins(this, (new(ctx) ArrayList<MatchCandidate>(ctx)), ctx, __FILEW__, __LINE__, L"")), domParents(GCUtils<Map<DomNode,ArrayList<MatchCandidate>> >::ins(this, (new(ctx) HashMap<DomNode,ArrayList<MatchCandidate>>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void MatchCandidatesCollection::__construct_impl(ThreadContext* ctx) throw() 
{
}
 MatchCandidatesCollection::~MatchCandidatesCollection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MatchCandidatesCollection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MatchCandidatesCollection", L"~MatchCandidatesCollection");
	__e_obj1.add(this->candidatesList, this);
	candidatesList = nullptr;
	__e_obj1.add(this->domParents, this);
	domParents = nullptr;
	if(!prepare){
		return;
	}
}
MatchCandidate* MatchCandidatesCollection::getFirstCandidate(ThreadContext* ctx) throw() 
{
	if(this->candidatesList->isEmpty(ctx))
	{
		return nullptr;
	}
	return this->candidatesList->get(0, ctx);
}
void MatchCandidatesCollection::addCandidate(MatchCandidate* candidate, ThreadContext* ctx) throw() 
{
	this->candidatesList->add(candidate, ctx);
	DomNode* node = candidate->getCandidateDom(ctx)->getParent(ctx);
	ArrayList<MatchCandidate>* list = this->domParents->get(node, ctx);
	if(list == nullptr)
	{
		list = (new(ctx) ArrayList<MatchCandidate>(ctx));
		this->domParents->put(candidate->getCandidateDom(ctx)->getParent(ctx), list, ctx);
	}
	list->add(candidate, ctx);
}
ArrayList<MatchCandidate>* MatchCandidatesCollection::getCandidatesList(ThreadContext* ctx) throw() 
{
	return candidatesList;
}
MatchCandidatesCollection* MatchCandidatesCollection::filterByIndex(IXpathStatement* indexStmt, DomDocument* document, ThreadContext* ctx)
{
	if(indexStmt == nullptr)
	{
		return this;
	}
	int index = 0;
	if((dynamic_cast<XpathFunction*>(indexStmt) != 0))
	{
		XpathFunction* f = static_cast<XpathFunction*>(indexStmt);
		if(f->getName(ctx)->equals(ConstStr::getCNST_STR_1805(), ctx))
		{
			return filterByLast(ctx);
		}
	}
	IVariableValue* val = indexStmt->getValue(document, document, ctx);
	if(!((dynamic_cast<NumberValue*>(val) != 0)))
	{
		throw (new(ctx) MatchingException(ConstStr::getCNST_STR_1812(), ctx));
	}
	index = (static_cast<NumberValue*>(val))->getValue(ctx) - 1;
	return filterByindex(index, ctx);
}
String* MatchCandidatesCollection::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	bool first = true;
	Iterator<MatchCandidate>* it = this->candidatesList->iterator(ctx);
	while(it->hasNext(ctx))
	{
		MatchCandidate* candidate = it->next(ctx);
		if(first)
		{
			first = false;
		}
				else 
		{
			buff->append(ConstStr::getCNST_STR_1313(), ctx);
		}
		buff->append(candidate->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
MatchCandidatesCollection* MatchCandidatesCollection::filterByindex(int index, ThreadContext* ctx) throw() 
{
	MatchCandidatesCollection* ret = (new(ctx) MatchCandidatesCollection(ctx));
	Iterator<DomNode>* it = this->domParents->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		DomNode* n = it->next(ctx);
		ArrayList<MatchCandidate>* list = this->domParents->get(n, ctx);
		if(list->size(ctx) - 1 < index)
		{
			continue;
		}
		ret->addCandidate(list->get(index, ctx), ctx);
	}
	return ret;
}
MatchCandidatesCollection* MatchCandidatesCollection::filterByLast(ThreadContext* ctx) throw() 
{
	MatchCandidatesCollection* ret = (new(ctx) MatchCandidatesCollection(ctx));
	Iterator<DomNode>* it = this->domParents->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		DomNode* n = it->next(ctx);
		ArrayList<MatchCandidate>* list = this->domParents->get(n, ctx);
		int index = list->size(ctx) - 1;
		ret->addCandidate(list->get(index, ctx), ctx);
	}
	return ret;
}
void MatchCandidatesCollection::__cleanUp(ThreadContext* ctx){
}
}}}}

