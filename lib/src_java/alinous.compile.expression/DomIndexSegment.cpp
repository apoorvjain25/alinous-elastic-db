#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool DomIndexSegment::__init_done = __init_static_variables();
bool DomIndexSegment::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomIndexSegment", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomIndexSegment::DomIndexSegment(IExpression* index, ThreadContext* ctx) throw()  : IObject(ctx), IDomSegment(ctx), index(nullptr), segmentVariableType(IDomVariable::TYPE_DOM)
{
	__GC_MV(this, &(this->index), index, IExpression);
}
void DomIndexSegment::__construct_impl(IExpression* index, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->index), index, IExpression);
}
 DomIndexSegment::~DomIndexSegment() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomIndexSegment::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomIndexSegment", L"~DomIndexSegment");
	__e_obj1.add(this->index, this);
	index = nullptr;
	if(!prepare){
		return;
	}
	IDomSegment::__releaseRegerences(true, ctx);
}
String* DomIndexSegment::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(ConstStr::getCNST_STR_977(), ctx)->append(ConstStr::getCNST_STR_564(), ctx);
	return buff->toString(ctx);
}
IExpression* DomIndexSegment::getIndex(ThreadContext* ctx) throw() 
{
	return this->index;
}
void DomIndexSegment::setIndex(IExpression* index, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->index), index, IExpression);
}
int DomIndexSegment::getDomSegmentType(ThreadContext* ctx) throw() 
{
	return IDomSegment::TYPE_INDEX;
}
String* DomIndexSegment::getName(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
int DomIndexSegment::getSegmentVariableType(ThreadContext* ctx) throw() 
{
	return this->segmentVariableType;
}
void DomIndexSegment::setSegmentVariableType(int segmentVariableType, ThreadContext* ctx) throw() 
{
	this->segmentVariableType = segmentVariableType;
}
bool DomIndexSegment::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
int DomIndexSegment::getLine(ThreadContext* ctx) throw() 
{
	return IDomSegment::getLine(ctx);
}
int DomIndexSegment::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDomSegment::getStartPosition(ctx);
}
int DomIndexSegment::getEndLine(ThreadContext* ctx) throw() 
{
	return IDomSegment::getEndLine(ctx);
}
int DomIndexSegment::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDomSegment::getEndPosition(ctx);
}
AbstractSrcElement* DomIndexSegment::getParent(ThreadContext* ctx) throw() 
{
	return IDomSegment::getParent(ctx);
}
void DomIndexSegment::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDomSegment::setParent(parent, ctx);
}
void DomIndexSegment::position(Token* t2, AbstractSrcElement* segment, ThreadContext* ctx) throw() 
{
	IDomSegment::position(t2, segment, ctx);
}
void DomIndexSegment::position(Token* start, Token* end, ThreadContext* ctx) throw() 
{
	IDomSegment::position(start, end, ctx);
}
}}}
