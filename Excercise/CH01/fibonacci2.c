// a function which can be called to generate the Fibonacci number
//Fibonacci numbers are 0,1,1,2,3,5,8......
#include<stdio.h>
//global function declaration
int fibonacci(int num);
//main function will call fibonacci function
int main()
{
	int num,sum=0;
	printf("Enter the integer till you want Fibonacci numbers: ");
	scanf("%d",&num);
	while(fibonacci(sum)<=num)
	{
		printf("%d\n",fibonacci(sum));
		sum++;
	}
}
//defining the function
int fibonacci(int num)
{
	if (num<=1)
	return num;
	return fibonacci(num-1)+fibonacci(num-2);
}
