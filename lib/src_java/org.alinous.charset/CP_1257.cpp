#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"
#include "org.alinous.charset/UTF_16.h"
#include "org.alinous.charset/UTF_16BE.h"
#include "org.alinous.charset/CP_1254.h"
#include "org.alinous.charset/ISO_8859_7.h"
#include "org.alinous.charset/ISO_8859_5.h"
#include "org.alinous.charset/US_ASCII.h"
#include "org.alinous.charset/CP_1250.h"
#include "org.alinous.charset/CP_1251.h"
#include "org.alinous.charset/CP_1252.h"
#include "org.alinous.charset/CP_1253.h"
#include "org.alinous.charset/CP_1257.h"
#include "org.alinous.charset/IBM866.h"
#include "org.alinous.charset/ISO_8859_1.h"
#include "org.alinous.charset/ISO_8859_2.h"
#include "org.alinous.charset/ISO_8859_4.h"
#include "org.alinous.charset/ISO_8859_9.h"
#include "org.alinous.charset/ISO_8859_13.h"
#include "org.alinous.charset/ISO_8859_15.h"
#include "org.alinous.charset/KOI8_R.h"
#include "org.alinous.charset/UTF_16LE.h"
#include "org.alinous.charset/UTF_8.h"
#include "org.alinous.charset/CharsetManager.h"

