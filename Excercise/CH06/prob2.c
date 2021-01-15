// problem 2
#include<stdio.h>
#include<math.h>
#include"integral.c"
#define pi 3.1415927

// function to be intgrated fxa(x,A)
double fxa(double x,double A){
    return 1/(1-sin(A/2)*sin(A/2)*sin(x)*sin(x));
}
// function for approx time-period T1(A)
double T1(double A){
    return 2*pi*(1+pow(A/4,2));
}
// function for whole time-period T(func,A,n)
double T(double f(double x,double A),double A,int n){
    return 4*trap(fxa,A,0,pi/2,n);   
}
// main function to do our job
int main()
{
    FILE*fp=NULL;
    fp=fopen("prob2.txt","w");

    double A,t,t1,error;
    // getting values for A range
    for(A=0;A<=pi;A+=0.05)
    {
        t=T(fxa,A,300);   // time-period n=300
        t1=T1(A);   // approx time-period
        error=(t-t1)/t*100; // % error in both
        fprintf(fp,"%lf\t%lf\t%lf\t%lf\n",A,t,t1,error);
    }
}