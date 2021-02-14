#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{   
    //Input Argument Validation Code
    if(argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    for(int i = 0 ; i < strlen(argv[1]); i++)
    {
        if(argv[1] < 0 ||  isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    
    }
    //converts input string to int
    int k = atoi(argv[1]);
  
    //cipher text algorithm for ascii 
    string s = get_string("plaintext: ");
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] % 97;
            //printf("%c\n" , s[i]);
            //printf("%i\n" , s[i]);
            s[i] = ((int) s[i] + k) % 26;
            s[i] = s[i] + 97; 
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] % 65;
            s[i] = (s[i] + k) % 26;
            s[i] = s[i] + 65;
        }
    }
    
    
    
    //Output text
    printf("ciphertext: %s\n", s);
}