// evaluating two functions sin(x) and cos(x) and storing the results in text file
#include<stdio.h>
#include <math.h>

int main()
{
	float x;
	//FILE*fp: declaring a pointer of type file
	//NULL: to make sure the file was successfully opened
	FILE*fp=NULL;
	fp=fopen("trig.txt","w");		//w: open a file handle in write mode

	fprintf(fp,"#x\tsin(x)\tcos(x)\ttan(x)\n");
	// pi/4 is 0.7853981634 rad
	for (x=0;x<=0.78; x+=0.01)
	{
		//print line to the file
		fprintf(fp,"%.2f\t%f\t%f\t%f\n",x,sin(x),cos(x),tan(x));
	}
	fclose(fp); 	//close the file handle
}
