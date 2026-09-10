#include <iostream>
#include "2205047_HashTable.h"
using namespace std;

class ScopeTable
{

public:
    int n;
    SeparateChaining *table;
    ScopeTable *parentScope;
    string scopeId;
    int totalSubscope;
    static int globalId;

    ScopeTable(int n,ScopeTable *parentScope)
    {
        this->n = n;
        this->table = new SeparateChaining(n, SDBMHash);
        this->parentScope = parentScope;

        if(parentScope == nullptr)
        {
            this->scopeId = "1";
            this->totalSubscope=0;
            return;
        }
        parentScope->totalSubscope ++;
        this->scopeId = this->parentScope->getId() + "." + to_string(parentScope->totalSubscope);
        this->totalSubscope=0;
    }

    ~ScopeTable()
    {
        delete table;
    }

    bool insert(SymbolInfo *symbol, int &bucketIndex, int &position)
    {
        return table->insert(symbol, bucketIndex, position);
    }

    SymbolInfo *search(string key, int &bucketIndex, int &position)
    {
        return table->search(key, bucketIndex, position);
    }

    bool deleteKey(string key, int &bucketIndex, int &position)
    {
        return table->deleteKey(key, bucketIndex, position);
    }

    void print(ofstream& file)
    {
        file << "ScopeTable # " << scopeId << endl;
        table->print(file);
    }

    void setParentScope(ScopeTable *parentScope)
    {
        this->parentScope = parentScope;
    }

    ScopeTable *getParentScope()
    {
        return this->parentScope;
    }

    string getId()
    {
        return this->scopeId;
    }
};

int ScopeTable::globalId = 0;

class SymbolTable
{
    ScopeTable *currentScope;
    int n;

public:
    SymbolTable(int n)
    {
        this->n = n;
        this->currentScope = nullptr;
        enterScope();
    }

    ~SymbolTable()
    {
        while (currentScope != nullptr)
        {
            ScopeTable *temp = currentScope;
            currentScope = currentScope->getParentScope();
            delete temp;
        }
    }

    void enterScope()
    {
        ScopeTable *newScope = new ScopeTable(n,currentScope);
        currentScope = newScope;
    }

    void exitScope()
    {
        if (currentScope->getParentScope() == nullptr)
            return;
        ScopeTable *temp = currentScope;
        currentScope = currentScope->getParentScope();
        delete temp;
    }

    bool insert(SymbolInfo *symbol, int &bucketIndex, int &position)
    {
        return currentScope->insert(symbol, bucketIndex, position);
    }

    bool remove(string key, int &bucketIndex, int &position)
    {
        return currentScope->deleteKey(key, bucketIndex, position);
    }

    SymbolInfo *lookup(string key, int &bucketIndex, int &position, string &scopeId)
    {
        ScopeTable *temp = currentScope;
        while (temp != nullptr)
        {
            SymbolInfo *symbol = temp->search(key, bucketIndex, position);
            if (symbol != nullptr)
            {
                scopeId = temp->getId();
                return symbol;
            }
            temp = temp->getParentScope();
        }
        return nullptr;
    }

    void printCurrentScope(ofstream& file)
    {
        currentScope->print(file);
    }

    void printAllScopes(ofstream& file)
    {
        ScopeTable *temp = currentScope;
        // string indent = "";
        while (temp != nullptr)
        {
            temp->print(file);
            // indent += "\t";
            temp = temp->getParentScope();
        }
    }

    string getScopeId()
    {
        return currentScope->getId();
    }

    ScopeTable *getCurrentScope()
    {
        return currentScope;
    }

