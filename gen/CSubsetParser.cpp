
// Generated from CSubset.g4 by ANTLR 4.13.2


#include "CSubsetListener.h"
#include "CSubsetVisitor.h"

#include "CSubsetParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CSubsetParserStaticData final {
  CSubsetParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CSubsetParserStaticData(const CSubsetParserStaticData&) = delete;
  CSubsetParserStaticData(CSubsetParserStaticData&&) = delete;
  CSubsetParserStaticData& operator=(const CSubsetParserStaticData&) = delete;
  CSubsetParserStaticData& operator=(CSubsetParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag csubsetParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CSubsetParserStaticData> csubsetParserStaticData = nullptr;

void csubsetParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (csubsetParserStaticData != nullptr) {
    return;
  }
#else
  assert(csubsetParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CSubsetParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "type_specifier", 
      "declaration_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'println'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "'++'", "'--'", "'!'", "", "", 
      "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", 
      "ID", "CONST_INT", "CONST_FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,32,304,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,54,8,1,10,1,12,1,57,9,1,
  	1,2,1,2,1,2,3,2,62,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,3,3,77,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	3,4,92,8,4,1,5,1,5,1,5,1,5,1,5,3,5,99,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,5,5,109,8,5,10,5,12,5,112,9,5,1,6,1,6,1,6,1,6,1,6,1,6,3,6,120,8,6,
  	1,7,1,7,1,7,1,7,1,8,1,8,1,8,3,8,129,8,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,137,
  	8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,148,8,9,10,9,12,9,151,9,9,
  	1,10,1,10,1,10,1,10,1,10,5,10,158,8,10,10,10,12,10,161,9,10,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,203,8,11,1,12,
  	1,12,1,12,1,12,3,12,209,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,217,8,
  	13,1,14,1,14,1,14,1,14,1,14,3,14,224,8,14,1,15,1,15,1,15,1,15,1,15,3,
  	15,231,8,15,1,16,1,16,1,16,1,16,1,16,3,16,238,8,16,1,17,1,17,1,17,1,17,
  	1,17,1,17,5,17,246,8,17,10,17,12,17,249,9,17,1,18,1,18,1,18,1,18,1,18,
  	1,18,5,18,257,8,18,10,18,12,18,260,9,18,1,19,1,19,1,19,1,19,1,19,3,19,
  	267,8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,3,20,287,8,20,1,21,1,21,3,21,291,8,21,1,
  	22,1,22,1,22,1,22,1,22,1,22,5,22,299,8,22,10,22,12,22,302,9,22,1,22,0,
  	7,2,10,18,20,34,36,44,23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,
  	34,36,38,40,42,44,0,0,320,0,46,1,0,0,0,2,48,1,0,0,0,4,61,1,0,0,0,6,76,
  	1,0,0,0,8,91,1,0,0,0,10,98,1,0,0,0,12,119,1,0,0,0,14,121,1,0,0,0,16,128,
  	1,0,0,0,18,136,1,0,0,0,20,152,1,0,0,0,22,202,1,0,0,0,24,208,1,0,0,0,26,
  	216,1,0,0,0,28,223,1,0,0,0,30,230,1,0,0,0,32,237,1,0,0,0,34,239,1,0,0,
  	0,36,250,1,0,0,0,38,266,1,0,0,0,40,286,1,0,0,0,42,290,1,0,0,0,44,292,
  	1,0,0,0,46,47,3,2,1,0,47,1,1,0,0,0,48,49,6,1,-1,0,49,50,3,4,2,0,50,55,
  	1,0,0,0,51,52,10,2,0,0,52,54,3,4,2,0,53,51,1,0,0,0,54,57,1,0,0,0,55,53,
  	1,0,0,0,55,56,1,0,0,0,56,3,1,0,0,0,57,55,1,0,0,0,58,62,3,14,7,0,59,62,
  	3,6,3,0,60,62,3,8,4,0,61,58,1,0,0,0,61,59,1,0,0,0,61,60,1,0,0,0,62,5,
  	1,0,0,0,63,64,3,16,8,0,64,65,5,30,0,0,65,66,5,14,0,0,66,67,3,10,5,0,67,
  	68,5,15,0,0,68,69,5,20,0,0,69,77,1,0,0,0,70,71,3,16,8,0,71,72,5,30,0,
  	0,72,73,5,14,0,0,73,74,5,15,0,0,74,75,5,20,0,0,75,77,1,0,0,0,76,63,1,
  	0,0,0,76,70,1,0,0,0,77,7,1,0,0,0,78,79,3,16,8,0,79,80,5,30,0,0,80,81,
  	5,14,0,0,81,82,3,10,5,0,82,83,5,15,0,0,83,84,3,12,6,0,84,92,1,0,0,0,85,
  	86,3,16,8,0,86,87,5,30,0,0,87,88,5,14,0,0,88,89,5,15,0,0,89,90,3,12,6,
  	0,90,92,1,0,0,0,91,78,1,0,0,0,91,85,1,0,0,0,92,9,1,0,0,0,93,94,6,5,-1,
  	0,94,95,3,16,8,0,95,96,5,30,0,0,96,99,1,0,0,0,97,99,3,16,8,0,98,93,1,
  	0,0,0,98,97,1,0,0,0,99,110,1,0,0,0,100,101,10,4,0,0,101,102,5,21,0,0,
  	102,103,3,16,8,0,103,104,5,30,0,0,104,109,1,0,0,0,105,106,10,3,0,0,106,
  	107,5,21,0,0,107,109,3,16,8,0,108,100,1,0,0,0,108,105,1,0,0,0,109,112,
  	1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,11,1,0,0,0,112,110,1,0,0,
  	0,113,114,5,16,0,0,114,115,3,20,10,0,115,116,5,17,0,0,116,120,1,0,0,0,
  	117,118,5,16,0,0,118,120,5,17,0,0,119,113,1,0,0,0,119,117,1,0,0,0,120,
  	13,1,0,0,0,121,122,3,16,8,0,122,123,3,18,9,0,123,124,5,20,0,0,124,15,
  	1,0,0,0,125,129,5,11,0,0,126,129,5,12,0,0,127,129,5,13,0,0,128,125,1,
  	0,0,0,128,126,1,0,0,0,128,127,1,0,0,0,129,17,1,0,0,0,130,131,6,9,-1,0,
  	131,137,5,30,0,0,132,133,5,30,0,0,133,134,5,18,0,0,134,135,5,31,0,0,135,
  	137,5,19,0,0,136,130,1,0,0,0,136,132,1,0,0,0,137,149,1,0,0,0,138,139,
  	10,4,0,0,139,140,5,21,0,0,140,148,5,30,0,0,141,142,10,3,0,0,142,143,5,
  	21,0,0,143,144,5,30,0,0,144,145,5,18,0,0,145,146,5,31,0,0,146,148,5,19,
  	0,0,147,138,1,0,0,0,147,141,1,0,0,0,148,151,1,0,0,0,149,147,1,0,0,0,149,
  	150,1,0,0,0,150,19,1,0,0,0,151,149,1,0,0,0,152,153,6,10,-1,0,153,154,
  	3,22,11,0,154,159,1,0,0,0,155,156,10,1,0,0,156,158,3,22,11,0,157,155,
  	1,0,0,0,158,161,1,0,0,0,159,157,1,0,0,0,159,160,1,0,0,0,160,21,1,0,0,
  	0,161,159,1,0,0,0,162,203,3,14,7,0,163,164,5,9,0,0,164,165,5,14,0,0,165,
  	166,5,30,0,0,166,167,5,15,0,0,167,203,5,20,0,0,168,203,3,24,12,0,169,
  	203,3,12,6,0,170,171,5,7,0,0,171,172,5,14,0,0,172,173,3,24,12,0,173,174,
  	3,24,12,0,174,175,3,28,14,0,175,176,5,15,0,0,176,177,3,22,11,0,177,203,
  	1,0,0,0,178,179,5,5,0,0,179,180,5,14,0,0,180,181,3,28,14,0,181,182,5,
  	15,0,0,182,183,3,22,11,0,183,203,1,0,0,0,184,185,5,5,0,0,185,186,5,14,
  	0,0,186,187,3,28,14,0,187,188,5,15,0,0,188,189,3,22,11,0,189,190,5,6,
  	0,0,190,191,3,22,11,0,191,203,1,0,0,0,192,193,5,8,0,0,193,194,5,14,0,
  	0,194,195,3,28,14,0,195,196,5,15,0,0,196,197,3,22,11,0,197,203,1,0,0,
  	0,198,199,5,10,0,0,199,200,3,28,14,0,200,201,5,20,0,0,201,203,1,0,0,0,
  	202,162,1,0,0,0,202,163,1,0,0,0,202,168,1,0,0,0,202,169,1,0,0,0,202,170,
  	1,0,0,0,202,178,1,0,0,0,202,184,1,0,0,0,202,192,1,0,0,0,202,198,1,0,0,
  	0,203,23,1,0,0,0,204,209,5,20,0,0,205,206,3,28,14,0,206,207,5,20,0,0,
  	207,209,1,0,0,0,208,204,1,0,0,0,208,205,1,0,0,0,209,25,1,0,0,0,210,217,
  	5,30,0,0,211,212,5,30,0,0,212,213,5,18,0,0,213,214,3,28,14,0,214,215,
  	5,19,0,0,215,217,1,0,0,0,216,210,1,0,0,0,216,211,1,0,0,0,217,27,1,0,0,
  	0,218,224,3,30,15,0,219,220,3,26,13,0,220,221,5,29,0,0,221,222,3,30,15,
  	0,222,224,1,0,0,0,223,218,1,0,0,0,223,219,1,0,0,0,224,29,1,0,0,0,225,
  	231,3,32,16,0,226,227,3,32,16,0,227,228,5,28,0,0,228,229,3,32,16,0,229,
  	231,1,0,0,0,230,225,1,0,0,0,230,226,1,0,0,0,231,31,1,0,0,0,232,238,3,
  	34,17,0,233,234,3,34,17,0,234,235,5,27,0,0,235,236,3,34,17,0,236,238,
  	1,0,0,0,237,232,1,0,0,0,237,233,1,0,0,0,238,33,1,0,0,0,239,240,6,17,-1,
  	0,240,241,3,36,18,0,241,247,1,0,0,0,242,243,10,1,0,0,243,244,5,22,0,0,
  	244,246,3,36,18,0,245,242,1,0,0,0,246,249,1,0,0,0,247,245,1,0,0,0,247,
  	248,1,0,0,0,248,35,1,0,0,0,249,247,1,0,0,0,250,251,6,18,-1,0,251,252,
  	3,38,19,0,252,258,1,0,0,0,253,254,10,1,0,0,254,255,5,23,0,0,255,257,3,
  	38,19,0,256,253,1,0,0,0,257,260,1,0,0,0,258,256,1,0,0,0,258,259,1,0,0,
  	0,259,37,1,0,0,0,260,258,1,0,0,0,261,262,5,22,0,0,262,267,3,38,19,0,263,
  	264,5,26,0,0,264,267,3,38,19,0,265,267,3,40,20,0,266,261,1,0,0,0,266,
  	263,1,0,0,0,266,265,1,0,0,0,267,39,1,0,0,0,268,287,3,26,13,0,269,270,
  	5,30,0,0,270,271,5,14,0,0,271,272,3,42,21,0,272,273,5,15,0,0,273,287,
  	1,0,0,0,274,275,5,14,0,0,275,276,3,28,14,0,276,277,5,15,0,0,277,287,1,
  	0,0,0,278,287,5,31,0,0,279,287,5,32,0,0,280,281,3,26,13,0,281,282,5,24,
  	0,0,282,287,1,0,0,0,283,284,3,26,13,0,284,285,5,25,0,0,285,287,1,0,0,
  	0,286,268,1,0,0,0,286,269,1,0,0,0,286,274,1,0,0,0,286,278,1,0,0,0,286,
  	279,1,0,0,0,286,280,1,0,0,0,286,283,1,0,0,0,287,41,1,0,0,0,288,291,3,
  	44,22,0,289,291,1,0,0,0,290,288,1,0,0,0,290,289,1,0,0,0,291,43,1,0,0,
  	0,292,293,6,22,-1,0,293,294,3,30,15,0,294,300,1,0,0,0,295,296,10,2,0,
  	0,296,297,5,21,0,0,297,299,3,30,15,0,298,295,1,0,0,0,299,302,1,0,0,0,
  	300,298,1,0,0,0,300,301,1,0,0,0,301,45,1,0,0,0,302,300,1,0,0,0,25,55,
  	61,76,91,98,108,110,119,128,136,147,149,159,202,208,216,223,230,237,247,
  	258,266,286,290,300
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  csubsetParserStaticData = std::move(staticData);
}

}

