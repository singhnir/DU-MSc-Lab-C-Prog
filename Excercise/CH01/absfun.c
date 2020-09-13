// Make a table of the function f(x,y) for -1.0<=x,y<=1.0 at intervals of 0:25 for both x and y.
#include<stdio.h>
#include <math.h>

int main ()
{
	float x,y,z;
	//FILE*fp: declaring a pointer of type file
	//NULL: to make sure the file was successfully opened
	FILE*fp=NULL;
	fp=fopen("absfun.txt","w");		//w: open a file handle in write mode

	printf("x\t y\t f(x,y)\n");
	for (x=-1.0;x<=1.0;x+=0.25)
	{
		for (y=-1.0;y<=1.0;y+=0.25)
		{
				if (fabs(x)>fabs(y))
				{
					z=pow(x,2)+pow(y,4);
					printf("%0.2f\t %0.2f\t %0.2f\n",x,y,z);
					fprintf(fp,"%0.2f\t %0.2f\t %0.2f\n",x,y,z);
				}
				else if (fabs(x)==fabs(y))
				{
					z=x*x*(x*x+1);
					printf("%0.2f\t %0.2f\t %0.2f\n",x,y,z);
					fprintf(fp,"%0.2f\t %0.2f\t %0.2f\n",x,y,z);
				}
				else if (fabs(x)<fabs(y))
				{
					z=pow(y,2)+pow(x,4);
					printf("%0.2f\t %0.2f\t %0.2f\n",x,y,z);
					fprintf(fp,"%0.2f\t %0.2f\t %0.2f\n",x,y,z);
				}
		}
	}
	fclose(fp); 	//close the file handle
	return 0;
}
