#ifndef ALINOUS_DB_TABLESCHEMACOLLECTION_H_
#define ALINOUS_DB_TABLESCHEMACOLLECTION_H_
namespace alinous {namespace db {
class ITableSchema;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::TableMetadata;



class TableSchemaCollection final : public virtual IObject {
public:
	TableSchemaCollection(const TableSchemaCollection& base) = default;
public:
	TableSchemaCollection(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TableSchemaCollection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<ITableSchema>* list;
public:
	void addScheme(ITableSchema* sc, ThreadContext* ctx) throw() ;
	IDatabaseTable* getTableStore(String* tableName, ThreadContext* ctx) throw() ;
	TableMetadata* getDableMetadata(String* tableName, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_DB_TABLESCHEMACOLLECTION_H_ */