CSubsetParser::CSubsetParser(TokenStream *input) : CSubsetParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CSubsetParser::CSubsetParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CSubsetParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *csubsetParserStaticData->atn, csubsetParserStaticData->decisionToDFA, csubsetParserStaticData->sharedContextCache, options);
}

CSubsetParser::~CSubsetParser() {
  delete _interpreter;
}

const atn::ATN& CSubsetParser::getATN() const {
  return *csubsetParserStaticData->atn;
}

std::string CSubsetParser::getGrammarFileName() const {
  return "CSubset.g4";
}

const std::vector<std::string>& CSubsetParser::getRuleNames() const {
  return csubsetParserStaticData->ruleNames;
}

const dfa::Vocabulary& CSubsetParser::getVocabulary() const {
  return csubsetParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CSubsetParser::getSerializedATN() const {
  return csubsetParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

CSubsetParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::StartContext::getRuleIndex() const {
  return CSubsetParser::RuleStart;
}

void CSubsetParser::StartContext::copyFrom(StartContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Start_ruleContext ------------------------------------------------------------------

CSubsetParser::ProgramContext* CSubsetParser::Start_ruleContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}

CSubsetParser::Start_ruleContext::Start_ruleContext(StartContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Start_ruleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart_rule(this);
}
void CSubsetParser::Start_ruleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart_rule(this);
}

std::any CSubsetParser::Start_ruleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStart_rule(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::StartContext* CSubsetParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, CSubsetParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<CSubsetParser::Start_ruleContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(46);
    program(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

CSubsetParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ProgramContext::getRuleIndex() const {
  return CSubsetParser::RuleProgram;
}

void CSubsetParser::ProgramContext::copyFrom(ProgramContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Program_to_unitContext ------------------------------------------------------------------

CSubsetParser::UnitContext* CSubsetParser::Program_to_unitContext::unit() {
  return getRuleContext<CSubsetParser::UnitContext>(0);
}

CSubsetParser::Program_to_unitContext::Program_to_unitContext(ProgramContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Program_to_unitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram_to_unit(this);
}
void CSubsetParser::Program_to_unitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram_to_unit(this);
}

std::any CSubsetParser::Program_to_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitProgram_to_unit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Program_to_program_unitContext ------------------------------------------------------------------

CSubsetParser::ProgramContext* CSubsetParser::Program_to_program_unitContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}

CSubsetParser::UnitContext* CSubsetParser::Program_to_program_unitContext::unit() {
  return getRuleContext<CSubsetParser::UnitContext>(0);
}

CSubsetParser::Program_to_program_unitContext::Program_to_program_unitContext(ProgramContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Program_to_program_unitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram_to_program_unit(this);
}
void CSubsetParser::Program_to_program_unitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram_to_program_unit(this);
}

std::any CSubsetParser::Program_to_program_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitProgram_to_program_unit(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::ProgramContext* CSubsetParser::program() {
   return program(0);
}

CSubsetParser::ProgramContext* CSubsetParser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  CSubsetParser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, CSubsetParser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Program_to_unitContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(49);
    unit();
    _ctx->stop = _input->LT(-1);
    setState(55);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Program_to_program_unitContext>(_tracker.createInstance<ProgramContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleProgram);
        setState(51);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(52);
        unit(); 
      }
      setState(57);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

CSubsetParser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::UnitContext::getRuleIndex() const {
  return CSubsetParser::RuleUnit;
}

void CSubsetParser::UnitContext::copyFrom(UnitContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Unit_to_var_declarationContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext* CSubsetParser::Unit_to_var_declarationContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

CSubsetParser::Unit_to_var_declarationContext::Unit_to_var_declarationContext(UnitContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Unit_to_var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit_to_var_declaration(this);
}
void CSubsetParser::Unit_to_var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit_to_var_declaration(this);
}

std::any CSubsetParser::Unit_to_var_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnit_to_var_declaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Unit_to_func_definitionContext ------------------------------------------------------------------

CSubsetParser::Func_definitionContext* CSubsetParser::Unit_to_func_definitionContext::func_definition() {
  return getRuleContext<CSubsetParser::Func_definitionContext>(0);
}

CSubsetParser::Unit_to_func_definitionContext::Unit_to_func_definitionContext(UnitContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Unit_to_func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit_to_func_definition(this);
}
void CSubsetParser::Unit_to_func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit_to_func_definition(this);
}

