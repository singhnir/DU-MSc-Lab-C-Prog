// sinxtab-loops.c - tabulates values of sin(x)
#include <stdio.h>
#include <math.h>

int main()
{
	float x,x1,x2,y,dx,pi;
	int i,n;
	n=20;
	pi = 4.0*atan(1.0);
	printf("Enter the x1 and x2 in units of pi:\n");
	scanf("%f, %f",&x1, &x2);
	x1=x1*pi;
	x2=x2*pi;
	dx=(x2-x1)/(float)(n); //to get the intervals

	printf("x is parameter equally spaced between x1 and x2\n");

	printf("\nUSING FOR LOOP\n");
	printf("x\tsin(x)\n");

	for (int i = 0; i <=n; ++i)
	{
		x=x1+i*dx;
		y=sin(x);
		printf("%6.2f %6.2f\n", x,y );
	}

	printf("\nUSING DO-WHILE LOOP\n");
	printf("x\tsin(x)\n");

	i=0;
	do
	{
		x=x1+i*dx;
		y=sin(x);
		printf("%6.2f %6.2f\n", x,y );
		i++;
	} while (i<=n);

	printf("\nUSING WHILE LOOP\n");
	printf("x\tsin(x)\n");
	i=0;n=20;
	while (i<=n)
	{
		x=x1+i*dx;
		y=sin(x);
		printf("%6.2f %6.2f\n", x,y );
		i++;
	}
	return 0;
}
