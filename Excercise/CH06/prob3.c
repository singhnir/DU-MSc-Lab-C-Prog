// problem 3
#include<stdio.h>
#include<math.h>
// function to be intgrated fre(r,E)
double fre(double r,double E)
{
    return (1/(r*r*sqrt(2*E+2/r+1/(r*r))));
}
// gauss quadrature function to evaluate integration
double gauss(double f(double r,double E),double r,double E,double a, double b)
{
    double x1,x2;
    x1=((b-a)/2.0)*(1/1.73)+((b+a)/2);
    x2=((b-a)/2.0)*(-1/1.73)+((b+a)/2);
    return (b-a)/a*(f(x1,E)+f(x2,E));
}
int main()
{
    FILE*fp=NULL;
    fp=fopen("prob3.txt","w");

    double E,r,r0,rm;
    printf("Enter the value of E:");
    scanf("%lf",&E);
    printf("Enter the lower and upper limit r0 & rm:");
    scanf("%lf%lf",&r0,&rm);

    // varaying R from r0 to rm
    for (r=r0;r<=rm;r=r+0.1)
    {
        fprintf(fp,"%lf\t%lf\n",r,gauss(fre,r,E,r0,r));
    }
}