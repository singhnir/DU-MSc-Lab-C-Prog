//calculating hcf using recursion
#include <stdio.h>

int hcf(int num1,int num2);
int main()
{
    int num1,num2;
    printf("Enter the two integers to find their HCF:");
    scanf("%d %d",&num1,&num2);
    printf("\nHCF of %d and %d is %d.\n",num1,num2,hcf(num1,num2));
    return 0;
}
//In this program, recursive calls are made until the value of n2 is equal to 0.
int hcf(int num1,int num2)
{
    if (num2 != 0)
        return hcf(num2,num1%num2);
    else
        return num1;
}
