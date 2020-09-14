// a function to calculate the factorial of a given integer.
// This program only works till 25.
#include<stdio.h>
//global function declaration
long int factorial(int n);
//main function will call factorial function
int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    printf("Factorial of %d is: %ld\n",n,factorial(n));
    return 0;
}
//defining the function
long int factorial(int n)
{
    if (n>=1)
        return n*factorial(n-1);
    else
        return 1;
}
