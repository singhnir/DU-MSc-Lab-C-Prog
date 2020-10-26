// sinxtab.c - tabulates values of sin(x)
#include <stdio.h>
#include <math.h>

int main()
{
	float x,x1,x2,y,dx,pi;
	int i,n;
	n=20;
	pi = 4.0*atan(1.0);
	printf("Enter the x1 and x2 in units of pi:\n");
	scanf("%f%f",&x1,&x2);
	x1=x1*pi;
	x2=x2*pi;
	dx=(x2-x1)/(float)(n); //to get the intervals

	printf("\nx is parameter equally spaced between x1 and x2\n");
	printf("x\tsin(x)\n");
	for (int i = 0; i <=n; ++i)
	{
		x=x1+i*dx;
		y=sin(x);
		printf("%.2f\t%.2f\n",x,y);
	}
}