std::any CSubsetParser::Unit_to_func_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnit_to_func_definition(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Unit_to_func_declarationContext ------------------------------------------------------------------

CSubsetParser::Func_declarationContext* CSubsetParser::Unit_to_func_declarationContext::func_declaration() {
  return getRuleContext<CSubsetParser::Func_declarationContext>(0);
}

CSubsetParser::Unit_to_func_declarationContext::Unit_to_func_declarationContext(UnitContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Unit_to_func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit_to_func_declaration(this);
}
void CSubsetParser::Unit_to_func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit_to_func_declaration(this);
}

std::any CSubsetParser::Unit_to_func_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnit_to_func_declaration(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::UnitContext* CSubsetParser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, CSubsetParser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::Unit_to_var_declarationContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(58);
      var_declaration();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::Unit_to_func_declarationContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(59);
      func_declaration();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::Unit_to_func_definitionContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(60);
      func_definition();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

CSubsetParser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Func_declarationContext::getRuleIndex() const {
  return CSubsetParser::RuleFunc_declaration;
}

void CSubsetParser::Func_declarationContext::copyFrom(Func_declarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Func_declaration_with_paramContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::Func_declaration_with_paramContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::Func_declaration_with_paramContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::Func_declaration_with_paramContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::Func_declaration_with_paramContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Func_declaration_with_paramContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::Func_declaration_with_paramContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::Func_declaration_with_paramContext::Func_declaration_with_paramContext(Func_declarationContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Func_declaration_with_paramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration_with_param(this);
}
void CSubsetParser::Func_declaration_with_paramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration_with_param(this);
}

std::any CSubsetParser::Func_declaration_with_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunc_declaration_with_param(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Func_declaration_without_paramContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::Func_declaration_without_paramContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::Func_declaration_without_paramContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::Func_declaration_without_paramContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::Func_declaration_without_paramContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::Func_declaration_without_paramContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::Func_declaration_without_paramContext::Func_declaration_without_paramContext(Func_declarationContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Func_declaration_without_paramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration_without_param(this);
}
void CSubsetParser::Func_declaration_without_paramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration_without_param(this);
}

std::any CSubsetParser::Func_declaration_without_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunc_declaration_without_param(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Func_declarationContext* CSubsetParser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, CSubsetParser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::Func_declaration_with_paramContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(63);
      type_specifier();
      setState(64);
      match(CSubsetParser::ID);
      setState(65);
      match(CSubsetParser::LPAREN);
      setState(66);
      parameter_list(0);
      setState(67);
      match(CSubsetParser::RPAREN);
      setState(68);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::Func_declaration_without_paramContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(70);
      type_specifier();
      setState(71);
      match(CSubsetParser::ID);
      setState(72);
      match(CSubsetParser::LPAREN);
      setState(73);
      match(CSubsetParser::RPAREN);
      setState(74);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

CSubsetParser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Func_definitionContext::getRuleIndex() const {
  return CSubsetParser::RuleFunc_definition;
}

void CSubsetParser::Func_definitionContext::copyFrom(Func_definitionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Func_def_without_paramContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::Func_def_without_paramContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::Func_def_without_paramContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::Func_def_without_paramContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::Func_def_without_paramContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Compound_statementContext* CSubsetParser::Func_def_without_paramContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::Func_def_without_paramContext::Func_def_without_paramContext(Func_definitionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Func_def_without_paramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_def_without_param(this);
}
void CSubsetParser::Func_def_without_paramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_def_without_param(this);
}

std::any CSubsetParser::Func_def_without_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunc_def_without_param(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Func_def_with_paramContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::Func_def_with_paramContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::Func_def_with_paramContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::Func_def_with_paramContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::Func_def_with_paramContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Func_def_with_paramContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Compound_statementContext* CSubsetParser::Func_def_with_paramContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::Func_def_with_paramContext::Func_def_with_paramContext(Func_definitionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Func_def_with_paramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_def_with_param(this);
}
void CSubsetParser::Func_def_with_paramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_def_with_param(this);
}

std::any CSubsetParser::Func_def_with_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunc_def_with_param(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Func_definitionContext* CSubsetParser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, CSubsetParser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(91);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::Func_def_with_paramContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(78);
      type_specifier();
      setState(79);
      match(CSubsetParser::ID);
      setState(80);
      match(CSubsetParser::LPAREN);
      setState(81);
      parameter_list(0);
      setState(82);
      match(CSubsetParser::RPAREN);
      setState(83);
      compound_statement();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::Func_def_without_paramContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(85);
      type_specifier();
      setState(86);
      match(CSubsetParser::ID);
      setState(87);
      match(CSubsetParser::LPAREN);
      setState(88);
      match(CSubsetParser::RPAREN);
      setState(89);
      compound_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Parameter_listContext::getRuleIndex() const {
  return CSubsetParser::RuleParameter_list;
}

void CSubsetParser::Parameter_listContext::copyFrom(Parameter_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Single_param_with_idContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::Single_param_with_idContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::Single_param_with_idContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::Single_param_with_idContext::Single_param_with_idContext(Parameter_listContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Single_param_with_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_param_with_id(this);
}
void CSubsetParser::Single_param_with_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_param_with_id(this);
}

std::any CSubsetParser::Single_param_with_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSingle_param_with_id(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Multiple_param_without_idContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext* CSubsetParser::Multiple_param_without_idContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Multiple_param_without_idContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Type_specifierContext* CSubsetParser::Multiple_param_without_idContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::Multiple_param_without_idContext::Multiple_param_without_idContext(Parameter_listContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Multiple_param_without_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiple_param_without_id(this);
}
void CSubsetParser::Multiple_param_without_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiple_param_without_id(this);
}

std::any CSubsetParser::Multiple_param_without_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitMultiple_param_without_id(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Multiple_param_with_idContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext* CSubsetParser::Multiple_param_with_idContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Multiple_param_with_idContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Type_specifierContext* CSubsetParser::Multiple_param_with_idContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::Multiple_param_with_idContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::Multiple_param_with_idContext::Multiple_param_with_idContext(Parameter_listContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Multiple_param_with_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiple_param_with_id(this);
}
void CSubsetParser::Multiple_param_with_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiple_param_with_id(this);
}

std::any CSubsetParser::Multiple_param_with_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitMultiple_param_with_id(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Single_param_without_idContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::Single_param_without_idContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::Single_param_without_idContext::Single_param_without_idContext(Parameter_listContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Single_param_without_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_param_without_id(this);
}
void CSubsetParser::Single_param_without_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_param_without_id(this);
}

std::any CSubsetParser::Single_param_without_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSingle_param_without_id(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Parameter_listContext* CSubsetParser::parameter_list() {
   return parameter_list(0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  CSubsetParser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, CSubsetParser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(98);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Single_param_with_idContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(94);
      type_specifier();
      setState(95);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Single_param_without_idContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      type_specifier();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(110);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(108);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Multiple_param_with_idContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(100);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(101);
          match(CSubsetParser::COMMA);
          setState(102);
          type_specifier();
          setState(103);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Multiple_param_without_idContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(105);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(106);
          match(CSubsetParser::COMMA);
          setState(107);
          type_specifier();
          break;
        }

        default:
          break;
        } 
      }
      setState(112);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

CSubsetParser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Compound_statementContext::getRuleIndex() const {
  return CSubsetParser::RuleCompound_statement;
}

void CSubsetParser::Compound_statementContext::copyFrom(Compound_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Compound_with_statementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Compound_with_statementContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

CSubsetParser::StatementsContext* CSubsetParser::Compound_with_statementContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

tree::TerminalNode* CSubsetParser::Compound_with_statementContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}

CSubsetParser::Compound_with_statementContext::Compound_with_statementContext(Compound_statementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Compound_with_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_with_statement(this);
}
void CSubsetParser::Compound_with_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_with_statement(this);
}

std::any CSubsetParser::Compound_with_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompound_with_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Compound_without_statementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Compound_without_statementContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

tree::TerminalNode* CSubsetParser::Compound_without_statementContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}

CSubsetParser::Compound_without_statementContext::Compound_without_statementContext(Compound_statementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Compound_without_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_without_statement(this);
}
void CSubsetParser::Compound_without_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_without_statement(this);
}

