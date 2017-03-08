#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"
#include "org.alinous.charset/ISO_8859_4.h"

namespace org {namespace alinous {namespace charset {





bool ISO_8859_4::__init_done = __init_static_variables();
bool ISO_8859_4::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ISO_8859_4", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ISO_8859_4::ISO_8859_4(ThreadContext* ctx) throw()  : IObject(ctx), CharsetConverter(ctx), decoder(nullptr), encoder(nullptr)
{
	__GC_MV(this, &(decoder), (new(ctx) ISO_8859_4::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) ISO_8859_4::Encoder(ctx)), CharsetEncoder);
}
void ISO_8859_4::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(decoder), (new(ctx) ISO_8859_4::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) ISO_8859_4::Encoder(ctx)), CharsetEncoder);
}
 ISO_8859_4::~ISO_8859_4() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ISO_8859_4::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ISO_8859_4", L"~ISO_8859_4");
	__e_obj1.add(this->decoder, this);
	decoder = nullptr;
	__e_obj1.add(this->encoder, this);
	encoder = nullptr;
	if(!prepare){
		return;
	}
}
CharsetDecoder* ISO_8859_4::newDecoder(ThreadContext* ctx) throw() 
{
	return decoder;
}
CharsetEncoder* ISO_8859_4::newEncoder(ThreadContext* ctx) throw() 
{
	return encoder;
}
bool ISO_8859_4::contains(String* cs, ThreadContext* ctx) throw() 
{
	return cs->equalsIgnoreCase(ConstStr::getCNST_STR_913(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_939(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_892(), ctx);
}
void ISO_8859_4::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





const StaticArrayObjectPrimitive<wchar_t> ISO_8859_4::Decoder::__arr = {0x0104, 0x0138, 0x0156, 0x00A4, 0x0128, 0x013B, 0x00A7, 0x00A8, 0x0160, 0x0112, 0x0122, 0x0166, 0x00AD, 0x017D, 0x00AF, 0x00B0, 0x0105, 0x02DB, 0x0157, 0x00B4, 0x0129, 0x013C, 0x02C7, 0x00B8, 0x0161, 0x0113, 0x0123, 0x0167, 0x014A, 0x017E, 0x014B, 0x0100, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x012E, 0x010C, 0x00C9, 0x0118, 0x00CB, 0x0116, 0x00CD, 0x00CE, 0x012A, 0x0110, 0x0145, 0x014C, 0x0136, 0x00D4, 0x00D5, 0x00D6, 0x00D7, 0x00D8, 0x0172, 0x00DA, 0x00DB, 0x00DC, 0x0168, 0x016A, 0x00DF, 0x0101, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x012F, 0x010D, 0x00E9, 0x0119, 0x00EB, 0x0117, 0x00ED, 0x00EE, 0x012B, 0x0111, 0x0146, 0x014D, 0x0137, 0x00F4, 0x00F5, 0x00F6, 0x00F7, 0x00F8, 0x0173, 0x00FA, 0x00FB, 0x00FC, 0x0169, 0x016B, 0x02D9};
IArrayObjectPrimitive<wchar_t>* ISO_8859_4::Decoder::arr = (IArrayObjectPrimitive<wchar_t>*)const_cast<StaticArrayObjectPrimitive<wchar_t>*>(&__arr);
bool ISO_8859_4::Decoder::__init_done = __init_static_variables();
bool ISO_8859_4::Decoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ISO_8859_4::Decoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ISO_8859_4::Decoder::Decoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetDecoder(ctx)
{
}
void ISO_8859_4::Decoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ISO_8859_4::Decoder::~Decoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ISO_8859_4::Decoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
CoderResult* ISO_8859_4::Decoder::decodeLoop(ByteBuffer* bb, CharBuffer* cb, ThreadContext* ctx) throw() 
{
	int cbRemaining = cb->remaining(ctx);
	{
		if(bb->hasArray(ctx) && cb->hasArray(ctx))
		{
			int rem = bb->remaining(ctx);
			rem = cbRemaining >= rem ? rem : cbRemaining;
			IArrayObjectPrimitive<char>* bArr = bb->array(ctx);
			IArrayObjectPrimitive<wchar_t>* cArr = cb->array(ctx);
			int bStart = bb->position(ctx);
			int cStart = cb->position(ctx);
			int i = 0;
			for(i = bStart; i < bStart + rem; i ++ )
			{
				int in = ((int)bArr->get(i));
				if(in < 0 && in >= -95)
				{
					int index = ((int)in) + 95;
					cArr->set(((wchar_t)arr->get(index)),cStart++, ctx);
				}
								else 
				{
					cArr->set(((wchar_t)(in & 0xFF)),cStart++, ctx);
				}
			}
			bb->position(i, ctx);
			cb->position(cStart, ctx);
			if(rem == cbRemaining && bb->hasRemaining(ctx))
			{
				return CoderResult::OVERFLOW;
			}
		}
				else 
		{
			while(bb->hasRemaining(ctx))
			{
				if(cbRemaining == 0)
				{
					return CoderResult::OVERFLOW;
				}
				int in = ((int)bb->get(ctx));
				if(in < 0 && in >= -95)
				{
					int index = ((int)in) + 95;
					cb->put(arr->get(index), ctx);
				}
								else 
				{
					cb->put(((wchar_t)(in & 0xFF)), ctx);
				}
				cbRemaining -- ;
			}
		}
	}
	return CoderResult::UNDERFLOW;
}
void ISO_8859_4::Decoder::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





const StaticArrayObjectPrimitive<wchar_t> ISO_8859_4::Encoder::__arr = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0x00, 0x00, 0x00, 0xA4, 0x00, 0x00, 0xA7, 0xA8, 0x00, 0x00, 0x00, 0x00, 0xAD, 0x00, 0xAF, 0xB0, 0x00, 0x00, 0x00, 0xB4, 0x00, 0x00, 0x00, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0x00, 0x00, 0xC9, 0x00, 0xCB, 0x00, 0xCD, 0xCE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0x00, 0xDA, 0xDB, 0xDC, 0x00, 0x00, 0xDF, 0x00, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0x00, 0x00, 0xE9, 0x00, 0xEB, 0x00, 0xED, 0xEE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0x00, 0xFA, 0xFB, 0xFC, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x00, 0x00, 0xA1, 0xB1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0xE8, 0x00, 0x00, 0xD0, 0xF0, 0xAA, 0xBA, 0x00, 0x00, 0xCC, 0xEC, 0xCA, 0xEA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAB, 0xBB, 0x00, 0x00, 0x00, 0x00, 0xA5, 0xB5, 0xCF, 0xEF, 0x00, 0x00, 0xC7, 0xE7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD3, 0xF3, 0xA2, 0x00, 0x00, 0xA6, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD1, 0xF1, 0x00, 0x00, 0x00, 0xBD, 0xBF, 0xD2, 0xF2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA3, 0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA9, 0xB9, 0x00, 0x00, 0x00, 0x00, 0xAC, 0xBC, 0xDD, 0xFD, 0xDE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD9, 0xF9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAE, 0xBE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xB2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
IArrayObjectPrimitive<wchar_t>* ISO_8859_4::Encoder::arr = (IArrayObjectPrimitive<wchar_t>*)const_cast<StaticArrayObjectPrimitive<wchar_t>*>(&__arr);
const StaticArrayObjectPrimitive<int> ISO_8859_4::Encoder::__encodeIndex = {0, 1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
IArrayObjectPrimitive<int>* ISO_8859_4::Encoder::encodeIndex = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__encodeIndex);
bool ISO_8859_4::Encoder::__init_done = __init_static_variables();
bool ISO_8859_4::Encoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ISO_8859_4::Encoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ISO_8859_4::Encoder::Encoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetEncoder(ctx)
{
}
void ISO_8859_4::Encoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ISO_8859_4::Encoder::~Encoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ISO_8859_4::Encoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
CoderResult* ISO_8859_4::Encoder::encodeLoop(CharBuffer* cb, ByteBuffer* bb, ThreadContext* ctx) throw() 
{
	int bbRemaining = bb->remaining(ctx);
	{
		if(bb->hasArray(ctx) && cb->hasArray(ctx))
		{
			IArrayObjectPrimitive<char>* byteArr = bb->array(ctx);
			IArrayObjectPrimitive<wchar_t>* charArr = cb->array(ctx);
			int rem = cb->remaining(ctx);
			int byteArrStart = bb->position(ctx);
			rem = bbRemaining <= rem ? bbRemaining : rem;
			int x = 0;
			for(x = cb->position(ctx); x < cb->position(ctx) + rem; x ++ )
			{
				wchar_t c = charArr->get(x);
				if(c > ((wchar_t)0x02DB))
				{
					if(c >= (wchar_t)0xD800 && c <= (wchar_t)0xDFFF)
					{
						if(x + 1 < cb->limit(ctx))
						{
							wchar_t c1 = charArr->get(x + 1);
							if(c1 >= (wchar_t)0xD800 && c1 <= (wchar_t)0xDFFF)
							{
								cb->position(x, ctx);
								bb->position(byteArrStart, ctx);
								return CoderResult::unmappableForLength(2, ctx);
							}
						}
												else 
						{
							cb->position(x, ctx);
							bb->position(byteArrStart, ctx);
							return CoderResult::UNDERFLOW;
						}
						cb->position(x, ctx);
						bb->position(byteArrStart, ctx);
						return CoderResult::malformedForLength(1, ctx);
					}
					cb->position(x, ctx);
					bb->position(byteArrStart, ctx);
					return CoderResult::unmappableForLength(1, ctx);
				}
								else 
				{
					if(c < (wchar_t)0xA1)
					{
						byteArr->set(((char)c),byteArrStart++, ctx);
					}
										else 
					{
						int index = ((int)c) >> 8;
						index = encodeIndex->get(index);
						if(index < 0)
						{
							cb->position(x, ctx);
							bb->position(byteArrStart, ctx);
							return CoderResult::unmappableForLength(1, ctx);
						}
						index <<= 8;
						index += ((int)c) & 0xFF;
						if(((char)arr->get(index)) != (char)0)
						{
							byteArr->set(((char)arr->get(index)),byteArrStart++, ctx);
						}
												else 
						{
							cb->position(x, ctx);
							bb->position(byteArrStart, ctx);
							return CoderResult::unmappableForLength(1, ctx);
						}
					}
				}
			}
			cb->position(x, ctx);
			bb->position(byteArrStart, ctx);
			if(rem == bbRemaining && cb->hasRemaining(ctx))
			{
				return CoderResult::OVERFLOW;
			}
		}
				else 
		{
			while(cb->hasRemaining(ctx))
			{
				if(bbRemaining == 0)
				{
					return CoderResult::OVERFLOW;
				}
				wchar_t c = cb->get(ctx);
				if(c > ((wchar_t)0x02DB))
				{
					if(c >= (wchar_t)0xD800 && c <= (wchar_t)0xDFFF)
					{
						if(cb->hasRemaining(ctx))
						{
							wchar_t c1 = cb->get(ctx);
							if(c1 >= (wchar_t)0xD800 && c1 <= (wchar_t)0xDFFF)
							{
								cb->position(cb->position(ctx) - 2, ctx);
								return CoderResult::unmappableForLength(2, ctx);
							}
														else 
							{
								cb->position(cb->position(ctx) - 1, ctx);
							}
						}
												else 
						{
							cb->position(cb->position(ctx) - 1, ctx);
							return CoderResult::UNDERFLOW;
						}
						cb->position(cb->position(ctx) - 1, ctx);
						return CoderResult::malformedForLength(1, ctx);
					}
					cb->position(cb->position(ctx) - 1, ctx);
					return CoderResult::unmappableForLength(1, ctx);
				}
								else 
				{
					if(c < (wchar_t)0xA1)
					{
						bb->put(((char)c), ctx);
					}
										else 
					{
						int index = ((int)c) >> 8;
						index = encodeIndex->get(index);
						if(index < 0)
						{
							cb->position(cb->position(ctx) - 1, ctx);
							return CoderResult::unmappableForLength(1, ctx);
						}
						index <<= 8;
						index += ((int)c) & 0xFF;
						if(((char)arr->get(index)) != (char)0)
						{
							bb->put(((char)arr->get(index)), ctx);
						}
												else 
						{
							cb->position(cb->position(ctx) - 1, ctx);
							return CoderResult::unmappableForLength(1, ctx);
						}
					}
					bbRemaining -- ;
				}
			}
		}
	}
	return CoderResult::UNDERFLOW;
}
void ISO_8859_4::Encoder::__cleanUp(ThreadContext* ctx){
}
}}}

