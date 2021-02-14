#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>




int main(void)
{
    int count_l=0;
    int count_w=1;
    int count_s=0;
    string sent = get_string("Text: ");
    
    //to convert the sentence to lowercase
    for (int i = 0, n = strlen(sent); i < n; i++)
    {
         sent[i] = tolower(sent[i]);
    }


    //function to count no. of letters ,words & sentences
    for (int i = 0, n = strlen(sent); i < n; i++)
    {
        if(sent[i] == ' ')
        {
            count_w++;
        }
        else if (sent[i] >= 'a' && sent[i] <= 'z')
        {
               
     
            count_l++;

       
        }
        else if(sent[i] == '.' || sent[i] == '!' || sent[i] == '?')
        {
            count_s++;
        }
    }
    

    //Coleman-Liau index calc.
    float L = ((float) count_l / count_w) * 100;
    float S = ((float) count_s / count_w) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = (int) round(index);
    
    
    
    
    //Printing Grade
    
    
    if (index>=1 && index<=16)
    printf("Grade %.0f\n", index);
    else if(index<1)
    printf("Before Grade 1\n");
    else
    printf("Grade 16+\n");

}