std::any CSubsetParser::Compound_without_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompound_without_statement(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Compound_statementContext* CSubsetParser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, CSubsetParser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::Compound_with_statementContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(113);
      match(CSubsetParser::LCURL);
      setState(114);
      statements(0);
      setState(115);
      match(CSubsetParser::RCURL);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::Compound_without_statementContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(117);
      match(CSubsetParser::LCURL);
      setState(118);
      match(CSubsetParser::RCURL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Type_specifierContext* CSubsetParser::Var_declarationContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::Var_declarationContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Var_declarationContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}


size_t CSubsetParser::Var_declarationContext::getRuleIndex() const {
  return CSubsetParser::RuleVar_declaration;
}

void CSubsetParser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void CSubsetParser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}


std::any CSubsetParser::Var_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVar_declaration(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Var_declarationContext* CSubsetParser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, CSubsetParser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    type_specifier();
    setState(122);
    declaration_list(0);
    setState(123);
    match(CSubsetParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Type_specifierContext::getRuleIndex() const {
  return CSubsetParser::RuleType_specifier;
}

void CSubsetParser::Type_specifierContext::copyFrom(Type_specifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VoidTypeContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::VoidTypeContext::VOID() {
  return getToken(CSubsetParser::VOID, 0);
}

CSubsetParser::VoidTypeContext::VoidTypeContext(Type_specifierContext *ctx) { copyFrom(ctx); }

void CSubsetParser::VoidTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoidType(this);
}
void CSubsetParser::VoidTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoidType(this);
}

std::any CSubsetParser::VoidTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVoidType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntTypeContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::IntTypeContext::INT() {
  return getToken(CSubsetParser::INT, 0);
}

CSubsetParser::IntTypeContext::IntTypeContext(Type_specifierContext *ctx) { copyFrom(ctx); }

void CSubsetParser::IntTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntType(this);
}
void CSubsetParser::IntTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntType(this);
}

std::any CSubsetParser::IntTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitIntType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatTypeContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FloatTypeContext::FLOAT() {
  return getToken(CSubsetParser::FLOAT, 0);
}

CSubsetParser::FloatTypeContext::FloatTypeContext(Type_specifierContext *ctx) { copyFrom(ctx); }

void CSubsetParser::FloatTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatType(this);
}
void CSubsetParser::FloatTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatType(this);
}

std::any CSubsetParser::FloatTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFloatType(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Type_specifierContext* CSubsetParser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 16, CSubsetParser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(128);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::INT: {
        _localctx = _tracker.createInstance<CSubsetParser::IntTypeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(125);
        match(CSubsetParser::INT);
        break;
      }

      case CSubsetParser::FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::FloatTypeContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(126);
        match(CSubsetParser::FLOAT);
        break;
      }

      case CSubsetParser::VOID: {
        _localctx = _tracker.createInstance<CSubsetParser::VoidTypeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(127);
        match(CSubsetParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Declaration_listContext::getRuleIndex() const {
  return CSubsetParser::RuleDeclaration_list;
}

void CSubsetParser::Declaration_listContext::copyFrom(Declaration_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SiglArrDeclContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::SiglArrDeclContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::SiglArrDeclContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::SiglArrDeclContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::SiglArrDeclContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::SiglArrDeclContext::SiglArrDeclContext(Declaration_listContext *ctx) { copyFrom(ctx); }

void CSubsetParser::SiglArrDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSiglArrDecl(this);
}
void CSubsetParser::SiglArrDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSiglArrDecl(this);
}

std::any CSubsetParser::SiglArrDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSiglArrDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SiglVarDeclContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::SiglVarDeclContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::SiglVarDeclContext::SiglVarDeclContext(Declaration_listContext *ctx) { copyFrom(ctx); }

void CSubsetParser::SiglVarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSiglVarDecl(this);
}
void CSubsetParser::SiglVarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSiglVarDecl(this);
}

std::any CSubsetParser::SiglVarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSiglVarDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiVarDeclContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext* CSubsetParser::MultiVarDeclContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::MultiVarDeclContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

tree::TerminalNode* CSubsetParser::MultiVarDeclContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::MultiVarDeclContext::MultiVarDeclContext(Declaration_listContext *ctx) { copyFrom(ctx); }

void CSubsetParser::MultiVarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiVarDecl(this);
}
void CSubsetParser::MultiVarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiVarDecl(this);
}

std::any CSubsetParser::MultiVarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitMultiVarDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiVarDeclWithArrContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext* CSubsetParser::MultiVarDeclWithArrContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::MultiVarDeclWithArrContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

tree::TerminalNode* CSubsetParser::MultiVarDeclWithArrContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::MultiVarDeclWithArrContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::MultiVarDeclWithArrContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::MultiVarDeclWithArrContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::MultiVarDeclWithArrContext::MultiVarDeclWithArrContext(Declaration_listContext *ctx) { copyFrom(ctx); }

