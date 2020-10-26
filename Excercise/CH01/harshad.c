/*to find Harshad numbers between 50 and 70 both inclusive
*Some integers have a property that they are divisible by the sum of their digits. Like 84 is divisible by 8 + 4 = 12
*We call them Harshad numbers.*/
#include<stdio.h>
#include <math.h>

int main()
{
	int a,b;
	printf("Harshad numbers between 50 and 70 both inclusive:\n");
	for (int i=50;i<=70;++i)
	{
		a=i/10;		// to get the first number using quotient
		b=i%10;		// to get the second number using remainder
		if (i%(a+b)==0)  //checking harshad number condition
		{
			printf("%d\n",i);
		}
	}
}
