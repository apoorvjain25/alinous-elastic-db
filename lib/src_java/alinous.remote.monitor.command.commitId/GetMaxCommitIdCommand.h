#ifndef ALINOUS_REMOTE_MONITOR_COMMAND_COMMITID_GETMAXCOMMITIDCOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_COMMAND_COMMITID_GETMAXCOMMITIDCOMMAND_H_
namespace alinous {namespace remote {namespace monitor {
class TransactionMonitorServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class AbstractMonitorCommand;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::remote::monitor::TransactionMonitorServer;
using ::alinous::remote::monitor::command::AbstractMonitorCommand;



class GetMaxCommitIdCommand final : public AbstractMonitorCommand {
public:
	GetMaxCommitIdCommand(const GetMaxCommitIdCommand& base) = default;
public:
	GetMaxCommitIdCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~GetMaxCommitIdCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_COMMAND_COMMITID_GETMAXCOMMITIDCOMMAND_H_ */