#include <iostream>
#include <string>
#include <cctype>
#include <deque>
#include <vector>

using namespace std; 

deque<int> decToBin(int dec)
{
    deque<int> bin;
    while (dec)
    {
        int digit = dec % 2;
        bin.push_front(digit);
        dec /= 2;
    }
    while (bin.size() < 5)
        bin.push_front(0);


    return bin;
}

void upperCase(string &text)
{
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i]))
            text[i] = toupper(text[i]);
    }
}

int binToDecChar(string bin)
{
    int dec = 0;
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == 'a')
            dec *= 2;
        else
            dec = dec * 2 + 1;
    }
    return dec;
}

string baconianCipher(string plain)
{
    string cipher = "";

    upperCase(plain);

    deque<int> carry(5);

    for (int i = 0; i < plain.size(); i++) {

        int letter = plain[i] - 'A';
        carry = decToBin(letter);

        for (auto it : carry) {
            if (it == 0)
                cipher += 'a';
            else
                cipher += 'b';
        }
    }
    return cipher;
}

string baconianDecipher(string decrypt)
{
    vector<int> dec;
    int beign = 0, end = 5;

    while (end <= decrypt.size())
    {
        string carry;
        carry = decrypt.substr(beign * 5, 5);
        dec.push_back(binToDecChar(carry));
        beign++;
        end += 5;
    }
    string plain = "";
    for (auto it : dec) {
        plain += (char) ('A' + it);
    }
    return plain;
}

int main() 
{
    return 0;
} 
