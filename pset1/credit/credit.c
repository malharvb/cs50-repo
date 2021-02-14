#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n=1;
    int c=1;
    long temp,type1,type2;
    long even = 0;
    long odd = 0;
    long div=10;

    long num = get_long("Number: ");
    while(num/div > 0)
    {
      n++;
      div *= 10;
    }
    //printf("%i\n", n);
    div = 10;
    
    for(int i=0; i<n; i++)
    {
        temp = num%div;
        temp = temp / (div/10);
         if(c==n)
        {
              type1 = temp;
        }
         else if(c==n-1)
        {
              type2 = temp;
              
        }
        if(c%2 == 0)
        {
            temp = temp * 2;
            if(temp/10 != 0)
            {
                long k = temp/10;
                temp = temp % 10;
                temp = temp + k;
            }
            
           
            even = even+temp;
            
        }
        else
        {
            odd = odd+temp;
        }
         
        c++; 
        div = div * 10;
        
        
    }
  
    long val = even + odd;
    //printf("%li\n",val);
    
   if(n==16 && type1 ==5 && (type2==1||type2==2||type2==3||type2==4||type2==5) && val%10 == 0)
   {
       printf("MASTERCARD\n");
   }
   else if(n==15 && type1==3 && (type2==4|| type2==7) && val%10==0)
   {
       printf("AMEX\n");
   }
    else if((n==13 || n==16) && type1==4 && val%10==0)
    {
        printf("VISA\n");
    }
    else
    {
         printf("INVALID\n");
    }
}
