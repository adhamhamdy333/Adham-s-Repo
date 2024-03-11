/*
    Vignere Cipher
    
    This program implements the Vignere Cipher encryption and decryption methods.
    In Vignere Cipher, a keyword is repeatedly added character by character to each alphabetic letter in the original message.
    The addition is carried out using the ASCII codes for each of the characters, modulo 26 (the number of letters in the alphabet),
    and the result is added to the code for the letter 'A' in the ASCII code sequence.
    
    Author: Adham Hamdy Hamed Abdulhameid
    ID: 20230043
    Date: 1:08 PM, 3/11/24, 1 Ramadan
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to convert characters in the given string to uppercase
void upperCase(string &text)
{
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i]))
            text[i] = toupper(text[i]);
    }
}

// Function to validate user input choice
void checkInput(string &c)
{
    while (c.size() > 1)
    {
        cout << "Please enter only one number that represents the choice's number!";
        cin >> c;
    }
    while (!isdigit(c[0]) || (c[0] < '1' || c[0] > '3'))
    {
        cout << "Please enter only one number from [1, 2, 3]";
        cin >> c;
    }
}

// Function to validate the message size
void checkMessage(string &m)
{
    while (m.size() > 80)
    {
        cout << "Please enter a message of size doesn't exceed 80 characters" << endl;
        getline(cin, m);
    }
}

// Function to validate the key size and characters
void checkKey(string &k)
{
    here : {};
    while (k.size() > 8)
    {
        cout << "Please enter a key of size doesn't exceed 8 characters" << endl;
        getline(cin, k);
    }
    for (int i = 0; i < k.size(); ++i) {
        if (!isalpha(k[i]))
        {
            cout << "Please enter a key contains only alphabetic characters" << endl;
            getline(cin, k);
            goto here;
        }
    }
}

// Function to perform Vignere Cipher encryption
void vignereCipher(string &message, string &keyword)
{
    checkMessage(message);
    checkKey(keyword);
    upperCase(message);
    upperCase(keyword);

    int keyIndx = 0;
    for (int i = 0; i < message.size(); i++) {
        if (isalpha(message[i]))
        {
            int messageIndx = ((int) message[i] + (int) keyword[keyIndx]) % 26;
            message[i] = char ('A' + messageIndx);
        }
        keyIndx++;
        if (keyIndx == keyword.size())
            keyIndx = 0;
    }
}

// Function to perform Vignere Cipher decryption
void vignereDecipher(string &message, string &keyword)
{
    checkMessage(message);
    checkKey(keyword);
    upperCase(message);
    upperCase(keyword);

    int keyIndx = 0;
    for (int i = 0; i < message.size(); i++) {
        if (isalpha(message[i]))
        {
            int messageIndx = (message[i] - keyword[keyIndx] + 26) % 26;
            message[i] = char ('A' + messageIndx);
        }
        keyIndx++;
        if (keyIndx == keyword.size())
            keyIndx = 0;
    }
}

// Function to run the program
int runME()
{
    string choice, message, key;
    cout << "***Hello and Welcome to Vignere Cipher/Decipher***" << endl;
    cout << "Menu: Choose from the menu and enter the number of your choice..." << endl;
    cout << "1- Cipher a message" << endl << "2- Decipher a message" << endl << "3- End" << endl;
    cin >> choice;
    checkInput(choice);
    cin.ignore();
    if (choice == "1")
    {
        cout << "Please enter the message and the key to cipher: ";
        getline(cin, message);
        getline(cin, key);
        vignereCipher(message, key);
        cout << "The message after encryption: " << message << endl;
        return 0;
    }
    else if (choice == "2")
    {
        cout << "Please enter the message and the key to decipher: ";
        getline(cin, message);
        getline(cin, key);
        vignereDecipher(message, key);
        cout << "The message after decryption: " << message << endl;
        return 0;
    }
    else if (choice == "3")
    {
        cout << "Goodbye...";
        return 0;
    }
}

// Main function
int main ()
{
    runME();
    return 0;
}
