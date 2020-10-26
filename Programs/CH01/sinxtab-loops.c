// sinxtab-loops.c - tabulates values of sin(x)
#include <stdio.h>
#include <math.h>

int main()
{
	float x,x1,x2,y,dx;
	int i,n;
	n=20;
	printf("Enter the x1 and x2 in units of degrees:\n");
	scanf("%f%f",&x1,&x2);
	//1 rad= 57.2957795 deg & 1 deg = 0.01745329 rad.
	x1=x1*0.01745329;
	x2=x2*0.01745329;
	dx=(x2-x1)/(float)(n); //to get the stepsize

	printf("\nUSING FOR LOOP\n");
	printf("x\tsin(x)\n");

	for (i=0;i<=n;++i)
	{
		x=x1+i*dx;
		y=sin(x);
		printf("%.2f\t%.2f\n",x,y);
	}

	printf("\nUSING DO-WHILE LOOP\n");
	printf("x\tsin(x)\n");

	i=0;
	do
	{
		x=x1+i*dx;
		y=sin(x);
		printf("%.2f\t%6.2f\n",x,y);
		i++;
	} while (i<=n);

	printf("\nUSING WHILE LOOP\n");
	printf("x\tsin(x)\n");
	i=0;n=20;
	while (i<=n)
	{
		x=x1+i*dx;
		y=sin(x);
		printf("%.2f\t%.2f\n",x,y);
		i++;
	}

	printf("\nx(in degrees) is parameter equally spaced between x1 and x2\n");
}
