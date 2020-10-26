/*Program to generate prime numbers upto n
*A prime number is a positive integer that is divisible only by 1 and itself. For example: 2, 3, 5, 7, 11, 13, 17*/
#include <stdio.h>

int main()
{
    int i, j,upto,flag; //a flag is a value that acts as a signal for a function or process.
    //Input upper limit to print prime
    printf("Show Prime numbers upto : ");
    scanf("%d",&upto);

    printf("\nAll prime numbers upto %d are:\n",upto);
    //logic for prime numbers
    for(i=2;i<=upto;++i)
    {
        //assumed this number is prime
        flag = 1;
        // validating this number with prime no difination
        for(j=2;j<=i/2;++j)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        //print the numbers if the condition checks true.
        if(flag==1)
        {
            printf("%d\n",i);
        }
    }
}
