
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_map>

static std::string trim(const std::string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == std::string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}


static bool parseInstr(const std::string& line, std::string& mnem,
                        std::string& op1, std::string& op2) {
    std::string t = trim(line);
    if (t.empty() || t.back() == ':' ) return false; // label
    if (t[0] == ';') return false;                    // comment
    std::istringstream iss(t);
    iss >> mnem;
    for (auto& c : mnem) c = toupper(c);
    std::string rest;
    std::getline(iss, rest);
    rest = trim(rest);
    size_t comma = rest.find(',');
    if (comma == std::string::npos) { op1 = rest; op2 = ""; }
    else { op1 = trim(rest.substr(0, comma)); op2 = trim(rest.substr(comma + 1)); }
    return true;
}

static bool isLabelLine(const std::string& line, std::string& labelName) {
    std::string t = trim(line);
    if (!t.empty() && t.back() == ':') {
        labelName = t.substr(0, t.size() - 1);
        return true;
    }
    return false;
}

void optimize(const std::string& inPath, const std::string& outPath) {
    std::ifstream in(inPath);
    std::vector<std::string> lines;
    std::string l;
    while (std::getline(in, l)) lines.push_back(l);


    std::vector<std::string> pass1;
    for (size_t i = 0; i < lines.size(); ++i) {
        std::string mnem, op1, op2, nmnem, nop1, nop2;
        bool isInstr = parseInstr(lines[i], mnem, op1, op2);

        if (isInstr && i + 1 < lines.size()) {
            bool nextIsInstr = parseInstr(lines[i + 1], nmnem, nop1, nop2);

            // (i) MOV a,b then MOV b,a -> drop the second
            if (isInstr && nextIsInstr && mnem == "MOV" && nmnem == "MOV" &&
                op1 == nop2 && op2 == nop1) {
                pass1.push_back(lines[i]);
                ++i; // skip the redundant second MOV
                continue;
            }
            // (ii) PUSH x then POP x -> drop both
            if (mnem == "PUSH" && nmnem == "POP" && op1 == nop1) {
                ++i; // skip both push and (about to skip) pop
                continue;
            }
            // (iii) ADD x,0 / SUB x,0 / MUL x,1 / IMUL x,1 -> drop this line
            if ((mnem == "ADD" || mnem == "SUB") && trim(op2) == "0") continue;
            if ((mnem == "MUL" || mnem == "IMUL") && trim(op2) == "1") continue;
        } else if (isInstr) {
            if ((mnem == "ADD" || mnem == "SUB") && trim(op2) == "0") continue;
            if ((mnem == "MUL" || mnem == "IMUL") && trim(op2) == "1") continue;
        }
        pass1.push_back(lines[i]);
    }

    
    std::vector<std::string> pass2;
    std::unordered_map<std::string, std::string> redirect; // dropped -> kept
    for (size_t i = 0; i < pass1.size(); ++i) {
        std::string lbl;
        if (isLabelLine(pass1[i], lbl)) {
            std::vector<std::string> group{lbl};
            size_t j = i + 1;
            std::string lbl2;
            while (j < pass1.size() && isLabelLine(pass1[j], lbl2)) {
                group.push_back(lbl2);
                ++j;
            }
            // keep the LAST label of the run (so any fallthrough code right
            // after keeps working, and earlier labels redirect to it)
            std::string kept = group.back();
            for (auto& g : group) if (g != kept) redirect[g] = kept;
            pass2.push_back(kept + ":");
            i = j - 1;
            continue;
        }
        pass2.push_back(pass1[i]);
    }

    // Apply redirects to jump targets (jmp/je/jne/... Lx)
    std::ofstream out(outPath);
    for (auto& line : pass2) {
        std::string mnem, op1, op2;
        if (parseInstr(line, mnem, op1, op2) &&
            (mnem.size() > 1 && mnem[0] == 'J')) {
            auto it = redirect.find(op1);
            if (it != redirect.end()) {
                out << line.substr(0, line.find(op1)) << it->second << "\n";
                continue;
            }
        }
        out << line << "\n";
    }
}

// Optional standalone main so you can run: ./peephole code.asm optimized_code.asm
#ifdef PEEPHOLE_STANDALONE
int main(int argc, char** argv) {
    if (argc != 3) { return 1; }
    optimize(argv[1], argv[2]);
    return 0;
}
#endif
