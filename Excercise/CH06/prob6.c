// problem 6
#include<stdio.h>
#include<math.h>
#include"integral.c"
#define pi 3.1415927

double f(double theta,double z){
    return cos(z*cos(theta))*pow(sin(theta),5);
}
double J2(double z){
    return pow(z,2)/(pow(2,3)*factorial(2))*trap(f,z,0,pi,1000);
}

int main()
{
  float a=0,b=10;	// range of roots
  printf("USING BISECTION METHOD\n");
  bisection(J2,a,b);
  printf("\nUSING SECANT METHOD\n");
  secant(J2,a,b);
}