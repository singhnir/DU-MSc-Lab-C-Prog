//program to generate prime numbers in given range
#include <stdio.h>

int main()
{
    int i, j,start,end,flag;
    //Input range to print prime
    printf("Enter lower limit: ");
    scanf("%d", &start);
    printf("Enter upper limit: ");
    scanf("%d", &end);

    printf("\nAll prime numbers between %d to %d are:\n", start, end);
    if(start < 2)       // 2 is first prime no
        start = 2;
    //logic for prime numbers
    for(i=start; i<=end; i++)
    {
        //assumed this number is prime
        flag = 1; 
        // validating this number with prime no difination
        for(j=2; j<=i/2; j++)
        {
            if(i%j==0)
            {
                flag = 0;
                break;
            }
        }
        //print the numbers if the condition checks true.
        if(flag==1)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}