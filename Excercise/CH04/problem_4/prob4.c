// Kepler's problem
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
    FILE*fp=NULL;
    fp=fopen("prob4.txt","w");
    float f,df,h,x,t,x1,y1,r,accuracy=0.00001,c;
    for(t=0.0001;t<=2*pi;t=t+0.05)
    {
        x=t;
        do
        {
            // omega=1,e=0.8,a=2
            f=x-0.8*sin(x)-t;
            df=1-0.8*cos(x);
            h=-f/df;
            x=x+h;
        } while(fabs(h/x)>accuracy);

        r=2*(1-0.8*cos(x));
        c=(cos(x)-0.8)/(1-0.8*cos(x));
        x1=r*c;
        y1=r*sqrt(1-c*c);
        fprintf(fp,"%f\t%f\n",x1,y1);
        fprintf(fp,"%f\t%f\n",x1,-y1);
    }
}