void CSubsetParser::MultiVarDeclWithArrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiVarDeclWithArr(this);
}
void CSubsetParser::MultiVarDeclWithArrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiVarDeclWithArr(this);
}

std::any CSubsetParser::MultiVarDeclWithArrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitMultiVarDeclWithArr(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list() {
   return declaration_list(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  CSubsetParser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, CSubsetParser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SiglVarDeclContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(131);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SiglArrDeclContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(132);
      match(CSubsetParser::ID);
      setState(133);
      match(CSubsetParser::LTHIRD);
      setState(134);
      match(CSubsetParser::CONST_INT);
      setState(135);
      match(CSubsetParser::RTHIRD);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(149);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(147);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiVarDeclContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(138);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(139);
          match(CSubsetParser::COMMA);
          setState(140);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MultiVarDeclWithArrContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(141);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(142);
          match(CSubsetParser::COMMA);
          setState(143);
          match(CSubsetParser::ID);
          setState(144);
          match(CSubsetParser::LTHIRD);
          setState(145);
          match(CSubsetParser::CONST_INT);
          setState(146);
          match(CSubsetParser::RTHIRD);
          break;
        }

        default:
          break;
        } 
      }
      setState(151);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

CSubsetParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::StatementsContext::getRuleIndex() const {
  return CSubsetParser::RuleStatements;
}

void CSubsetParser::StatementsContext::copyFrom(StatementsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Multiple_statementContext ------------------------------------------------------------------

CSubsetParser::StatementsContext* CSubsetParser::Multiple_statementContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

CSubsetParser::StatementContext* CSubsetParser::Multiple_statementContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::Multiple_statementContext::Multiple_statementContext(StatementsContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Multiple_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiple_statement(this);
}
void CSubsetParser::Multiple_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiple_statement(this);
}

std::any CSubsetParser::Multiple_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitMultiple_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Single_statementContext ------------------------------------------------------------------

CSubsetParser::StatementContext* CSubsetParser::Single_statementContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::Single_statementContext::Single_statementContext(StatementsContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Single_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_statement(this);
}
void CSubsetParser::Single_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_statement(this);
}

std::any CSubsetParser::Single_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSingle_statement(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::StatementsContext* CSubsetParser::statements() {
   return statements(0);
}

CSubsetParser::StatementsContext* CSubsetParser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  CSubsetParser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, CSubsetParser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Single_statementContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(153);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(159);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Multiple_statementContext>(_tracker.createInstance<StatementsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleStatements);
        setState(155);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(156);
        statement(); 
      }
      setState(161);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CSubsetParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::StatementContext::getRuleIndex() const {
  return CSubsetParser::RuleStatement;
}

void CSubsetParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Expression_statement_statementContext ------------------------------------------------------------------

CSubsetParser::Expression_statementContext* CSubsetParser::Expression_statement_statementContext::expression_statement() {
  return getRuleContext<CSubsetParser::Expression_statementContext>(0);
}

CSubsetParser::Expression_statement_statementContext::Expression_statement_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Expression_statement_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement_statement(this);
}
void CSubsetParser::Expression_statement_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement_statement(this);
}

std::any CSubsetParser::Expression_statement_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpression_statement_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Println_statementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Println_statementContext::PRINTLN() {
  return getToken(CSubsetParser::PRINTLN, 0);
}

tree::TerminalNode* CSubsetParser::Println_statementContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::Println_statementContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::Println_statementContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::Println_statementContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::Println_statementContext::Println_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Println_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintln_statement(this);
}
void CSubsetParser::Println_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintln_statement(this);
}

std::any CSubsetParser::Println_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitPrintln_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- For_statementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::For_statementContext::FOR() {
  return getToken(CSubsetParser::FOR, 0);
}

tree::TerminalNode* CSubsetParser::For_statementContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

std::vector<CSubsetParser::Expression_statementContext *> CSubsetParser::For_statementContext::expression_statement() {
  return getRuleContexts<CSubsetParser::Expression_statementContext>();
}

CSubsetParser::Expression_statementContext* CSubsetParser::For_statementContext::expression_statement(size_t i) {
  return getRuleContext<CSubsetParser::Expression_statementContext>(i);
}

CSubsetParser::ExpressionContext* CSubsetParser::For_statementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::For_statementContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::StatementContext* CSubsetParser::For_statementContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::For_statementContext::For_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::For_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_statement(this);
}
void CSubsetParser::For_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_statement(this);
}

std::any CSubsetParser::For_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFor_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- If_else_statementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::If_else_statementContext::IF() {
  return getToken(CSubsetParser::IF, 0);
}

tree::TerminalNode* CSubsetParser::If_else_statementContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::If_else_statementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::If_else_statementContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

std::vector<CSubsetParser::StatementContext *> CSubsetParser::If_else_statementContext::statement() {
  return getRuleContexts<CSubsetParser::StatementContext>();
}

CSubsetParser::StatementContext* CSubsetParser::If_else_statementContext::statement(size_t i) {
  return getRuleContext<CSubsetParser::StatementContext>(i);
}

tree::TerminalNode* CSubsetParser::If_else_statementContext::ELSE() {
  return getToken(CSubsetParser::ELSE, 0);
}

CSubsetParser::If_else_statementContext::If_else_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::If_else_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_else_statement(this);
}
void CSubsetParser::If_else_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_else_statement(this);
}

std::any CSubsetParser::If_else_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitIf_else_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Compound_statement_statementContext ------------------------------------------------------------------

CSubsetParser::Compound_statementContext* CSubsetParser::Compound_statement_statementContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::Compound_statement_statementContext::Compound_statement_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Compound_statement_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement_statement(this);
}
void CSubsetParser::Compound_statement_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement_statement(this);
}

std::any CSubsetParser::Compound_statement_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompound_statement_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- If_statementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::If_statementContext::IF() {
  return getToken(CSubsetParser::IF, 0);
}

tree::TerminalNode* CSubsetParser::If_statementContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::If_statementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::If_statementContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::StatementContext* CSubsetParser::If_statementContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::If_statementContext::If_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::If_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_statement(this);
}
void CSubsetParser::If_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_statement(this);
}

std::any CSubsetParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- While_statementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::While_statementContext::WHILE() {
  return getToken(CSubsetParser::WHILE, 0);
}

tree::TerminalNode* CSubsetParser::While_statementContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::While_statementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::While_statementContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::StatementContext* CSubsetParser::While_statementContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::While_statementContext::While_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::While_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_statement(this);
}
void CSubsetParser::While_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_statement(this);
}

std::any CSubsetParser::While_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitWhile_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Var_declaration_statementContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext* CSubsetParser::Var_declaration_statementContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

CSubsetParser::Var_declaration_statementContext::Var_declaration_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Var_declaration_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration_statement(this);
}
void CSubsetParser::Var_declaration_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration_statement(this);
}

std::any CSubsetParser::Var_declaration_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVar_declaration_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Return_statementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Return_statementContext::RETURN() {
  return getToken(CSubsetParser::RETURN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::Return_statementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::Return_statementContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::Return_statementContext::Return_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Return_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_statement(this);
}
void CSubsetParser::Return_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_statement(this);
}

