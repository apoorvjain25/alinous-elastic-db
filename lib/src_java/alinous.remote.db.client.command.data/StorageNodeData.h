#ifndef ALINOUS_REMOTE_DB_CLIENT_COMMAND_DATA_STORAGENODEDATA_H_
#define ALINOUS_REMOTE_DB_CLIENT_COMMAND_DATA_STORAGENODEDATA_H_
namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class StorageNodeData;}}}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::TableMetadata;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class StorageNodeData final : public ICommandData, public virtual IObject {
public:
	StorageNodeData(const StorageNodeData& base) = default;
public:
	StorageNodeData(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	StorageNodeData(String* host, int port, bool ipv6, TableMetadata* medatada, ThreadContext* ctx) throw() ;
	void __construct_impl(String* host, int port, bool ipv6, TableMetadata* medatada, ThreadContext* ctx) throw() ;
	virtual ~StorageNodeData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* host;
	int port;
	bool ipv6;
	TableMetadata* metadata;
public:
	String* getHost(ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	bool isIpv6(ThreadContext* ctx) throw() ;
	bool equals(String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	bool equals(StorageNodeData* another, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	TableMetadata* getMetadata(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_DB_CLIENT_COMMAND_DATA_STORAGENODEDATA_H_ */
