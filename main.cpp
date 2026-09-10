/*
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include "antlr4-runtime.h"
#include "CSubsetLexer.h"
#include "CSubsetParser.h"
#include "CSubsetImp.h"

using namespace antlr4;
using namespace std;

ofstream lexLogFile; // used by Lexer.g4's writeIntoLexLogFile()

// ANTLR's default error strategy can skip valid tokens after a malformed token.
// Normalize the three recoverable forms used by this C-subset grammar and retain
// their diagnostics for CSubsetImp, which writes them in log/error at rule time.
static string normalizeInput(const string &source) {
    istringstream in(source);
    ostringstream out;
    string line;
    int lineNo = 0;
    while (getline(in, line)) {
        ++lineNo;
        smatch match;
        regex unnamed(R"(^([ \t]*(?:int|float|void)[ \t]+[A-Za-z_][A-Za-z0-9_]*[ \t]*\([ \t]*(?:int|float|void))[ \t]*[+-][ \t]*(\)))");
        if (regex_search(line, match, unnamed)) {
            line.replace(match.position(0), match.length(0), match[1].str() + match[2].str());
            noteUnnamedParameter(lineNo);
        }
        regex declaration(R"(^([ \t]*(?:int|float|void)[ \t]+[A-Za-z_][A-Za-z0-9_]*[ \t]*)-[ \t]*[A-Za-z_][A-Za-z0-9_]*[ \t]*(?=,))");
        if (regex_search(line, match, declaration)) {
            line.replace(match.position(0), match.length(0), match[1].str());
            noteBadDeclaration(lineNo);
        }
        regex badAddAssign(R"(([A-Za-z_][A-Za-z0-9_]*[ \t]*=[ \t]*[0-9]+)[ \t]*\+[ \t]*=[ \t]*([0-9]+))");
        if (regex_search(line, match, badAddAssign)) {
            string lhs = match[1].str();
            string rhs = match[2].str();
            string compactLhs = regex_replace(lhs, regex(R"([ \t])"), "");
            line.replace(match.position(0), match.length(0), lhs + "; " + rhs);
            if (line.find(';', match.position(0) + lhs.size() + 2) == string::npos)
                line += ";";
            noteBadAddAssign(lineNo);
            noteMissingSemicolon(lineNo, compactLhs);
            noteMissingSemicolon(lineNo, rhs);
        }
        out << line;
        if (!in.eof()) out << '\n';
    }
    return out.str();
}

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    string source((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    ANTLRInputStream input(normalizeInput(source));
    CSubsetLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CSubsetParser parser(&tokens);

    CSubsetParser::StartContext* tree = parser.start();

    CSubsetBaseVisitor* visitor=new CSubsetImp();
    visitor->visit(tree);
    int totalLines = 0;
    for (char ch : source)
        if (ch == '\n')
            ++totalLines;
    if (!source.empty() && source.back() != '\n')
        ++totalLines;
    appendLogSummary(totalLines);

    cout << "Parsing completed." << endl;

    inputFile.close();
    return 0;
}

*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "antlr4-runtime.h"
#include "CSubsetLexer.h"
#include "CSubsetParser.h"
#include "CodeGenImp.h"   // Phase 1 code generator

using namespace antlr4;
using namespace std;

ofstream lexLogFile; // used by Lexer.g4's writeIntoLexLogFile()

// Declared in peephole.cpp. Compile peephole.cpp WITHOUT -DPEEPHOLE_STANDALONE
// when linking it into this binary (that macro adds its own main()).
void optimize(const string &inPath, const string &outPath);

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    string source((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

    // No normalizeInput() here -- that function exists only to patch up
    // specific malformed inputs the A3 grammar-recovery logic expects.
    // For pure codegen testing, feed it clean, valid C-subset source.
    ANTLRInputStream input(source);
    CSubsetLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CSubsetParser parser(&tokens);

    CSubsetParser::StartContext* tree = parser.start();
    // std::cout << tree->toStringTree(&parser) << std::endl;

    // ---- Phase 4: intermediate code generation only ----
    CodeGenEmitter emitter("temp_code.txt");
    CodeGenImp codeGen(emitter);
    codeGen.visit(tree);
    emitter.finalize("code.asm");
    optimize("code.asm", "optimized_code.asm");

    cout << "code.asm and optimized_code.asm generated." << endl;

    inputFile.close();
    return 0;
}