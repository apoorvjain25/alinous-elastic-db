#ifndef ALINOUS_REMOTE_REGION_CLIENT_REMOTEREGIONREF_H_
#define ALINOUS_REMOTE_REGION_CLIENT_REMOTEREGIONREF_H_
namespace alinous {namespace system {namespace config {namespace remote {
class RegionRef;}}}}

namespace alinous {namespace db {
class ITableSchema;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace db {
class ITableRegion;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::db::ITableRegion;
using ::alinous::db::ITableSchema;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::TableMetadata;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::config::remote::RegionRef;



class RemoteRegionRef final : public ITableRegion, public virtual IObject {
public:
	RemoteRegionRef(const RemoteRegionRef& base) = default;
public:
	RemoteRegionRef(RegionRef* ref, ThreadContext* ctx) throw() ;
	void __construct_impl(RegionRef* ref, ThreadContext* ctx) throw() ;
	virtual ~RemoteRegionRef() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	RegionRef* config;
public:
	int getRegionType(ThreadContext* ctx) throw()  final;
	String* getRegionName(ThreadContext* ctx) throw()  final;
	ITableSchema* getSchema(String* name, ThreadContext* ctx) throw()  final;
	void createSchema(String* schemaName, ThreadContext* ctx) throw()  final;
	void createTable(String* schemaName, TableMetadata* tblMeta, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	RegionRef* getConfig(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_REMOTEREGIONREF_H_ */
