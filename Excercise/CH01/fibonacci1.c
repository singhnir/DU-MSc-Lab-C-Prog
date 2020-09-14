//Program to generate Fibonacci numbers till 200.
//Fibonacci numbers are 1,2,3,5,8......
#include <stdio.h>

int main()
{
	int fib1=1,fib2=2,fib3;
	printf("Fibonacci numbers till 200: \n");
	printf("%d\n",fib1);
	printf("%d\n",fib2);
	fib3=3;
	while (fib3<=200)
	{
		printf("%d\n",fib3);
		fib1=fib2;
		fib2=fib3;
		fib3=fib1+fib2;
	}
	return 0;
}

// // More General form, you can delete the below section in your program.
// //Program to generate Fibonacci numbers till any integer
// //Fibonacci numbers are 1,2,3,5,8......
// #include <stdio.h>
//
// int main()
// {
// 	int fib1=1,fib2=2,fib3,num;
// 	printf("Enter the integer till you want Fibonacci numbers: ");
// 	scanf("%d", &num);
// 	printf("Fibonacci numbers till %d: \n",num);
// 	printf("%d\n",fib1);
// 	printf("%d\n",fib2);
// 	fib3=3;
// 	while (fib3<=num)
// 	{
// 		printf("%d\n",fib3);
// 		fib1=fib2; // swap elements
// 		fib2=fib3;
// 		fib3=fib1+fib2; // next term is the sum of the last two terms
// 	}
// 	return 0;
// }
