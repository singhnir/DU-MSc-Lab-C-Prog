// Program which calculates nCr and nPr for given values of n and r
#include<stdio.h>
//global function declaration
long int factorial(int n);
//main function will call factorial function
int main()
{
    int n,r;
    float nCr,nPr;
    printf("Enter a positive integer n and r(r<=n): ");
    scanf("%d %d",&n, &r);
    nCr=(factorial(n))/(factorial(n-r)*factorial(r));
    nPr=(factorial(n))/(factorial(n-r));
    printf("For n=%d and r=%d\n",n,r);
    printf("Combination: %0.2f Permutation: %0.2f\n",nCr,nPr);
    return 0;
}
//defining the factorial function
long int factorial(int n)
{
    if (n>=1)
        return n*factorial(n-1);
    else
        return 1;
}