    void quitClean(ofstream &out)
    {
        while (currentScope != nullptr)
        {
            ScopeTable *temp = currentScope;
            out << "\tScopeTable# " << temp->getId() << " removed" << std::endl; //[cite: 2]
            currentScope = currentScope->getParentScope();
            delete temp;
        }
    }
};
/*
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: ./symbol_table <input_file> <output_file>" << std::endl;
        return 1;
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int n;
    fin >> n;
    fin.ignore();

    SymbolTable symbolTable(n);
    fout << "\tScopeTable# " << symbolTable.getScopeId() << " created" << endl;

    string line;
    int commandNumber = 1;

    while (getline(fin, line))
    {
        stringstream ss(line);

        string command;
        ss >> command;

        if (command == "I")
        {
            string name, type;
            ss >> name >> type;

            fout << "Cmd " << commandNumber++ << ": " << line << endl;

            if (name == "" || type == "")
            {
                fout << "\tNumber of parameters mismatch for the command I" << endl;
                continue;
            }

            string modifiedType = type;
            if (type == "FUNCTION")
            {
                string returnType;
                if (ss >> returnType)
                {
                    modifiedType += "," + returnType + "<==(";
                    string arg;
                    bool firstArg = true;
                    while (ss >> arg)
                    {
                        if (!firstArg)
                            modifiedType += ",";
                        modifiedType += arg;
                        firstArg = false;
                    }
                    modifiedType += ")";
                }
            }
            else if (type == "STRUCT" || type == "UNION")
            {
                modifiedType += ",{";
                string member_type, member_name;
                bool firstMember = true;
                while (ss >> member_type >> member_name)
                {
                    if (!firstMember)
                        modifiedType += ",";
                    modifiedType += "(" + member_type + "," + member_name + ")";
                    firstMember = false;
                }
                modifiedType += "}";
            }

            SymbolInfo *symbol = new SymbolInfo(name, modifiedType);

            int bucketIndex, position;

            if (symbolTable.insert(symbol, bucketIndex, position))
            {
                fout << "\tInserted in ScopeTable# " << symbolTable.getScopeId() << " at position " << bucketIndex << ", " << position << endl;
            }
            else
            {
                fout << "\t'" << name << "' already exists in the current ScopeTable" << endl;
                delete symbol;
            }
        }
        else if (command == "L")
        {
            string name;
            int bucketIndex, position, scopeId;
            ss >> name;
            string word;
            ss >> word;
            fout << "Cmd " << commandNumber++ << ": " << line << endl;
            if (name == "" || word != "")
            {
                fout << "\tNumber of parameters mismatch for the command " << command << endl;
            }
            else
            {
                SymbolInfo *symbol = symbolTable.lookup(name, bucketIndex, position, scopeId);
                if (symbol != nullptr)
                {
                    fout << "\t'" << name << "' found in ScopeTable# " << scopeId << " at position " << bucketIndex << ", " << position << endl;
                }
                else
                {
                    fout << "\t'" << name << "' not found in any of the ScopeTables" << endl;
                }
            }
        }
        else if (command == "D")
        {
            string name;
            ss >> name;
            string extra;
            ss >> extra;
            int bucketIndex, position;
            fout << "Cmd " << commandNumber++ << ": " << line << endl;
            if (name == "" || extra != "")
            {
                fout << "\tNumber of parameters mismatch for the command D" << endl;
                continue;
            }
            if (symbolTable.remove(name, bucketIndex, position))
            {
                fout << "\tDeleted '" << name << "' from ScopeTable# " << symbolTable.getScopeId() << " at position " << bucketIndex << ", " << position << endl;
            }
            else
            {
                fout << "\tNot found in the current ScopeTable" << endl;
            }
        }
        else if (command == "P")
        {
            string code;
            ss >> code;

            if (code == "A")
            {
                fout << "Cmd " << commandNumber++ << ": " << line << endl;
                symbolTable.printAllScopes(fout);
            }
            else if (code == "C")
            {
                fout << "Cmd " << commandNumber++ << ": " << line << endl;
                symbolTable.printCurrentScope(fout);
            }
        }
        else if (command == "S")
        {
            fout << "Cmd " << commandNumber++ << ": " << line << endl;
            symbolTable.enterScope();
            fout << "\tScopeTable# " << symbolTable.getScopeId() << " created" << endl;
        }
        else if (command == "E")
        {
            if (symbolTable.getCurrentScope()->getParentScope() == nullptr)
            {
                continue;
            }
            fout << "Cmd " << commandNumber++ << ": " << line << endl;
            int scopeId = symbolTable.getScopeId();
            symbolTable.exitScope();
            fout << "\tScopeTable# " << scopeId << " removed" << endl;
        }
        else if (command == "Q")
        {
            fout << "Cmd " << commandNumber++ << ": " << line << endl;
            symbolTable.quitClean(fout);
            break;
        }
        else
        {
            continue;
        }
    }
}

*/