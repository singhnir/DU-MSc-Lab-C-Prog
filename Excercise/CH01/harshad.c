//to find Harshad numbers between 50 and 70 both inclusive
#include<stdio.h>
#include <math.h>

int main()
{
	int a,b;
	printf("Harshad numbers between 50 and 70 both inclusive:\n");
	for (int i=50;i<=70;++i)
	{
		a=i%10;		// to get the second number using remainder
		b=(i-a)/10;		// to get the first number
		if (i%(a+b)==0)  //checking harshad number condition
		{
			printf("%d\n",i);
		}
	}
	return 0;
