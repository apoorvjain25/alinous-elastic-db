#ifndef ALINOUS_COMPILE_EXPRESSION_CONDITIONALEXPRESSION_H_
#define ALINOUS_COMPILE_EXPRESSION_CONDITIONALEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class IExpressionFactory;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace compile {namespace expression {
class AbstractExpression;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::db::table::DatabaseException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class ConditionalExpression final : public AbstractExpression {
public:
	ConditionalExpression(const ConditionalExpression& base) = default;
public:
	ConditionalExpression(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ConditionalExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IExpression* first;
	IExpression* exp;
	IExpression* altexp;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	IExpression* getFirst(ThreadContext* ctx) throw() ;
	void setFirst(IExpression* first, ThreadContext* ctx) throw() ;
	IExpression* getExp(ThreadContext* ctx) throw() ;
	void setExp(IExpression* exp, ThreadContext* ctx) throw() ;
	IExpression* getAltexp(ThreadContext* ctx) throw() ;
	void setAltexp(IExpression* altexp, ThreadContext* ctx) throw() ;
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	bool isSQLExp(ThreadContext* ctx) throw()  final;
	int getExpressionType(ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	int fileSize(ThreadContext* ctx) final;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	void fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) final;
public:
	static void includes(IExpressionFactory* arg0, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_CONDITIONALEXPRESSION_H_ */
