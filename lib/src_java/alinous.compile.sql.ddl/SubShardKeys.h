#ifndef ALINOUS_COMPILE_SQL_DDL_SUBSHARDKEYS_H_
#define ALINOUS_COMPILE_SQL_DDL_SUBSHARDKEYS_H_
namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace compile {
class IAlinousVisitorContainer;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace ddl {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::IAlinousVisitorContainer;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class SubShardKeys final : public IAlinousElement, public IAlinousVisitorContainer {
public:
	SubShardKeys(const SubShardKeys& base) = default;
public:
	SubShardKeys(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx), columns(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SubShardKeys() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<String>* columns;
public:
	void addKey(String* key, ThreadContext* ctx) throw() ;
	ArrayList<String>* getColumns(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_DDL_SUBSHARDKEYS_H_ */
