// Make a table of the function f(x,y) for -1.0<=x,y<=1.0 at intervals of 0:25 for both x and y.
#include<stdio.h>
#include <math.h>

int main ()
{
	float x,y,z;

	printf("x\ty\tf(x,y)\n");
	for (x=-1.0;x<=1.0;x+=0.25)
	{
		for (y=-1.0;y<=1.0;y+=0.25)
		{
			if (fabs(x)>fabs(y))
			{
				z=pow(x,2)+pow(y,4);
				printf("%.2f\t%.2f\t%.2f\n",x,y,z);
			}
			else if (fabs(x)==fabs(y))
			{
				z=x*x*(x*x+1);
				printf("%.2f\t%.2f\t%.2f\n",x,y,z);
			}
			else if (fabs(x)<fabs(y))
			{
				z=pow(y,2)+pow(x,4);
				printf("%.2f\t%.2f\t%.2f\n",x,y,z);
			}
		}
	}
}
