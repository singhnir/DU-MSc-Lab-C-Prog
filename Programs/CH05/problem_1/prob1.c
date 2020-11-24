// solving ODE using Euler and RK4 methods
#include<stdio.h>
#include<math.h>

// defining the function to be solved
double f(double t,double x)
{
    return (x*t*t+t*t*sin(pow(t,3)));  
}
// defining the exact solution
double g(double t,double x)
{
    return (-0.3*cos(pow(t,3))-0.1*sin(pow(t,3))+1.3*exp(0.33*pow(t,3)));
}

int main()
{
    FILE*fp=NULL;
    FILE*fp1=NULL;
    FILE*fp2=NULL;
    fp=fopen("exact.txt","w");
    fp1=fopen("euler.txt","w");
    fp2=fopen("rk4.txt","w");

    double t,x,h=0.05,tf=1; //tf is t end value
    // printing the exact sol
    for (t=0;t<=tf;t+=h)
    {
        fprintf(fp,"%.2f\t%lf\n",t,g(t,x));
    }
    // initial conditions
    t=0;
    x=1;
    fprintf(fp1,"0\t1\n");
    // Using Euler Method
    do{
        x=x+h*f(t,x);
        t=t+h;
        fprintf(fp1,"%.2f\t%lf\n",t,x);
    } while(t<=tf);

    // Using RK4 Method
    float k1,k2,k3,k4;
    fprintf(fp2,"0\t1\n");
    t=0;
    x=1;
    do{
        k1=h*f(t,x);
        k2=h*f(t+h/2,x+k1/2);
        k3=h*f(t+h/2,x+k2/2);
        k4=h*f(t+h,x+k3);

        x=x+(k1+2*k2+2*k3+k4)/6;
        t=t+h;
        fprintf(fp2,"%.2f\t%lf\n",t,x);
    } while(t<=tf);
}