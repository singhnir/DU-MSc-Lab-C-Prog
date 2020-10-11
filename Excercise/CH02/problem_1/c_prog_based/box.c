// problem oriented program
#include<stdio.h>

int main()
{
	FILE*fp=NULL;
	fp=fopen("box.txt","w");

	float x,y;
	//Loop to calculate and store data-points
	for (x=1;x<=5;x+=0.1)
	{
		// using parallel to x axis equation
		y=1;
		fprintf(fp,"%.2f\t%.2f\n",x,y);
	}

	for (x=1;x<=5;x+=0.1)
	{
		// using parallel to x axis equation
		y=5;
		fprintf(fp,"%.2f\t%.2f\n",x,y);
	}

	for (y=1;y<=5;y+=0.1)
	{
		// using parallel to y axis equation
		x=1;
		fprintf(fp,"%.2f\t%.2f\n",x,y);
	}

	for (y=1;y<=5;y+=0.1)
	{
		// using parallel to y axis equation
		x=5;
		fprintf(fp,"%.2f\t%.2f\n",x,y);
	}
}