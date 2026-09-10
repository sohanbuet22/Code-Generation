#include <bits/stdc++.h>
#include "2205047_utils.h"
using namespace std;
using namespace chrono;

struct Parameter
{
    string type;
    string name;
};

class FunctionInfo
{
public:
    string returnType;
    string parameters;
    bool isDeclared;
    bool isDefined;

    FunctionInfo(string returnType, string parameters)
    {
        this->returnType = returnType;
        this->parameters = parameters;
        this->isDeclared = false;
        this->isDefined = false;
    }
};

class SymbolInfo
{
public:
    string name;
    string type;
    SymbolInfo *nextSymbol;
    string var_type;
    FunctionInfo *funcInfo;
    string arr_type;

    SymbolInfo(const string &name, const string &type)
    {
        this->name = name;
        this->type = type;
        this->nextSymbol = nullptr;
    }

    string getName()
    {
        return name;
    }
    string getType()
    {
        return type;
    }

    SymbolInfo *getNextSymbol()
    {
        return nextSymbol;
    }

    void setName(const string &name)
    {
        this->name = name;
    }
    void setType(const string &type)
    {
        this->type = type;
    }

    void setNextSymbol(SymbolInfo *nextSymbol)
    {
        this->nextSymbol = nextSymbol;
    }
};

struct SeparateChaining
{
    int size;
    function<unsigned long long(const string &, int)> hashFunc;

    SymbolInfo **buckets;

    SeparateChaining(int n, function<unsigned long long(const string &, int)> func) : size(n), hashFunc(func)
    {
        buckets = new SymbolInfo *[size];
        for (int i = 0; i < size; i++)
        {
            buckets[i] = nullptr;
        }
    }

    ~SeparateChaining()
    {
        for (int i = 0; i < size; i++)
        {
            SymbolInfo *current = buckets[i];
            while (current != nullptr)
            {
                SymbolInfo *temp = current;
                current = current->getNextSymbol();
                delete temp;
            }
        }
        delete[] buckets;
    }

    bool insert(SymbolInfo *symbol, int &bucketIndex, int &position)
    {
        int idx = hashFunc(symbol->getName(), size);
        bucketIndex = idx;
        position = 0;
        if (buckets[idx] == nullptr)
        {
            buckets[idx] = symbol;
            return true;
        }
        else
        {
            SymbolInfo *current = buckets[idx];
            SymbolInfo *prev = nullptr;
            while (current != nullptr)
            {
                if (current->getName() == symbol->getName())
                {
                    return false;
                }
                prev = current;
                current = current->getNextSymbol();
                position++;
            }
            prev->setNextSymbol(symbol);
            return true;
        }
    }

    SymbolInfo *search(string key, int &bucketIndex, int &position)
    {
        int idx = hashFunc(key, size);
        bucketIndex = idx + 1;
        position = 1;
        SymbolInfo *current = buckets[idx];
        while (current != nullptr)
        {
            if (current->getName() == key)
            {
                return current;
            }
            current = current->getNextSymbol();
            position++;
        }
        return nullptr;
    }

    bool deleteKey(string key, int &bucketIndex, int &position)
    {
        int idx = hashFunc(key, size);
        bucketIndex = idx + 1;
        position = 1;
        SymbolInfo *current = buckets[idx];
        SymbolInfo *prev = nullptr;
        while (current != nullptr)
        {
            if (current->getName() == key)
            {
                if (prev == nullptr)
                {
                    buckets[idx] = current->getNextSymbol();
                }
                else
                {
                    prev->setNextSymbol(current->getNextSymbol());
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->getNextSymbol();
            position++;
        }
        return false;
    }

    void print(ofstream &file)
    {
        for (int i = 0; i < size; i++)
        {
            SymbolInfo *current = buckets[i];
            if (current == nullptr)
                continue;
            file << " " << i << " --> ";
            while (current != nullptr)
            {
                file << "< " << current->getName() << " , " << "ID > ";
                current = current->getNextSymbol();
            }
            file << endl;
        }
        file << endl
             << endl;
    }
};
