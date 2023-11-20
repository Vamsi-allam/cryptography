// Write a program take text file as an input and print word, character count and ascii value of each characters as output. (Hint: Use open(), read() and split()).

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    char inp_file[50];
    FILE *file = fopen("C:\Users\khv12\OneDrive\Documents\Cryptography Lab-1 Code.txt","r");
    if(file== NULL)
    {
        printf("File not found!");
        return 1;
    }
    int word_count=0;
    int char_count=0;
    int c;
    while((c=fgetc(file))!= EOF)
    {
        if(isspace(c))
        {
            word_count+=1;
        }
        char_count+=1;
        printf("ASCII value of %c is %d\n",c,c);
    }
    printf("Word Count: %d\n",word_count+1);
    printf("Character Count: %d",char_count);
    fclose(file);
    return 0;

}
