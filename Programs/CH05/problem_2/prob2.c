// solving the spring-mass system
#include<stdio.h>
#include<math.h>

// defining the function to be solved
double f1(double t,double y,double z){
    return z;  
}
double f2(double t,double y,double z){
    return -y;
}

int main()
{
    FILE*fp=NULL;
    FILE*fp1=NULL;
    fp=fopen("exact.txt","w");
    fp1=fopen("rk4.txt","w");

    double t,y,z,h=0.05;
    double k1,k2,k3,k4,m1,m2,m3,m4;
    // printing the exact solution
    for (t=0;t<=10;t=t+0.05)
    {
        fprintf(fp,"%.2f\t%lf\n",t,cos(t));
    }
    // initial conditions
    t=0;
    y=1;
    z=0;
    // Using RK4 Method
    do{
        k1=h*f1(t,y,z);
        m1=h*f2(t,y,z);

        k2=h*f1(t+h/2,y+k1/2,z+m1/2);
        m2=h*f2(t+h/2,y+k1/2,z+m1/2);

        k3=h*f1(t+h/2,y+k2/2,z+m2/2);
        m3=h*f2(t+h/2,y+k2/2,z+m2/2);

        k4=h*f1(t+h,y+k3,z+m3);
        m4=h*f2(t+h,y+k3,z+m3);

        y=y+(k1+2*k2+2*k3+k4)/6;
        z=z+(m1+2*m2+2*m3+m4)/6;
        t=t+h;
        fprintf(fp1,"%.2f\t%lf\n",t,y);
    } while(t<=10);
}