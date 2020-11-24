#include<stdio.h>
#include<math.h>
// summing the series for f4(x)
double f4(double x){
    double t0,t1,sum,R;
    t0=1;
    sum=t0;
    for(int i=1;i<=10;i++)
    {
        R=-(x*x)/((2*i+1)*2*i);
        t1=R*t0;
        sum=sum+t1;
        t0=t1;
    }
    return sum;
}
// defining the function to be solved
double dy(double x,double y,double z){
    return z;
}
double dz(double x,double y,double z){
    return -z-4*x*y+f4(x);
}
int main()
{
    double x,y,z,h=0.05;

    FILE*fp=NULL;
    fp=fopen("prob4.txt","w");
    // initial condition
    x=0;
    y=0;
    z=1; 
    double k1,k2,k3,k4,m1,m2,m3,m4;

    do{
        fprintf(fp,"%lf\t%lf\t%lf\n",x,y,z);
         
        k1=h*dy(x,y,z);
        m1=h*dz(x,y,z);

        k2=h*dy(x+h/2,y+k1/2,z+m1/2);
        m2=h*dz(x+h/2,y+k1/2,z+m1/2);

        k3=h*dy(x+h/2,y+k2/2,z+m2/2);
        m3=h*dz(x+h/2,y+k2/2,z+m2/2);

        k4=h*dy(x+h,y+k3,z+m3);
        m4=h*dz(x+h,y+k3,z+m3);
         
        y=y+(k1+2*k2+2*k3+k4)/6;
        z=z+(m1+2*m2+2*m3+m4)/6;         
        x=x+h;
    }while(x<=10);
}