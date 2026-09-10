#include<iostream>
using namespace std;

void print(string s,int a);
int isValidFloat(const string& s)
{
    if (s.empty())
        return 0;

    bool hasDigit = false;
    bool hasDot = false;
    bool hasExp = false;

    size_t i = 0;

    // Optional sign
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (; i < s.length(); i++)
    {
        char c = s[i];

        if (c >= '0' && c <= '9')
        {
            hasDigit = true;
        }
        else if (c == '.')
        {
            if (hasDot || hasExp)
                return 0;

            hasDot = true;
        }
        else if (c == 'e' || c == 'E')
        {
            if (!hasDigit || hasExp)
                return 0;

            hasExp = true;
            hasDigit = false;

            // Optional exponent sign
            if (i + 1 < s.length() &&
                (s[i + 1] == '+' || s[i + 1] == '-'))
            {
                i++;
            }
        }
        else
        {
            return 0;
        }
    }

    // Must contain a decimal point OR exponent
    return hasDigit && (hasDot || hasExp);
}


void print(string s1,int a){
    cout << "String: " << s1 << ", Integer: " << a << endl;
}


int main()
{
    cout << isValidFloat("0") << endl; // Output: 1 (true)
    print("Hello", 5);
}