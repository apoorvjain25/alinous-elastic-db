#ifndef ALINOUS_DB_VARIABLE_UTIL_RECORDSTORE_H_
#define ALINOUS_DB_VARIABLE_UTIL_RECORDSTORE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace variable {namespace util {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class RecordStore final : public virtual IObject {
public:
	RecordStore(const RecordStore& base) = default;
public:
	RecordStore(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RecordStore() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_VARIABLE_UTIL_RECORDSTORE_H_ */
