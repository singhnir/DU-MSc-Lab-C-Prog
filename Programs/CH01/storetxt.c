// evaluating two functions sin(x) and cos(x) and storing the results in text file
#include<stdio.h>
#include <math.h>

int main()
{
	float x,y,z;
	//FILE*fp: declaring a pointer of type file
	//NULL: to make sure the file was successfully opened
	FILE*fp=NULL;
	FILE*fp1=NULL;

	fp=fopen("sinx.txt","w");		//w: open a file handle in write mode
	fp1=fopen("cosx.txt","w");

	for (x=0;x<=6;x+=0.1)
	{
		y=sin(x);
		z=cos(x);
		//print line in the output terminal
		// printf("\n %f\t %f\n",x,y);
		//print line to the file
		fprintf(fp,"%f\t%f\n",x,y);
		fprintf(fp1,"%f\t%f\n",x,z);
	}
	fclose(fp); 	//close the file handle
	fclose(fp1);
}
