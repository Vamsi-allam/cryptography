/* By using key “CBDE” Raju would like send message (plain text)“HELLO
WORLD” to Rani. Can you build encryption process and find out what is the
encrypted message (cipher text) to Raju by using Hill Cipher.Also Can you build
decryption process and find out what is the decrypted message (plain text) of
cipher text &quot;SLHZYATGZT&quot; by using Hill Cipher. */


#include <iostream>
#include <vector>
using namespace std;
vector<int> textToNumerical(const string& text) 
{
    vector<int> numerical;
    for (char ch : text) 
    {
        numerical.push_back(ch - 'A');
    }
    return numerical;
}
string numericalToText(const vector<int>& numerical) 
{
    string text;
    for (int num : numerical) 
    {
        text.push_back(num + 'A');
    }
    return text;
}
vector<int> matrixMultiply(const vector<vector<int>>& key, const vector<int>& input) 
{
    vector<int> result(2, 0);
    result[0] = (key[0][0] * input[0] + key[0][1] * input[1]) % 26;
    result[1] = (key[1][0] * input[0] + key[1][1] * input[1]) % 26;
    return result;
}
vector<int> encrypt(const vector<vector<int>>& key, const vector<int>& plaintext) 
{
    vector<int> ciphertext;
    for (size_t i = 0; i < plaintext.size(); i += 2) 
    {
        vector<int> input = { plaintext[i], plaintext[i + 1] };
        vector<int> result = matrixMultiply(key, input);
        ciphertext.insert(ciphertext.end(), result.begin(), result.end());
    }
    return ciphertext;
}
int modInverse(int a, int m) 
{
    for (int i = 1; i < m; i++) 
    {
        if ((a * i) % m == 1) 
        {
            return i;
        }
    }
    return 1;
}
int determinant(const vector<vector<int>>& key) 
{
    return (key[0][0] * key[1][1] - key[0][1] * key[1][0] + 26) % 26;
}
vector<vector<int>> inverseMatrix(const vector<vector<int>>& key) 
{
    int det = determinant(key);
    int detInv = modInverse(det, 26);
    vector<vector<int>> inverse(2, vector<int>(2, 0));
    inverse[0][0] = (key[1][1] * detInv) % 26;
    inverse[1][1] = (key[0][0] * detInv) % 26;
    inverse[0][1] = (26 + (-key[0][1] * detInv) % 26) % 26;
    inverse[1][0] = (26 + (-key[1][0] * detInv) % 26) % 26;
    return inverse;
}
vector<int> decrypt(const vector<vector<int>>& key, const vector<int>& ciphertext) 
{
    vector<int> plaintext;
    vector<vector<int>> keyInverse = inverseMatrix(key);
    if (keyInverse[0][0] == -1) 
    {
        cout << "Key is not invertible. Decryption is not possible." << endl;
        return plaintext;
    }
    for (size_t i = 0; i < ciphertext.size(); i += 2) 
    {
        vector<int> input = { ciphertext[i], ciphertext[i + 1] };
        vector<int> result = matrixMultiply(keyInverse, input);
        plaintext.insert(plaintext.end(), result.begin(), result.end());
    }
    return plaintext;
}
int main() 
{
    vector<vector<int>> key = { {2, 1}, {3, 4} };
    string plaintext = "HELLOWORLD";
    vector<int> numericalPlaintext = textToNumerical(plaintext);
    vector<int> ciphertext = encrypt(key, numericalPlaintext);
    cout << "Encrypted Ciphertext: ";
    for (int num : ciphertext) 
    {
        cout << num << " ";
    }
    cout << endl;
    vector<int> decryptedPlaintext = decrypt(key, ciphertext);
    string decryptedText = numericalToText(decryptedPlaintext);
    cout << "Decrypted Plaintext: " << decryptedText << endl;
    return 0;
}
