// Write a encryption program: Input: computerscienceengineeringsrmuniversity Output:gsqtyxivwgmirgiirkmriivmrkwvqyrmzivwmxc Hint: key =4 (play with ascii value).

#include <stdio.h>
void encrypt(char *input, char *output) 
{
    int i = 0;
    while (input[i] != '\0') 
    {
        if (input[i] >= 'a' && input[i] <= 'v') 
        {
            output[i] = input[i]+4;
        }
        else if(input[i]>='w' && input[i]<= 'z')
        {
            output[i] = input[i] - 22;
        }
        i++;
    }
}
int main() 
{
    char input[] = "computerscienceengineeringsrmuniversity";
    char output[100];
    encrypt(input, output);
    printf("Input: %s\n", input);
    printf("Output: %s\n", output);
    return 0;
}
