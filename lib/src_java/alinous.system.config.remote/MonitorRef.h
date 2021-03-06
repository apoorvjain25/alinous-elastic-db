#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_MONITORREF_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_MONITORREF_H_
namespace alinous {namespace system {namespace config {namespace remote {
class MonitorRef;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidate;}}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class Matcher;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchingException;}}}}

namespace alinous {namespace parser {namespace xpath {
class ParseException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {namespace remote {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::html::xpath::match::MatchCandidate;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::html::xpath::match::MatchingException;
using ::alinous::parser::xpath::ParseException;
using ::alinous::system::config::AlinousInitException;
using ::alinous::system::config::IAlinousConfigElement;



class MonitorRef final : public IAlinousConfigElement, public virtual IObject {
public:
	MonitorRef(const MonitorRef& base) = default;
public:
	MonitorRef(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~MonitorRef() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* url;
	String* host;
	int port;
	bool ipv6;
public:
	void parseUrl(ThreadContext* ctx);
	String* getUrl(ThreadContext* ctx) throw() ;
	void setUrl(String* url, ThreadContext* ctx) throw() ;
	String* getHost(ThreadContext* ctx) throw() ;
	void setHost(String* host, ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	void setPort(int port, ThreadContext* ctx) throw() ;
	bool isIpv6(ThreadContext* ctx) throw() ;
	void setIpv6(bool ipv6, ThreadContext* ctx) throw() ;
public:
	static MonitorRef* parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_MONITORREF_H_ */
