#ifndef ALINOUS_DB_TABLE_TABLEPARTITIONKEY_H_
#define ALINOUS_DB_TABLE_TABLEPARTITIONKEY_H_
namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionKey;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::AlinousDbException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class TablePartitionKey final : public ICommandData, public virtual IObject {
public:
	TablePartitionKey(const TablePartitionKey& base) = default;
public:
	TablePartitionKey(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TablePartitionKey() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<TableColumnMetadata>* keys;
	String* colString;
public:
	void addKeyColumn(TableColumnMetadata* col, ThreadContext* ctx) throw() ;
	List<VariantValue>* makeValues(IDatabaseRecord* record, ThreadContext* ctx) throw() ;
	String* getColumnString(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	int fileSize(ThreadContext* ctx);
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	ArrayList<TableColumnMetadata>* getKeys(ThreadContext* ctx) throw() ;
public:
	static TablePartitionKey* loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
	static TablePartitionKey* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLEPARTITIONKEY_H_ */
