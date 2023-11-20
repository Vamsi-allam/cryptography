/* Implementation of Encryption and Decryption of Vigenère Cipher
keyword deceptive
key: deceptivedeceptivedeceptive
plaintext: wearediscoveredsaveyourself
ciphertext: ZICVTWQNGRZGVTWAVZHCQYGLMGJ */

#include <iostream>
#include <string>

using namespace std;

string vigenereEncrypt(const string& plaintext, const string& key) 
{
    string ciphertext;
    int keyLength = key.length();
    for (size_t i = 0; i < plaintext.length(); ++i) 
    {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength];
        if (isalpha(plainChar)) 
        {
            char base = isupper(plainChar) ? 'A' : 'a';
            char encryptedChar = ((plainChar - base + keyChar - 'a') % 26) + base;
            ciphertext += encryptedChar;
        } 
        else 
        {
            ciphertext += plainChar;
        }
    }
    return ciphertext;
}
string vigenereDecrypt(const string& ciphertext, const string& key) 
{
    string decryptedtext;
    int keyLength = key.length();
    for (size_t i = 0; i < ciphertext.length(); ++i) 
    {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % keyLength];
        if (isalpha(cipherChar)) 
        {
            char base = isupper(cipherChar) ? 'A' : 'a';
            char decryptedChar = ((cipherChar - base - (keyChar - 'a') + 26) % 26) + base;
            decryptedtext += decryptedChar;
        } else 
        {
            decryptedtext += cipherChar;
        }
    }
    return decryptedtext;
}
int main() 
{
    string keyword = "deceptive";
    string plaintext = "wearediscoveredsaveyourself";
    string fullKey;
    while (fullKey.length() < plaintext.length()) 
    {
        fullKey += keyword;
    }
    fullKey = fullKey.substr(0, plaintext.length());
    string ciphertext = vigenereEncrypt(plaintext, fullKey);
    cout << "Ciphertext: " << ciphertext << endl;
    string decryptedText = vigenereDecrypt(ciphertext, fullKey);
    cout << "Decrypted Plaintext: " << decryptedText << endl;
    return 0;
}
