//a program to finnd all the distinct sets of Pythagorean numbers less than 100
#include<stdio.h>
#include <math.h>

int main()
{
	int a,b,c,n=100;
	printf("distinct sets of Pythagorean numbers less than 100\n");
	printf("\na\t b\t c\n");
	for (int a=1; a<=n;a+=1)
	{
		for (int b=1;b<=n;b+=1)
		{
			for (int c=1;c<=n;c+=1)
			{
				if (a*a+b*b==c*c)
				{
					printf("%d\t %d\t %d\n",a,b,c);
				}
			}
		}
	}
	return 0;
}
