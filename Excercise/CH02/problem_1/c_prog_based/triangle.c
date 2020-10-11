// problem oriented program
#include<stdio.h>

int main()
{
	FILE*fp=NULL;
	fp=fopen("triangle.txt","w");

	float x,y;
	//Loop to calculate and store data-points
	for (x=0;x<=4;x+=0.1)
	{
		// using x axis equation
		y=0;
		fprintf(fp,"%.2f\t%.2f\n",x,y);
	}

	for (x=0;x<=4;x+=0.1)
	{
		// using y-y1=m(x-x1)
		y=(3*x)/4;
		fprintf(fp,"%.2f\t%.2f\n",x,y);
	}

	for (y=0;y<=3;y+=0.1)
	{
		// using parallel to y axis equation
		x=4;
		fprintf(fp,"%.2f\t%.2f\n",x,y);
	}
}