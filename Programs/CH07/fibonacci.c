// program to generate the first 10 Fibonacci numbers
#include<stdio.h>

int i;
int fibonacci[10];	//decalaring 1-d array with 10 elements

int main()
{
	// initialising first two fibonacci no
	fibonacci[0]=0;
	fibonacci[1]=1;

	// generating fibanacci no upto 10
	for (i=2;i<10;++i)	
		fibonacci[i]=fibonacci[i-2]+fibonacci[i-1];

		for (i=0;i<10;++i)		
			printf("fibonacci[%d]=%d\n",i,fibonacci[i]);	
}