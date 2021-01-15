// problem 4
#include<stdio.h>
#include<math.h>
#include"integral.c"
#define pi 3.1415927

// function to be intgrated ftx(t,x)
double ftx(double t,double x){
    return cos(pow(x,1.5)*cos(t))*pow(sin(t),3);
}
// function which root is needed Fx(x)
double Fx(double x){
    return trap(ftx,x,0,pi,500);	// n=500
}
// main program to do neccessary job
int main()
{
	float a=0,b=5; // range of roots
	printf("USING BISECTION METHOD\n");
  	bisection(Fx,a,b);
  	printf("\nUSING SECANT METHOD\n");
	secant(Fx,a,b);
}