// "prey-predator" system
#include<stdio.h>
#include<math.h>

#define dx(t,x,y) (gamma1*(x)-gamma2*(x)*(y))
#define dy(t,x,y) (-gamma3*(y)+gamma4*(x)*(y))

int main()
{
    FILE*fp=NULL;
    fp=fopen("prob3.txt","w");

    double gamma1=0.25,gamma2=0.01,gamma3=1,gamma4=0.01;
    double t,x,y,y0,h=0.05;
    double k1,k2,k3,k4,m1,m2,m3,m4;

    for (y0=5;y0<=25;y0+=5)
    {
        // initial conditions
        t=0;
        x=100;
        y=y0;

        do{
            fprintf(fp,"%lf\t%lf\t%lf\n",x,y,t);
            k1=h*dx(t,x,y);
            m1=h*dy(t,x,y);

            k2=h*dx(t+h/2,x+k1/2,y+m1/2);
            m2=h*dy(t+h/2,x+k2/2,y+m2/2);

            k3=h*dx(t+h/2,x+k2/2,y+m2/2);
            m3=h*dy(t+h/2,x+k2/2,y+m2/2);

            k4=h*dx(t+h,x+k3,y+m3);
            m4=h*dy(t+h,x+k3,y+m3);
         
            x=x+(k1+2*k2+2*k3+k4)/6;
            y=y+(m1+2*m2+2*m3+m4)/6;         
            t=t+h;
        } while(t<=20);
    }
 
}