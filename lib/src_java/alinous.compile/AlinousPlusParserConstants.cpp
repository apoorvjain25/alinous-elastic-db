#include "includes.h"


namespace alinous {namespace compile {




constexpr const long long AlinousPlusParserConstants::EOF;
constexpr const long long AlinousPlusParserConstants::NOTASCII;
constexpr const long long AlinousPlusParserConstants::ASCILETTER;
constexpr const long long AlinousPlusParserConstants::NUMBERLETTER;
constexpr const long long AlinousPlusParserConstants::CHARACTOR;
constexpr const long long AlinousPlusParserConstants::INTEGER_LITERAL;
constexpr const long long AlinousPlusParserConstants::DECIMAL_LITERAL;
constexpr const long long AlinousPlusParserConstants::HEX_LITERAL;
constexpr const long long AlinousPlusParserConstants::OCTAL_LITERAL;
constexpr const long long AlinousPlusParserConstants::FLOATING_POINT_LITERAL;
constexpr const long long AlinousPlusParserConstants::DECIMAL_FLOATING_POINT_LITERAL;
constexpr const long long AlinousPlusParserConstants::DECIMAL_EXPONENT;
constexpr const long long AlinousPlusParserConstants::HEXADECIMAL_FLOATING_POINT_LITERAL;
constexpr const long long AlinousPlusParserConstants::HEXADECIMAL_EXPONENT;
constexpr const long long AlinousPlusParserConstants::STRING_LITERAL;
constexpr const long long AlinousPlusParserConstants::CHARACTER_LITERAL;
constexpr const long long AlinousPlusParserConstants::SQL_STRING_LITERAL;
constexpr const long long AlinousPlusParserConstants::SEMI_COLON;
constexpr const long long AlinousPlusParserConstants::EQUALS;
constexpr const long long AlinousPlusParserConstants::ASTERISK;
constexpr const long long AlinousPlusParserConstants::PLUSPLUS;
constexpr const long long AlinousPlusParserConstants::PLUS;
constexpr const long long AlinousPlusParserConstants::MINUSMINUS;
constexpr const long long AlinousPlusParserConstants::MINUS;
constexpr const long long AlinousPlusParserConstants::DIV;
constexpr const long long AlinousPlusParserConstants::MODULO;
constexpr const long long AlinousPlusParserConstants::LOGICAL_AND;
constexpr const long long AlinousPlusParserConstants::LOGICAL_OR;
constexpr const long long AlinousPlusParserConstants::BIT_AND;
constexpr const long long AlinousPlusParserConstants::BIT_OR;
constexpr const long long AlinousPlusParserConstants::L_PARENTHESIS;
constexpr const long long AlinousPlusParserConstants::R_PARENTHESIS;
constexpr const long long AlinousPlusParserConstants::L_BRACKET;
constexpr const long long AlinousPlusParserConstants::R_BRACKET;
constexpr const long long AlinousPlusParserConstants::DOLLAR;
constexpr const long long AlinousPlusParserConstants::DOT;
constexpr const long long AlinousPlusParserConstants::COMMA;
constexpr const long long AlinousPlusParserConstants::AT_AT_MARK;
constexpr const long long AlinousPlusParserConstants::AT_MARK;
constexpr const long long AlinousPlusParserConstants::L_BRACE;
constexpr const long long AlinousPlusParserConstants::R_BRACE;
constexpr const long long AlinousPlusParserConstants::CMP_EQUALS;
constexpr const long long AlinousPlusParserConstants::CMP_NOTEQUALS;
constexpr const long long AlinousPlusParserConstants::GT;
constexpr const long long AlinousPlusParserConstants::GEQ;
constexpr const long long AlinousPlusParserConstants::LT;
constexpr const long long AlinousPlusParserConstants::LEQ;
constexpr const long long AlinousPlusParserConstants::NOT;
constexpr const long long AlinousPlusParserConstants::COLON;
constexpr const long long AlinousPlusParserConstants::RSIGNEDSHIFT;
constexpr const long long AlinousPlusParserConstants::RUNSIGNEDSHIFT;
constexpr const long long AlinousPlusParserConstants::IMPORT;
constexpr const long long AlinousPlusParserConstants::PACKAGE;
constexpr const long long AlinousPlusParserConstants::CLASS;
constexpr const long long AlinousPlusParserConstants::CLASS_INTERFACE;
constexpr const long long AlinousPlusParserConstants::ABSTRACT;
constexpr const long long AlinousPlusParserConstants::BREAK;
constexpr const long long AlinousPlusParserConstants::BYTE;
constexpr const long long AlinousPlusParserConstants::CASE;
constexpr const long long AlinousPlusParserConstants::CATCH;
constexpr const long long AlinousPlusParserConstants::_CONST;
constexpr const long long AlinousPlusParserConstants::CONTINUE;
constexpr const long long AlinousPlusParserConstants::DO;
constexpr const long long AlinousPlusParserConstants::ELSE;
constexpr const long long AlinousPlusParserConstants::ENUM;
constexpr const long long AlinousPlusParserConstants::EXTENDS;
constexpr const long long AlinousPlusParserConstants::FINAL;
constexpr const long long AlinousPlusParserConstants::FINALLY;
constexpr const long long AlinousPlusParserConstants::FOR;
constexpr const long long AlinousPlusParserConstants::GOTO;
constexpr const long long AlinousPlusParserConstants::IF;
constexpr const long long AlinousPlusParserConstants::IMPLEMENTS;
constexpr const long long AlinousPlusParserConstants::INSTANCEOF;
constexpr const long long AlinousPlusParserConstants::NATIVE;
constexpr const long long AlinousPlusParserConstants::NEW;
constexpr const long long AlinousPlusParserConstants::PRIVATE;
constexpr const long long AlinousPlusParserConstants::PROTECTED;
constexpr const long long AlinousPlusParserConstants::PUBLIC;
constexpr const long long AlinousPlusParserConstants::RETURN;
constexpr const long long AlinousPlusParserConstants::STATIC;
constexpr const long long AlinousPlusParserConstants::SUPER;
constexpr const long long AlinousPlusParserConstants::SWITCH;
constexpr const long long AlinousPlusParserConstants::SYNCHRONIZED;
constexpr const long long AlinousPlusParserConstants::THIS;
constexpr const long long AlinousPlusParserConstants::THROW;
constexpr const long long AlinousPlusParserConstants::THROWS;
constexpr const long long AlinousPlusParserConstants::TRY;
constexpr const long long AlinousPlusParserConstants::VOID;
constexpr const long long AlinousPlusParserConstants::WHILE;
constexpr const long long AlinousPlusParserConstants::INCLUDE;
constexpr const long long AlinousPlusParserConstants::DOWNLOAD;
constexpr const long long AlinousPlusParserConstants::REDIRECT;
constexpr const long long AlinousPlusParserConstants::REFERER_FROM;
constexpr const long long AlinousPlusParserConstants::VALIDATOR;
constexpr const long long AlinousPlusParserConstants::PARALLEL;
constexpr const long long AlinousPlusParserConstants::LOCAL;
constexpr const long long AlinousPlusParserConstants::TRUE;
constexpr const long long AlinousPlusParserConstants::FALSE;
constexpr const long long AlinousPlusParserConstants::SELECT;
constexpr const long long AlinousPlusParserConstants::INSERT;
constexpr const long long AlinousPlusParserConstants::UPDATE;
constexpr const long long AlinousPlusParserConstants::DELETE;
constexpr const long long AlinousPlusParserConstants::INTO;
constexpr const long long AlinousPlusParserConstants::FROM;
constexpr const long long AlinousPlusParserConstants::WHERE;
constexpr const long long AlinousPlusParserConstants::OR;
constexpr const long long AlinousPlusParserConstants::SQLAND;
constexpr const long long AlinousPlusParserConstants::LIKE;
constexpr const long long AlinousPlusParserConstants::ESCAPE;
constexpr const long long AlinousPlusParserConstants::LEFT;
constexpr const long long AlinousPlusParserConstants::RIGHT;
constexpr const long long AlinousPlusParserConstants::NATURAL;
constexpr const long long AlinousPlusParserConstants::INNER;
constexpr const long long AlinousPlusParserConstants::OUTER;
constexpr const long long AlinousPlusParserConstants::FULL;
constexpr const long long AlinousPlusParserConstants::JOIN;
constexpr const long long AlinousPlusParserConstants::CROSS;
constexpr const long long AlinousPlusParserConstants::SET;
constexpr const long long AlinousPlusParserConstants::VALUES;
constexpr const long long AlinousPlusParserConstants::GROUP;
constexpr const long long AlinousPlusParserConstants::BY;
constexpr const long long AlinousPlusParserConstants::HAVING;
constexpr const long long AlinousPlusParserConstants::ORDER;
constexpr const long long AlinousPlusParserConstants::ASC;
constexpr const long long AlinousPlusParserConstants::DESC;
constexpr const long long AlinousPlusParserConstants::LIMIT;
constexpr const long long AlinousPlusParserConstants::OFFSET;
constexpr const long long AlinousPlusParserConstants::ON;
constexpr const long long AlinousPlusParserConstants::SQL_NOT;
constexpr const long long AlinousPlusParserConstants::AS;
constexpr const long long AlinousPlusParserConstants::DISTINCT;
constexpr const long long AlinousPlusParserConstants::SHARE;
constexpr const long long AlinousPlusParserConstants::NOWAIT;
constexpr const long long AlinousPlusParserConstants::OF;
constexpr const long long AlinousPlusParserConstants::IN;
constexpr const long long AlinousPlusParserConstants::BETWEEN;
constexpr const long long AlinousPlusParserConstants::IS;
constexpr const long long AlinousPlusParserConstants::BEGIN;
constexpr const long long AlinousPlusParserConstants::PREPARE;
constexpr const long long AlinousPlusParserConstants::TRANSACTION;
constexpr const long long AlinousPlusParserConstants::ISOLATION;
constexpr const long long AlinousPlusParserConstants::LEVEL;
constexpr const long long AlinousPlusParserConstants::COMMIT;
constexpr const long long AlinousPlusParserConstants::PREPARED;
constexpr const long long AlinousPlusParserConstants::END;
constexpr const long long AlinousPlusParserConstants::ROLLBACK;
constexpr const long long AlinousPlusParserConstants::CREATE;
constexpr const long long AlinousPlusParserConstants::DROP;
constexpr const long long AlinousPlusParserConstants::ALTER;
constexpr const long long AlinousPlusParserConstants::TABLE;
constexpr const long long AlinousPlusParserConstants::SQL_DEFAULT;
constexpr const long long AlinousPlusParserConstants::ADD;
constexpr const long long AlinousPlusParserConstants::RENAME;
constexpr const long long AlinousPlusParserConstants::COLUMN;
constexpr const long long AlinousPlusParserConstants::TO;
constexpr const long long AlinousPlusParserConstants::PRIMARY;
constexpr const long long AlinousPlusParserConstants::KEY;
constexpr const long long AlinousPlusParserConstants::UNIQUE;
constexpr const long long AlinousPlusParserConstants::CHECK;
constexpr const long long AlinousPlusParserConstants::RETURNS;
constexpr const long long AlinousPlusParserConstants::SETOF;
constexpr const long long AlinousPlusParserConstants::LANGUAGE;
constexpr const long long AlinousPlusParserConstants::REPLACE;
constexpr const long long AlinousPlusParserConstants::INDEX;
constexpr const long long AlinousPlusParserConstants::USING;
constexpr const long long AlinousPlusParserConstants::EACH;
constexpr const long long AlinousPlusParserConstants::ROW;
constexpr const long long AlinousPlusParserConstants::STATEMENT;
constexpr const long long AlinousPlusParserConstants::EXECUTE;
constexpr const long long AlinousPlusParserConstants::PROCEDURE;
constexpr const long long AlinousPlusParserConstants::EXISTS;
constexpr const long long AlinousPlusParserConstants::TRIGGER;
constexpr const long long AlinousPlusParserConstants::BEFORE;
constexpr const long long AlinousPlusParserConstants::AFTER;
constexpr const long long AlinousPlusParserConstants::FOREIGN;
constexpr const long long AlinousPlusParserConstants::REFERENCES;
constexpr const long long AlinousPlusParserConstants::ADJUST_WHERE;
constexpr const long long AlinousPlusParserConstants::ADJUST_SET;
constexpr const long long AlinousPlusParserConstants::BOOL;
constexpr const long long AlinousPlusParserConstants::_NULL;
constexpr const long long AlinousPlusParserConstants::FUNCTION;
constexpr const long long AlinousPlusParserConstants::USE;
constexpr const long long AlinousPlusParserConstants::IDENTIFIER;
constexpr const long long AlinousPlusParserConstants::DEFAULT;
constexpr const long long AlinousPlusParserConstants::COMM;
constexpr const long long AlinousPlusParserConstants::L_COMM;
const StaticArrayObject<UnicodeStringWrapper> AlinousPlusParserConstants::__tokenImage = {ConstStr::getCNST_STR_1222(), ConstStr::getCNST_STR_1223(), ConstStr::getCNST_STR_1224(), ConstStr::getCNST_STR_1225(), ConstStr::getCNST_STR_1226(), ConstStr::getCNST_STR_1227(), ConstStr::getCNST_STR_1228(), ConstStr::getCNST_STR_1229(), ConstStr::getCNST_STR_1230(), ConstStr::getCNST_STR_1231(), ConstStr::getCNST_STR_1232(), ConstStr::getCNST_STR_1233(), ConstStr::getCNST_STR_1234(), ConstStr::getCNST_STR_1235(), ConstStr::getCNST_STR_1236(), ConstStr::getCNST_STR_1237(), ConstStr::getCNST_STR_1238(), ConstStr::getCNST_STR_1239(), ConstStr::getCNST_STR_1240(), ConstStr::getCNST_STR_1241(), ConstStr::getCNST_STR_1242(), ConstStr::getCNST_STR_1243(), ConstStr::getCNST_STR_1244(), ConstStr::getCNST_STR_1245(), ConstStr::getCNST_STR_1246(), ConstStr::getCNST_STR_1247(), ConstStr::getCNST_STR_1248(), ConstStr::getCNST_STR_1249(), ConstStr::getCNST_STR_1250(), ConstStr::getCNST_STR_1251(), ConstStr::getCNST_STR_1252(), ConstStr::getCNST_STR_1253(), ConstStr::getCNST_STR_1254(), ConstStr::getCNST_STR_1255(), ConstStr::getCNST_STR_1256(), ConstStr::getCNST_STR_1257(), ConstStr::getCNST_STR_1258(), ConstStr::getCNST_STR_1259(), ConstStr::getCNST_STR_1260(), ConstStr::getCNST_STR_1261(), ConstStr::getCNST_STR_1262(), ConstStr::getCNST_STR_1263(), ConstStr::getCNST_STR_1264(), ConstStr::getCNST_STR_1265(), ConstStr::getCNST_STR_1266(), ConstStr::getCNST_STR_1267(), ConstStr::getCNST_STR_1268(), ConstStr::getCNST_STR_1269(), ConstStr::getCNST_STR_1270(), ConstStr::getCNST_STR_1271(), ConstStr::getCNST_STR_1272(), ConstStr::getCNST_STR_1273(), ConstStr::getCNST_STR_1274(), ConstStr::getCNST_STR_1275(), ConstStr::getCNST_STR_1276(), ConstStr::getCNST_STR_1277(), ConstStr::getCNST_STR_1278(), ConstStr::getCNST_STR_1279(), ConstStr::getCNST_STR_1280(), ConstStr::getCNST_STR_1281(), ConstStr::getCNST_STR_1282(), ConstStr::getCNST_STR_1283(), ConstStr::getCNST_STR_1284(), ConstStr::getCNST_STR_1285(), ConstStr::getCNST_STR_1286(), ConstStr::getCNST_STR_1287(), ConstStr::getCNST_STR_1288(), ConstStr::getCNST_STR_1289(), ConstStr::getCNST_STR_1290(), ConstStr::getCNST_STR_1291(), ConstStr::getCNST_STR_1292(), ConstStr::getCNST_STR_1293(), ConstStr::getCNST_STR_1294(), ConstStr::getCNST_STR_1295(), ConstStr::getCNST_STR_1296(), ConstStr::getCNST_STR_1297(), ConstStr::getCNST_STR_1298(), ConstStr::getCNST_STR_1299(), ConstStr::getCNST_STR_1300(), ConstStr::getCNST_STR_1301(), ConstStr::getCNST_STR_1302(), ConstStr::getCNST_STR_1303(), ConstStr::getCNST_STR_1304(), ConstStr::getCNST_STR_1305(), ConstStr::getCNST_STR_1306(), ConstStr::getCNST_STR_1307(), ConstStr::getCNST_STR_1308(), ConstStr::getCNST_STR_1309(), ConstStr::getCNST_STR_1310(), ConstStr::getCNST_STR_1311(), ConstStr::getCNST_STR_1312(), ConstStr::getCNST_STR_1313(), ConstStr::getCNST_STR_1314(), ConstStr::getCNST_STR_1315(), ConstStr::getCNST_STR_1316(), ConstStr::getCNST_STR_1317(), ConstStr::getCNST_STR_1318(), ConstStr::getCNST_STR_1319(), ConstStr::getCNST_STR_1320(), ConstStr::getCNST_STR_1321(), ConstStr::getCNST_STR_1322(), ConstStr::getCNST_STR_1323(), ConstStr::getCNST_STR_1324(), ConstStr::getCNST_STR_1325(), ConstStr::getCNST_STR_1326(), ConstStr::getCNST_STR_1327(), ConstStr::getCNST_STR_1328(), ConstStr::getCNST_STR_1329(), ConstStr::getCNST_STR_1330(), ConstStr::getCNST_STR_1331(), ConstStr::getCNST_STR_1332(), ConstStr::getCNST_STR_1333(), ConstStr::getCNST_STR_1334(), ConstStr::getCNST_STR_1335(), ConstStr::getCNST_STR_1336(), ConstStr::getCNST_STR_1337(), ConstStr::getCNST_STR_1338(), ConstStr::getCNST_STR_1339(), ConstStr::getCNST_STR_1340(), ConstStr::getCNST_STR_1341(), ConstStr::getCNST_STR_1342(), ConstStr::getCNST_STR_1343(), ConstStr::getCNST_STR_1344(), ConstStr::getCNST_STR_1345(), ConstStr::getCNST_STR_1346(), ConstStr::getCNST_STR_1347(), ConstStr::getCNST_STR_1348(), ConstStr::getCNST_STR_1349(), ConstStr::getCNST_STR_1350(), ConstStr::getCNST_STR_1351(), ConstStr::getCNST_STR_1352(), ConstStr::getCNST_STR_1353(), ConstStr::getCNST_STR_1354(), ConstStr::getCNST_STR_1355(), ConstStr::getCNST_STR_1356(), ConstStr::getCNST_STR_1357(), ConstStr::getCNST_STR_1358(), ConstStr::getCNST_STR_1359(), ConstStr::getCNST_STR_1360(), ConstStr::getCNST_STR_1361(), ConstStr::getCNST_STR_1362(), ConstStr::getCNST_STR_1363(), ConstStr::getCNST_STR_1364(), ConstStr::getCNST_STR_1365(), ConstStr::getCNST_STR_1366(), ConstStr::getCNST_STR_1367(), ConstStr::getCNST_STR_1368(), ConstStr::getCNST_STR_1369(), ConstStr::getCNST_STR_1370(), ConstStr::getCNST_STR_1371(), ConstStr::getCNST_STR_1372(), ConstStr::getCNST_STR_1373(), ConstStr::getCNST_STR_1374(), ConstStr::getCNST_STR_1375(), ConstStr::getCNST_STR_1376(), ConstStr::getCNST_STR_1377(), ConstStr::getCNST_STR_1378(), ConstStr::getCNST_STR_1379(), ConstStr::getCNST_STR_1380(), ConstStr::getCNST_STR_1381(), ConstStr::getCNST_STR_1382(), ConstStr::getCNST_STR_1383(), ConstStr::getCNST_STR_1384(), ConstStr::getCNST_STR_1385(), ConstStr::getCNST_STR_1386(), ConstStr::getCNST_STR_1387(), ConstStr::getCNST_STR_1388(), ConstStr::getCNST_STR_1389(), ConstStr::getCNST_STR_1390(), ConstStr::getCNST_STR_1391(), ConstStr::getCNST_STR_1392(), ConstStr::getCNST_STR_1393(), ConstStr::getCNST_STR_1394(), ConstStr::getCNST_STR_1395(), ConstStr::getCNST_STR_1396(), ConstStr::getCNST_STR_1397(), ConstStr::getCNST_STR_1398(), ConstStr::getCNST_STR_1399(), ConstStr::getCNST_STR_1400(), ConstStr::getCNST_STR_1401(), ConstStr::getCNST_STR_1402(), ConstStr::getCNST_STR_1403(), ConstStr::getCNST_STR_1404(), ConstStr::getCNST_STR_1405(), ConstStr::getCNST_STR_1406(), ConstStr::getCNST_STR_1407(), ConstStr::getCNST_STR_1408(), ConstStr::getCNST_STR_1409(), ConstStr::getCNST_STR_1410(), ConstStr::getCNST_STR_1225(), ConstStr::getCNST_STR_1411(), ConstStr::getCNST_STR_1412(), ConstStr::getCNST_STR_1413(), ConstStr::getCNST_STR_1414(), ConstStr::getCNST_STR_1415(), ConstStr::getCNST_STR_1416(), ConstStr::getCNST_STR_1417(), ConstStr::getCNST_STR_1418(), ConstStr::getCNST_STR_1419(), ConstStr::getCNST_STR_1420(), ConstStr::getCNST_STR_1421(), ConstStr::getCNST_STR_1422(), ConstStr::getCNST_STR_1423(), ConstStr::getCNST_STR_1424(), ConstStr::getCNST_STR_1425(), ConstStr::getCNST_STR_1426(), ConstStr::getCNST_STR_1427(), ConstStr::getCNST_STR_1428()};
IArrayObject<String>* AlinousPlusParserConstants::tokenImage = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__tokenImage);
bool AlinousPlusParserConstants::__init_done = __init_static_variables();
bool AlinousPlusParserConstants::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousPlusParserConstants", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousPlusParserConstants::~AlinousPlusParserConstants() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousPlusParserConstants::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}