std::any CSubsetParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::StatementContext* CSubsetParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, CSubsetParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(202);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::Var_declaration_statementContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(162);
      var_declaration();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::Println_statementContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(163);
      match(CSubsetParser::PRINTLN);
      setState(164);
      match(CSubsetParser::LPAREN);
      setState(165);
      match(CSubsetParser::ID);
      setState(166);
      match(CSubsetParser::RPAREN);
      setState(167);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::Expression_statement_statementContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(168);
      expression_statement();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::Compound_statement_statementContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(169);
      compound_statement();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubsetParser::For_statementContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(170);
      match(CSubsetParser::FOR);
      setState(171);
      match(CSubsetParser::LPAREN);
      setState(172);
      expression_statement();
      setState(173);
      expression_statement();
      setState(174);
      expression();
      setState(175);
      match(CSubsetParser::RPAREN);
      setState(176);
      statement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubsetParser::If_statementContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(178);
      match(CSubsetParser::IF);
      setState(179);
      match(CSubsetParser::LPAREN);
      setState(180);
      expression();
      setState(181);
      match(CSubsetParser::RPAREN);
      setState(182);
      statement();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubsetParser::If_else_statementContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(184);
      match(CSubsetParser::IF);
      setState(185);
      match(CSubsetParser::LPAREN);
      setState(186);
      expression();
      setState(187);
      match(CSubsetParser::RPAREN);
      setState(188);
      statement();
      setState(189);
      match(CSubsetParser::ELSE);
      setState(190);
      statement();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<CSubsetParser::While_statementContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(192);
      match(CSubsetParser::WHILE);
      setState(193);
      match(CSubsetParser::LPAREN);
      setState(194);
      expression();
      setState(195);
      match(CSubsetParser::RPAREN);
      setState(196);
      statement();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<CSubsetParser::Return_statementContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(198);
      match(CSubsetParser::RETURN);
      setState(199);
      expression();
      setState(200);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

CSubsetParser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Expression_statementContext::getRuleIndex() const {
  return CSubsetParser::RuleExpression_statement;
}

void CSubsetParser::Expression_statementContext::copyFrom(Expression_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Expression_statement_to_expression_semicolonContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext* CSubsetParser::Expression_statement_to_expression_semicolonContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::Expression_statement_to_expression_semicolonContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::Expression_statement_to_expression_semicolonContext::Expression_statement_to_expression_semicolonContext(Expression_statementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Expression_statement_to_expression_semicolonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement_to_expression_semicolon(this);
}
void CSubsetParser::Expression_statement_to_expression_semicolonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement_to_expression_semicolon(this);
}

std::any CSubsetParser::Expression_statement_to_expression_semicolonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpression_statement_to_expression_semicolon(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expression_statement_to_semicolonContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Expression_statement_to_semicolonContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::Expression_statement_to_semicolonContext::Expression_statement_to_semicolonContext(Expression_statementContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Expression_statement_to_semicolonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement_to_semicolon(this);
}
void CSubsetParser::Expression_statement_to_semicolonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement_to_semicolon(this);
}

std::any CSubsetParser::Expression_statement_to_semicolonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpression_statement_to_semicolon(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Expression_statementContext* CSubsetParser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 24, CSubsetParser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::SEMICOLON: {
        _localctx = _tracker.createInstance<CSubsetParser::Expression_statement_to_semicolonContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(204);
        match(CSubsetParser::SEMICOLON);
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::ADDOP:
      case CSubsetParser::NOT:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::Expression_statement_to_expression_semicolonContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(205);
        expression();
        setState(206);
        match(CSubsetParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

CSubsetParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::VariableContext::getRuleIndex() const {
  return CSubsetParser::RuleVariable;
}

void CSubsetParser::VariableContext::copyFrom(VariableContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrVarContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ArrVarContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::ArrVarContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::ArrVarContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::ArrVarContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::ArrVarContext::ArrVarContext(VariableContext *ctx) { copyFrom(ctx); }

void CSubsetParser::ArrVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrVar(this);
}
void CSubsetParser::ArrVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrVar(this);
}

std::any CSubsetParser::ArrVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArrVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SimpleVarContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::SimpleVarContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::SimpleVarContext::SimpleVarContext(VariableContext *ctx) { copyFrom(ctx); }

void CSubsetParser::SimpleVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleVar(this);
}
void CSubsetParser::SimpleVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleVar(this);
}

std::any CSubsetParser::SimpleVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSimpleVar(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::VariableContext* CSubsetParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 26, CSubsetParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(216);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::SimpleVarContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(210);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::ArrVarContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(211);
      match(CSubsetParser::ID);
      setState(212);
      match(CSubsetParser::LTHIRD);
      setState(213);
      expression();
      setState(214);
      match(CSubsetParser::RTHIRD);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ExpressionContext::getRuleIndex() const {
  return CSubsetParser::RuleExpression;
}

void CSubsetParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Expression_to_logic_expressionContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext* CSubsetParser::Expression_to_logic_expressionContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::Expression_to_logic_expressionContext::Expression_to_logic_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Expression_to_logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_to_logic_expression(this);
}
void CSubsetParser::Expression_to_logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_to_logic_expression(this);
}

std::any CSubsetParser::Expression_to_logic_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpression_to_logic_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expression_to_logic_expression_with_assignopContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::Expression_to_logic_expression_with_assignopContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::Expression_to_logic_expression_with_assignopContext::ASSIGNOP() {
  return getToken(CSubsetParser::ASSIGNOP, 0);
}

CSubsetParser::Logic_expressionContext* CSubsetParser::Expression_to_logic_expression_with_assignopContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::Expression_to_logic_expression_with_assignopContext::Expression_to_logic_expression_with_assignopContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Expression_to_logic_expression_with_assignopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_to_logic_expression_with_assignop(this);
}
void CSubsetParser::Expression_to_logic_expression_with_assignopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_to_logic_expression_with_assignop(this);
}

std::any CSubsetParser::Expression_to_logic_expression_with_assignopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpression_to_logic_expression_with_assignop(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::ExpressionContext* CSubsetParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, CSubsetParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::Expression_to_logic_expressionContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(218);
      logic_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::Expression_to_logic_expression_with_assignopContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(219);
      variable();
      setState(220);
      match(CSubsetParser::ASSIGNOP);
      setState(221);
      logic_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Logic_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleLogic_expression;
}

void CSubsetParser::Logic_expressionContext::copyFrom(Logic_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Logic_to_rel_expression_simpleContext ------------------------------------------------------------------

CSubsetParser::Rel_expressionContext* CSubsetParser::Logic_to_rel_expression_simpleContext::rel_expression() {
  return getRuleContext<CSubsetParser::Rel_expressionContext>(0);
}

CSubsetParser::Logic_to_rel_expression_simpleContext::Logic_to_rel_expression_simpleContext(Logic_expressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Logic_to_rel_expression_simpleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_to_rel_expression_simple(this);
}
void CSubsetParser::Logic_to_rel_expression_simpleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_to_rel_expression_simple(this);
}

std::any CSubsetParser::Logic_to_rel_expression_simpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitLogic_to_rel_expression_simple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Logic_to_rel_expression_complexContext ------------------------------------------------------------------

std::vector<CSubsetParser::Rel_expressionContext *> CSubsetParser::Logic_to_rel_expression_complexContext::rel_expression() {
  return getRuleContexts<CSubsetParser::Rel_expressionContext>();
}

CSubsetParser::Rel_expressionContext* CSubsetParser::Logic_to_rel_expression_complexContext::rel_expression(size_t i) {
  return getRuleContext<CSubsetParser::Rel_expressionContext>(i);
}

tree::TerminalNode* CSubsetParser::Logic_to_rel_expression_complexContext::LOGICOP() {
  return getToken(CSubsetParser::LOGICOP, 0);
}

CSubsetParser::Logic_to_rel_expression_complexContext::Logic_to_rel_expression_complexContext(Logic_expressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Logic_to_rel_expression_complexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_to_rel_expression_complex(this);
}
void CSubsetParser::Logic_to_rel_expression_complexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_to_rel_expression_complex(this);
}

