//Program to generate Fibonacci numbers till 200.
//Fibonacci numbers are 1,2,3,5,8......
#include <stdio.h>

int main()
{
	int fib1=1,fib2=2,fib3,num=200;
	printf("Fibonacci numbers till 200: \n");
	printf("%d\n",fib1);
	printf("%d\n",fib2);
	fib3=3;
	while (fib3<=num)
	{
		printf("%d\n",fib3);
		fib1=fib2;
		fib2=fib3;
		fib3=fib1+fib2;
	}
}
