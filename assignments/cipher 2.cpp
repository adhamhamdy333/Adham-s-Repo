#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string atbashCipherV1(string text)
{
    string calpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", salpha = "abcdefghijklmnopqrstuvwxyz";
    string cipher = "";
    for (int i = 0; i < text.size(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            int steps = text[i] - 'a';
            cipher += salpha[25 - steps];
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            int steps = text[i] - 'A';
            cipher += calpha[25 - steps];
        }
        else
            cipher += text[i];
    }
    return cipher;
}
string removeSpaces (string s)
{   string ret = "";
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i]))
            ret += s[i];
    }
    return ret;
}
void atbashCipherV2()
{
    string name, name1, name2;
    getline(cin, name);

    name = removeSpaces(name);

    name1 = name.substr(0, name.size() / 2);
    name2 = name.substr(name.size() / 2, name.size());

    name1 = atbashCipherV1(name1);
    name2 = atbashCipherV1(name2);

    cout << name1 << ' ' << name2;
}
int main ()
{
    string name;
    getline(cin, name);
    name = atbashCipherV1(name);
    cout << name;
    return 0;
}