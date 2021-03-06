#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/TypedVariableDeclareSource.h"
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"

namespace alinous {namespace compile {namespace analyse {





bool VariableDeclareHolder::__init_done = __init_static_variables();
bool VariableDeclareHolder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariableDeclareHolder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariableDeclareHolder::VariableDeclareHolder(ThreadContext* ctx) throw()  : IObject(ctx), variableDeclares(GCUtils<Stack<SubVariableDeclareHolder> >::ins(this, (new(ctx) Stack<SubVariableDeclareHolder>(ctx)), ctx, __FILEW__, __LINE__, L"")), domDeclare(GCUtils<HashMap<String,DomVariableDeclareSource> >::ins(this, (new(ctx) HashMap<String,DomVariableDeclareSource>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void VariableDeclareHolder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VariableDeclareHolder::~VariableDeclareHolder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariableDeclareHolder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"VariableDeclareHolder", L"~VariableDeclareHolder");
	__e_obj1.add(this->variableDeclares, this);
	variableDeclares = nullptr;
	__e_obj1.add(this->domDeclare, this);
	domDeclare = nullptr;
	if(!prepare){
		return;
	}
}
HashMap<String,DomVariableDeclareSource>* VariableDeclareHolder::getDomDeclare(ThreadContext* ctx) throw() 
{
	return domDeclare;
}
void VariableDeclareHolder::newSubStack(ThreadContext* ctx) throw() 
{
	SubVariableDeclareHolder* holder = (new(ctx) SubVariableDeclareHolder(ctx));
	variableDeclares->push(holder, ctx);
}
void VariableDeclareHolder::endSubStack(ThreadContext* ctx) throw() 
{
	this->variableDeclares->pop(ctx);
}
SubVariableDeclareHolder* VariableDeclareHolder::getCurrentSubStack(ThreadContext* ctx) throw() 
{
	return this->variableDeclares->peek(ctx);
}
void VariableDeclareHolder::addTypeVariableDeclare(FunctionArgumentDefine* argumentDefine, ThreadContext* ctx) throw() 
{
	SubVariableDeclareHolder* sub = this->variableDeclares->peek(ctx);
	sub->addFunctionArgumentDefine(argumentDefine, ctx);
}
void VariableDeclareHolder::addTypeVariableDeclare(TypedVariableDeclare* typedVariableDeclare, ThreadContext* ctx) throw() 
{
	SubVariableDeclareHolder* sub = this->variableDeclares->peek(ctx);
	sub->addTypedVariableDeclare(typedVariableDeclare, ctx);
}
TypedVariableDeclareSource* VariableDeclareHolder::getTypedVariableDeclare(String* name, ThreadContext* ctx) throw() 
{
	TypedVariableDeclareSource* ret = nullptr;
	int maxLoop = this->variableDeclares->size(ctx) - 1;
	for(int i = maxLoop; i != -1; --i)
	{
		SubVariableDeclareHolder* sub = this->variableDeclares->get(i, ctx);
		ret = sub->getTypedVariableDeclareSource(name, ctx);
		if(ret != nullptr)
		{
			return ret;
		}
	}
	return nullptr;
}
void VariableDeclareHolder::__cleanUp(ThreadContext* ctx){
}
}}}

