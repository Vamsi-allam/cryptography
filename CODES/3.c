// 3. Raju send an encrypted message (cipher text) “PHHW PH DIWHU WKH WRJD SDUWB” to Rani. Can you build decryption process and find out what is the message (plain text) send to Rani? Hint: try all keys.

#include <stdio.h>
void encrypt(char *input, char *output) 
{
    int i = 0;
    while (input[i] != '\0') 
    {
        if(input[i] >='A' && input[i] <='C')
        {
            output[i] = input[i] + 23;
        }
        else if (input[i] >= 'D' && input[i] <= 'Z') 
        {
            output[i] = input[i]-3;
        }
        else if(input[i] == ' ')
        {
            output[i] = input[i];
        }
        i++;
    }
}
int main() 
{
    char input[] = "PHHW PH DIWHU WKH WRJD SDUWB";
    char output[100];
    encrypt(input, output);
    printf("Input: %s\n", input);
    printf("Output: %s\n", output);
    return 0;
}
