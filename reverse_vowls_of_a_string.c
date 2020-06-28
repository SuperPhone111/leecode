#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// utility function to check for vowel 
bool isVowel(char c) 
{ 
    return (c=='a' || c=='A' || c=='e' || 
            c=='E' || c=='i' || c=='I' || 
            c=='o' || c=='O' || c=='u' || 
            c=='U'); 
}

char * reverseVowels(char * str)
{
    int i = 0, j = 0, tmp = 0; 
    char *vowel;
    int n = (strlen(str)+1);
    vowel = (char*)malloc(n * sizeof(char));
    
    // Storing the vowels separately
    for (int i=0; str[i]!='\0'; i++)
        if (isVowel(str[i]))
            vowel[j++] = str[i];
    // Placing the vowels in the reverse
    // order in the string
    for (int i=0; str[i]!='\0'; i++)
        if (isVowel(str[i]))
            str[i] = vowel[--j] ;
    
    return str;
}

int main()
{
    char input[] = "hello";
    char *output;

    int n = (strlen(input)+1);
    output = (char*)malloc(n * sizeof(char));
    output = reverseVowels(input);
    
    printf("n=%d\n",n);
    printf("output=%s\n",output);

    return 0;
}