std::any CSubsetParser::Logic_to_rel_expression_complexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitLogic_to_rel_expression_complex(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Logic_expressionContext* CSubsetParser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 30, CSubsetParser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(230);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::Logic_to_rel_expression_simpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(225);
      rel_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::Logic_to_rel_expression_complexContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(226);
      rel_expression();
      setState(227);
      match(CSubsetParser::LOGICOP);
      setState(228);
      rel_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

CSubsetParser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Rel_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleRel_expression;
}

void CSubsetParser::Rel_expressionContext::copyFrom(Rel_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Rel_expression_simple_expresssion_simpleContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext* CSubsetParser::Rel_expression_simple_expresssion_simpleContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

CSubsetParser::Rel_expression_simple_expresssion_simpleContext::Rel_expression_simple_expresssion_simpleContext(Rel_expressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Rel_expression_simple_expresssion_simpleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression_simple_expresssion_simple(this);
}
void CSubsetParser::Rel_expression_simple_expresssion_simpleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression_simple_expresssion_simple(this);
}

std::any CSubsetParser::Rel_expression_simple_expresssion_simpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitRel_expression_simple_expresssion_simple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Rel_expression_simple_expresssion_complexContext ------------------------------------------------------------------

std::vector<CSubsetParser::Simple_expressionContext *> CSubsetParser::Rel_expression_simple_expresssion_complexContext::simple_expression() {
  return getRuleContexts<CSubsetParser::Simple_expressionContext>();
}

CSubsetParser::Simple_expressionContext* CSubsetParser::Rel_expression_simple_expresssion_complexContext::simple_expression(size_t i) {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(i);
}

tree::TerminalNode* CSubsetParser::Rel_expression_simple_expresssion_complexContext::RELOP() {
  return getToken(CSubsetParser::RELOP, 0);
}

CSubsetParser::Rel_expression_simple_expresssion_complexContext::Rel_expression_simple_expresssion_complexContext(Rel_expressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Rel_expression_simple_expresssion_complexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression_simple_expresssion_complex(this);
}
void CSubsetParser::Rel_expression_simple_expresssion_complexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression_simple_expresssion_complex(this);
}

std::any CSubsetParser::Rel_expression_simple_expresssion_complexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitRel_expression_simple_expresssion_complex(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Rel_expressionContext* CSubsetParser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, CSubsetParser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(237);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::Rel_expression_simple_expresssion_simpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(232);
      simple_expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::Rel_expression_simple_expresssion_complexContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(233);
      simple_expression(0);
      setState(234);
      match(CSubsetParser::RELOP);
      setState(235);
      simple_expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Simple_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleSimple_expression;
}

void CSubsetParser::Simple_expressionContext::copyFrom(Simple_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Simple_expression_to_termContext ------------------------------------------------------------------

CSubsetParser::TermContext* CSubsetParser::Simple_expression_to_termContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

CSubsetParser::Simple_expression_to_termContext::Simple_expression_to_termContext(Simple_expressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Simple_expression_to_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression_to_term(this);
}
void CSubsetParser::Simple_expression_to_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression_to_term(this);
}

std::any CSubsetParser::Simple_expression_to_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSimple_expression_to_term(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Simple_expression_to_term_with_plusContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext* CSubsetParser::Simple_expression_to_term_with_plusContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

tree::TerminalNode* CSubsetParser::Simple_expression_to_term_with_plusContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::TermContext* CSubsetParser::Simple_expression_to_term_with_plusContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

CSubsetParser::Simple_expression_to_term_with_plusContext::Simple_expression_to_term_with_plusContext(Simple_expressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Simple_expression_to_term_with_plusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression_to_term_with_plus(this);
}
void CSubsetParser::Simple_expression_to_term_with_plusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression_to_term_with_plus(this);
}

std::any CSubsetParser::Simple_expression_to_term_with_plusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSimple_expression_to_term_with_plus(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::simple_expression() {
   return simple_expression(0);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  CSubsetParser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CSubsetParser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Simple_expression_to_termContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(240);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(247);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Simple_expression_to_term_with_plusContext>(_tracker.createInstance<Simple_expressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleSimple_expression);
        setState(242);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(243);
        match(CSubsetParser::ADDOP);
        setState(244);
        term(0); 
      }
      setState(249);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

CSubsetParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::TermContext::getRuleIndex() const {
  return CSubsetParser::RuleTerm;
}

void CSubsetParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Term_times_unary_expressionContext ------------------------------------------------------------------

CSubsetParser::TermContext* CSubsetParser::Term_times_unary_expressionContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

tree::TerminalNode* CSubsetParser::Term_times_unary_expressionContext::MULOP() {
  return getToken(CSubsetParser::MULOP, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::Term_times_unary_expressionContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::Term_times_unary_expressionContext::Term_times_unary_expressionContext(TermContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Term_times_unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm_times_unary_expression(this);
}
void CSubsetParser::Term_times_unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm_times_unary_expression(this);
}

std::any CSubsetParser::Term_times_unary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTerm_times_unary_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Term_unary_expressionContext ------------------------------------------------------------------

CSubsetParser::Unary_expressionContext* CSubsetParser::Term_unary_expressionContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::Term_unary_expressionContext::Term_unary_expressionContext(TermContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Term_unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm_unary_expression(this);
}
void CSubsetParser::Term_unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm_unary_expression(this);
}

std::any CSubsetParser::Term_unary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTerm_unary_expression(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::TermContext* CSubsetParser::term() {
   return term(0);
}

CSubsetParser::TermContext* CSubsetParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  CSubsetParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, CSubsetParser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Term_unary_expressionContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(251);
    unary_expression();
    _ctx->stop = _input->LT(-1);
    setState(258);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Term_times_unary_expressionContext>(_tracker.createInstance<TermContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTerm);
        setState(253);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(254);
        match(CSubsetParser::MULOP);
        setState(255);
        unary_expression(); 
      }
      setState(260);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

CSubsetParser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Unary_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleUnary_expression;
}

void CSubsetParser::Unary_expressionContext::copyFrom(Unary_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Unary_expression_to_factorContext ------------------------------------------------------------------

CSubsetParser::FactorContext* CSubsetParser::Unary_expression_to_factorContext::factor() {
  return getRuleContext<CSubsetParser::FactorContext>(0);
}

CSubsetParser::Unary_expression_to_factorContext::Unary_expression_to_factorContext(Unary_expressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Unary_expression_to_factorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression_to_factor(this);
}
void CSubsetParser::Unary_expression_to_factorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression_to_factor(this);
}

