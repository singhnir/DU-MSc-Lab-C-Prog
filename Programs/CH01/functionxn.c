// Evaluating a function having two variable
#include<stdio.h>
#include <math.h>
//defining the function
float func(float x, int n)
{
	float y,z=1.0;
	int i;
	for (int i=1;i<=n;++i)
	{
		z*=x;
	}
	if (x<0.0)
	{
		y=z-1+exp(x);
	}
	else {
		y=z-log(1+x);
	}
	return (y);
}
//global function declaration
float func(float x, int n);
//main function will call func
int main ()
{
float a;
int b;
    printf("\nEnter the value of x(float) and n(int):\n");
    scanf("%f %d", &a, &b);
    printf("\nfor x= %.2f and n= %d function f(x,n) = %.2f\n",a,b,func(a,b));
	return 0;
}
