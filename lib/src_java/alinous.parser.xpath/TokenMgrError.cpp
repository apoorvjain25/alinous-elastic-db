#include "include/global.h"


#include "alinous.parser.xpath/TokenMgrError.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/XpathReference.h"
#include "alinous.html.xpath/Xpath2Compare.h"
#include "alinous.html.xpath/XpathNumber.h"
#include "alinous.html.xpath/XpathFunctionArgument.h"
#include "alinous.html.xpath/XpathFunction.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath/AbstractContainerStatement.h"
#include "alinous.html.xpath/XpathAndStatement.h"
#include "alinous.html.xpath/XpathNotStatement.h"
#include "alinous.html.xpath/XpathOrStatement.h"
#include "alinous.html.xpath/XpathString.h"
#include "alinous.parser.xpath/Token.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.parser.xpath/JavaCharStream.h"
#include "alinous.parser.xpath/AlinousXpathParserConstants.h"
#include "alinous.parser.xpath/AlinousXpathParserTokenManager.h"
#include "alinous.parser.xpath/AlinousXpathParser.h"
#include "alinous.compile/JavaCharStream.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/ParseException.h"

namespace alinous {namespace parser {namespace xpath {





constexpr const long long TokenMgrError::serialVersionUID;
constexpr const int TokenMgrError::LEXICAL_ERROR;
constexpr const int TokenMgrError::STATIC_LEXER_ERROR;
constexpr const int TokenMgrError::INVALID_LEXICAL_STATE;
constexpr const int TokenMgrError::LOOP_DETECTED;
bool TokenMgrError::__init_done = __init_static_variables();
bool TokenMgrError::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TokenMgrError", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TokenMgrError::TokenMgrError(ThreadContext* ctx) throw()  : IObject(ctx), Error(ctx), errorCode(0)
{
}
void TokenMgrError::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TokenMgrError::TokenMgrError(String* message, int reason, ThreadContext* ctx) throw()  : IObject(ctx), Error(message, ctx), errorCode(0)
{
	errorCode = reason;
}
void TokenMgrError::__construct_impl(String* message, int reason, ThreadContext* ctx) throw() 
{
	errorCode = reason;
}
 TokenMgrError::TokenMgrError(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, int reason, ThreadContext* ctx) throw()  : IObject(ctx), Error(ctx), errorCode(0)
{
	__construct_impl(LexicalError(EOFSeen, lexState, errorLine, errorColumn, errorAfter, curChar, ctx), reason, ctx);
}
void TokenMgrError::__construct_impl(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, int reason, ThreadContext* ctx) throw() 
{
	__construct_impl(LexicalError(EOFSeen, lexState, errorLine, errorColumn, errorAfter, curChar, ctx), reason, ctx);
}
 TokenMgrError::~TokenMgrError() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TokenMgrError::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TokenMgrError", L"~TokenMgrError");
	if(!prepare){
		return;
	}
	Error::__releaseRegerences(true, ctx);
}
String* TokenMgrError::getMessage(ThreadContext* ctx) throw() 
{
	return Error::getMessage(ctx);
}
String* TokenMgrError::addEscapes(String* str, ThreadContext* ctx) throw() 
{
	StringBuffer* retval = (new(ctx) StringBuffer(ctx));
	wchar_t ch = 0;
	for(int i = 0; i < str->length(ctx); i ++ )
	{
		switch(str->charAt(i, ctx)) {
		case 0:
			continue;
		case L'\b':
			retval->append(ConstStr::getCNST_STR_86(), ctx);
			continue;
		case L'\t':
			retval->append(ConstStr::getCNST_STR_125(), ctx);
			continue;
		case L'\n':
			retval->append(ConstStr::getCNST_STR_126(), ctx);
			continue;
		case L'\f':
			retval->append(ConstStr::getCNST_STR_128(), ctx);
			continue;
		case L'\r':
			retval->append(ConstStr::getCNST_STR_127(), ctx);
			continue;
		case L'\"':
			retval->append(ConstStr::getCNST_STR_123(), ctx);
			continue;
		case L'\'':
			retval->append(ConstStr::getCNST_STR_1315(), ctx);
			continue;
		case L'\\':
			retval->append(ConstStr::getCNST_STR_124(), ctx);
			continue;
		default:
			ch = str->charAt(i, ctx);
			if((ch) < (wchar_t)0x20 || ch > (wchar_t)0x7e)
			{
				String* s = ConstStr::getCNST_STR_384()->clone(ctx)->append(Integer::toString((int)ch, 16, ctx), ctx);
				retval->append(ConstStr::getCNST_STR_1316()->clone(ctx)->append(s->substring(s->length(ctx) - 4, s->length(ctx), ctx), ctx), ctx);
			}
						else 
			{
				retval->append(ch, ctx);
			}
			continue;
			break;
		}
	}
	return retval->toString(ctx);
}
String* TokenMgrError::LexicalError(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, ThreadContext* ctx) throw() 
{
	return (ConstStr::getCNST_STR_1317()->clone(ctx)->append(errorLine, ctx)->append(ConstStr::getCNST_STR_1318(), ctx)->append(errorColumn, ctx)->append(ConstStr::getCNST_STR_1319(), ctx)->append((EOFSeen ? ConstStr::getCNST_STR_1320() : (ConstStr::getCNST_STR_1321()->clone(ctx)->append(addEscapes(String::valueOf(curChar, ctx), ctx), ctx)->append(ConstStr::getCNST_STR_1321(), ctx))->clone(ctx)->append(ConstStr::getCNST_STR_887(), ctx)->append(((int)curChar), ctx)->append(ConstStr::getCNST_STR_1322(), ctx)), ctx)->append(ConstStr::getCNST_STR_1323(), ctx)->append(addEscapes(errorAfter, ctx), ctx)->append(ConstStr::getCNST_STR_1321(), ctx));
}
void TokenMgrError::__cleanUp(ThreadContext* ctx){
}
}}}

