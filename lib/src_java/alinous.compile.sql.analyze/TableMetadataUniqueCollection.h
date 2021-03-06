#ifndef ALINOUS_COMPILE_SQL_ANALYZE_TABLEMETADATAUNIQUECOLLECTION_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_TABLEMETADATAUNIQUECOLLECTION_H_
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace db {namespace table {
class TablePartitionKeyCollection;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace db {namespace table {
class TablePartitionKey;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::db::table::TablePartitionKey;
using ::alinous::db::table::TablePartitionKeyCollection;



class TableMetadataUniqueCollection final : public virtual IObject {
public:
	TableMetadataUniqueCollection(const TableMetadataUniqueCollection& base) = default;
public:
	TableMetadataUniqueCollection(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TableMetadataUniqueCollection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<ScanUnique>* uniqueList;
	bool fullCover;
public:
	void addUnique(ScanUnique* unique, ThreadContext* ctx) throw() ;
	ArrayList<ScanUnique>* getUniqueList(ThreadContext* ctx) throw() ;
	void calcPartitionCoverage(TablePartitionKeyCollection* partitionKeys, ThreadContext* ctx) throw() ;
	bool isFullCover(ThreadContext* ctx) throw() ;
private:
	void calcCover(ScanUnique* unique, TablePartitionKeyCollection* partitionKeys, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_TABLEMETADATAUNIQUECOLLECTION_H_ */