std::any CSubsetParser::Unary_expression_to_factorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnary_expression_to_factor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Unary_expression_notContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Unary_expression_notContext::NOT() {
  return getToken(CSubsetParser::NOT, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::Unary_expression_notContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::Unary_expression_notContext::Unary_expression_notContext(Unary_expressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Unary_expression_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression_not(this);
}
void CSubsetParser::Unary_expression_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression_not(this);
}

std::any CSubsetParser::Unary_expression_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnary_expression_not(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Unary_expression_addopContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Unary_expression_addopContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::Unary_expression_addopContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::Unary_expression_addopContext::Unary_expression_addopContext(Unary_expressionContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Unary_expression_addopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression_addop(this);
}
void CSubsetParser::Unary_expression_addopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression_addop(this);
}

std::any CSubsetParser::Unary_expression_addopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnary_expression_addop(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Unary_expressionContext* CSubsetParser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 38, CSubsetParser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(266);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::ADDOP: {
        _localctx = _tracker.createInstance<CSubsetParser::Unary_expression_addopContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(261);
        match(CSubsetParser::ADDOP);
        setState(262);
        unary_expression();
        break;
      }

      case CSubsetParser::NOT: {
        _localctx = _tracker.createInstance<CSubsetParser::Unary_expression_notContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(263);
        match(CSubsetParser::NOT);
        setState(264);
        unary_expression();
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::Unary_expression_to_factorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(265);
        factor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

CSubsetParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::FactorContext::getRuleIndex() const {
  return CSubsetParser::RuleFactor;
}

void CSubsetParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Factor_post_decrementContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::Factor_post_decrementContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::Factor_post_decrementContext::DECOP() {
  return getToken(CSubsetParser::DECOP, 0);
}

CSubsetParser::Factor_post_decrementContext::Factor_post_decrementContext(FactorContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Factor_post_decrementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor_post_decrement(this);
}
void CSubsetParser::Factor_post_decrementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor_post_decrement(this);
}

std::any CSubsetParser::Factor_post_decrementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactor_post_decrement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_to_variableContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::Factor_to_variableContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

CSubsetParser::Factor_to_variableContext::Factor_to_variableContext(FactorContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Factor_to_variableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor_to_variable(this);
}
void CSubsetParser::Factor_to_variableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor_to_variable(this);
}

std::any CSubsetParser::Factor_to_variableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactor_to_variable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_function_callContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Factor_function_callContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::Factor_function_callContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Argument_listContext* CSubsetParser::Factor_function_callContext::argument_list() {
  return getRuleContext<CSubsetParser::Argument_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Factor_function_callContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Factor_function_callContext::Factor_function_callContext(FactorContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Factor_function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor_function_call(this);
}
void CSubsetParser::Factor_function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor_function_call(this);
}

std::any CSubsetParser::Factor_function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactor_function_call(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_post_incrementContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::Factor_post_incrementContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::Factor_post_incrementContext::INCOP() {
  return getToken(CSubsetParser::INCOP, 0);
}

CSubsetParser::Factor_post_incrementContext::Factor_post_incrementContext(FactorContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Factor_post_incrementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor_post_increment(this);
}
void CSubsetParser::Factor_post_incrementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor_post_increment(this);
}

std::any CSubsetParser::Factor_post_incrementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactor_post_increment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_const_floatContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Factor_const_floatContext::CONST_FLOAT() {
  return getToken(CSubsetParser::CONST_FLOAT, 0);
}

CSubsetParser::Factor_const_floatContext::Factor_const_floatContext(FactorContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Factor_const_floatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor_const_float(this);
}
void CSubsetParser::Factor_const_floatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor_const_float(this);
}

std::any CSubsetParser::Factor_const_floatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactor_const_float(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_parenthesized_expressionContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Factor_parenthesized_expressionContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::Factor_parenthesized_expressionContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::Factor_parenthesized_expressionContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Factor_parenthesized_expressionContext::Factor_parenthesized_expressionContext(FactorContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Factor_parenthesized_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor_parenthesized_expression(this);
}
void CSubsetParser::Factor_parenthesized_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor_parenthesized_expression(this);
}

std::any CSubsetParser::Factor_parenthesized_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactor_parenthesized_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_const_intContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::Factor_const_intContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

CSubsetParser::Factor_const_intContext::Factor_const_intContext(FactorContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Factor_const_intContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor_const_int(this);
}
void CSubsetParser::Factor_const_intContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor_const_int(this);
}

std::any CSubsetParser::Factor_const_intContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactor_const_int(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::FactorContext* CSubsetParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 40, CSubsetParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::Factor_to_variableContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(268);
      variable();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::Factor_function_callContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(269);
      match(CSubsetParser::ID);
      setState(270);
      match(CSubsetParser::LPAREN);
      setState(271);
      argument_list();
      setState(272);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::Factor_parenthesized_expressionContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(274);
      match(CSubsetParser::LPAREN);
      setState(275);
      expression();
      setState(276);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::Factor_const_intContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(278);
      match(CSubsetParser::CONST_INT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubsetParser::Factor_const_floatContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(279);
      match(CSubsetParser::CONST_FLOAT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubsetParser::Factor_post_incrementContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(280);
      variable();
      setState(281);
      match(CSubsetParser::INCOP);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubsetParser::Factor_post_decrementContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(283);
      variable();
      setState(284);
      match(CSubsetParser::DECOP);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

CSubsetParser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Argument_listContext::getRuleIndex() const {
  return CSubsetParser::RuleArgument_list;
}

void CSubsetParser::Argument_listContext::copyFrom(Argument_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Arg_list_emptyContext ------------------------------------------------------------------

CSubsetParser::Arg_list_emptyContext::Arg_list_emptyContext(Argument_listContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Arg_list_emptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg_list_empty(this);
}
void CSubsetParser::Arg_list_emptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg_list_empty(this);
}

std::any CSubsetParser::Arg_list_emptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArg_list_empty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Arg_list_with_argsContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext* CSubsetParser::Arg_list_with_argsContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

CSubsetParser::Arg_list_with_argsContext::Arg_list_with_argsContext(Argument_listContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Arg_list_with_argsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg_list_with_args(this);
}
void CSubsetParser::Arg_list_with_argsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg_list_with_args(this);
}

std::any CSubsetParser::Arg_list_with_argsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArg_list_with_args(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Argument_listContext* CSubsetParser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 42, CSubsetParser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(290);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::LPAREN:
      case CSubsetParser::ADDOP:
      case CSubsetParser::NOT:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::Arg_list_with_argsContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(288);
        arguments(0);
        break;
      }

      case CSubsetParser::RPAREN: {
        _localctx = _tracker.createInstance<CSubsetParser::Arg_list_emptyContext>(_localctx);
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ArgumentsContext::getRuleIndex() const {
  return CSubsetParser::RuleArguments;
}

void CSubsetParser::ArgumentsContext::copyFrom(ArgumentsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Multi_argumentsContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext* CSubsetParser::Multi_argumentsContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

tree::TerminalNode* CSubsetParser::Multi_argumentsContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Logic_expressionContext* CSubsetParser::Multi_argumentsContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::Multi_argumentsContext::Multi_argumentsContext(ArgumentsContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Multi_argumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulti_arguments(this);
}
void CSubsetParser::Multi_argumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulti_arguments(this);
}

std::any CSubsetParser::Multi_argumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitMulti_arguments(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Single_argumentContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext* CSubsetParser::Single_argumentContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::Single_argumentContext::Single_argumentContext(ArgumentsContext *ctx) { copyFrom(ctx); }

void CSubsetParser::Single_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_argument(this);
}
void CSubsetParser::Single_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSubsetListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_argument(this);
}

std::any CSubsetParser::Single_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSingle_argument(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::ArgumentsContext* CSubsetParser::arguments() {
   return arguments(0);
}

CSubsetParser::ArgumentsContext* CSubsetParser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  CSubsetParser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, CSubsetParser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Single_argumentContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(293);
    logic_expression();
    _ctx->stop = _input->LT(-1);
    setState(300);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Multi_argumentsContext>(_tracker.createInstance<ArgumentsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleArguments);
        setState(295);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(296);
        match(CSubsetParser::COMMA);
        setState(297);
        logic_expression(); 
      }
      setState(302);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CSubsetParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 9: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 10: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 17: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 18: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 22: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void CSubsetParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  csubsetParserInitialize();
#else
  ::antlr4::internal::call_once(csubsetParserOnceFlag, csubsetParserInitialize);
#endif
}
