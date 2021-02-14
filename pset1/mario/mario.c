#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while(n<1 || n>8);
    for(int i=0;i<n;i++)
    {  
      for(int k=n-i;k>1;k=k-1)
      {
        printf(" ");
      }
        
      for(int j=0;j<=i;j++)
      {
     
          printf("#");
      }
      printf("  ");
      for(int m=0;m<=i;m++)
      {
     
          printf("#");
      }
      printf("\n");
    }
}