namespace org {namespace alinous {namespace charset {





bool CP_1257::__init_done = __init_static_variables();
bool CP_1257::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CP_1257", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CP_1257::CP_1257(ThreadContext* ctx) throw()  : IObject(ctx), CharsetConverter(ctx), decoder(nullptr), encoder(nullptr)
{
	__GC_MV(this, &(decoder), (new(ctx) CP_1257::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) CP_1257::Encoder(ctx)), CharsetEncoder);
}
void CP_1257::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(decoder), (new(ctx) CP_1257::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) CP_1257::Encoder(ctx)), CharsetEncoder);
}
 CP_1257::~CP_1257() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CP_1257::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CP_1257", L"~CP_1257");
	__e_obj1.add(this->decoder, this);
	decoder = nullptr;
	__e_obj1.add(this->encoder, this);
	encoder = nullptr;
	if(!prepare){
		return;
	}
}
CharsetDecoder* CP_1257::newDecoder(ThreadContext* ctx) throw() 
{
	return decoder;
}
CharsetEncoder* CP_1257::newEncoder(ThreadContext* ctx) throw() 
{
	return encoder;
}
bool CP_1257::contains(String* cs, ThreadContext* ctx) throw() 
{
	return cs->equalsIgnoreCase(ConstStr::getCNST_STR_913(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_892(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_899(), ctx);
}
void CP_1257::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





const StaticArrayObjectPrimitive<wchar_t> CP_1257::Decoder::__arr = {0x20AC, 0x0081, 0x201A, 0x0083, 0x201E, 0x2026, 0x2020, 0x2021, 0x0088, 0x2030, 0x008A, 0x2039, 0x008C, 0x00A8, 0x02C7, 0x00B8, 0x0090, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014, 0x0098, 0x2122, 0x009A, 0x203A, 0x009C, 0x00AF, 0x02DB, 0x009F, 0x00A0, 0x0000, 0x00A2, 0x00A3, 0x00A4, 0x0000, 0x00A6, 0x00A7, 0x00D8, 0x00A9, 0x0156, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00C6, 0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7, 0x00F8, 0x00B9, 0x0157, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00E6, 0x0104, 0x012E, 0x0100, 0x0106, 0x00C4, 0x00C5, 0x0118, 0x0112, 0x010C, 0x00C9, 0x0179, 0x0116, 0x0122, 0x0136, 0x012A, 0x013B, 0x0160, 0x0143, 0x0145, 0x00D3, 0x014C, 0x00D5, 0x00D6, 0x00D7, 0x0172, 0x0141, 0x015A, 0x016A, 0x00DC, 0x017B, 0x017D, 0x00DF, 0x0105, 0x012F, 0x0101, 0x0107, 0x00E4, 0x00E5, 0x0119, 0x0113, 0x010D, 0x00E9, 0x017A, 0x0117, 0x0123, 0x0137, 0x012B, 0x013C, 0x0161, 0x0144, 0x0146, 0x00F3, 0x014D, 0x00F5, 0x00F6, 0x00F7, 0x0173, 0x0142, 0x015B, 0x016B, 0x00FC, 0x017C, 0x017E, 0x02D9};
IArrayObjectPrimitive<wchar_t>* CP_1257::Decoder::arr = (IArrayObjectPrimitive<wchar_t>*)const_cast<StaticArrayObjectPrimitive<wchar_t>*>(&__arr);
bool CP_1257::Decoder::__init_done = __init_static_variables();
bool CP_1257::Decoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CP_1257::Decoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CP_1257::Decoder::Decoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetDecoder(ctx)
{
}
void CP_1257::Decoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CP_1257::Decoder::~Decoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CP_1257::Decoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
CoderResult* CP_1257::Decoder::decodeLoop(ByteBuffer* bb, CharBuffer* cb, ThreadContext* ctx) throw() 
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
				if(in < 0 && in >= -128)
				{
					int index = ((int)in) + 128;
					if(arr->get(index) != (wchar_t)0x0000)
					{
						cArr->set(((wchar_t)arr->get(index)),cStart++, ctx);
					}
										else 
					{
						bb->position(i, ctx);
						cb->position(cStart, ctx);
						return CoderResult::unmappableForLength(1, ctx);
					}
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
				if(in < 0 && in >= -128)
				{
					int index = ((int)in) + 128;
					if(arr->get(index) != (wchar_t)0x0000)
					{
						cb->put(arr->get(index), ctx);
					}
										else 
					{
						bb->position(bb->position(ctx) - 1, ctx);
						return CoderResult::unmappableForLength(1, ctx);
					}
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
void CP_1257::Decoder::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





const StaticArrayObjectPrimitive<wchar_t> CP_1257::Encoder::__arr = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x00, 0x81, 0x00, 0x83, 0x00, 0x00, 0x00, 0x00, 0x88, 0x00, 0x8A, 0x00, 0x8C, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x00, 0x9A, 0x00, 0x9C, 0x00, 0x00, 0x9F, 0xA0, 0x00, 0xA2, 0xA3, 0xA4, 0x00, 0xA6, 0xA7, 0x8D, 0xA9, 0x00, 0xAB, 0xAC, 0xAD, 0xAE, 0x9D, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0x8F, 0xB9, 0x00, 0xBB, 0xBC, 0xBD, 0xBE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC4, 0xC5, 0xAF, 0x00, 0x00, 0xC9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD3, 0x00, 0xD5, 0xD6, 0xD7, 0xA8, 0x00, 0x00, 0x00, 0xDC, 0x00, 0x00, 0xDF, 0x00, 0x00, 0x00, 0x00, 0xE4, 0xE5, 0xBF, 0x00, 0x00, 0xE9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF3, 0x00, 0xF5, 0xF6, 0xF7, 0xB8, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0xC2, 0xE2, 0x00, 0x00, 0xC0, 0xE0, 0xC3, 0xE3, 0x00, 0x00, 0x00, 0x00, 0xC8, 0xE8, 0x00, 0x00, 0x00, 0x00, 0xC7, 0xE7, 0x00, 0x00, 0xCB, 0xEB, 0xC6, 0xE6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0xEC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCE, 0xEE, 0x00, 0x00, 0xC1, 0xE1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCD, 0xED, 0x00, 0x00, 0x00, 0xCF, 0xEF, 0x00, 0x00, 0x00, 0x00, 0xD9, 0xF9, 0xD1, 0xF1, 0xD2, 0xF2, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD4, 0xF4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xBA, 0x00, 0x00, 0xDA, 0xFA, 0x00, 0x00, 0x00, 0x00, 0xD0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDB, 0xFB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCA, 0xEA, 0xDD, 0xFD, 0xDE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x9E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x96, 0x97, 0x00, 0x00, 0x00, 0x91, 0x92, 0x82, 0x00, 0x93, 0x94, 0x84, 0x00, 0x86, 0x87, 0x95, 0x00, 0x00, 0x00, 0x85, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x9B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
IArrayObjectPrimitive<wchar_t>* CP_1257::Encoder::arr = (IArrayObjectPrimitive<wchar_t>*)const_cast<StaticArrayObjectPrimitive<wchar_t>*>(&__arr);
const StaticArrayObjectPrimitive<int> CP_1257::Encoder::__encodeIndex = {0, 1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
IArrayObjectPrimitive<int>* CP_1257::Encoder::encodeIndex = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__encodeIndex);
bool CP_1257::Encoder::__init_done = __init_static_variables();
bool CP_1257::Encoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CP_1257::Encoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CP_1257::Encoder::Encoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetEncoder(ctx)
{
}
void CP_1257::Encoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CP_1257::Encoder::~Encoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CP_1257::Encoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
CoderResult* CP_1257::Encoder::encodeLoop(CharBuffer* cb, ByteBuffer* bb, ThreadContext* ctx) throw() 
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
				if(c > ((wchar_t)0x2122))
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
					if(c < (wchar_t)0x80)
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
				if(c > ((wchar_t)0x2122))
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
					if(c < (wchar_t)0x80)
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
void CP_1257::Encoder::__cleanUp(ThreadContext* ctx){
}
}}}

