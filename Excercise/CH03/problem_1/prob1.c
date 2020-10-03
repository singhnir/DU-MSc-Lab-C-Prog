
#include<stdio.h>
#include<math.h>

int main()
{
    FILE*fp=NULL;
    fp=fopen("prob1.txt","w");
    int i,n;
    float x,t0,t1,R,sum;
    n=20;

    for(x=0.1;x<=2;x=x+0.01)
    {
        t0=1/(x*x); //taking 2nd term as first
        sum=1+t0;   // adding first term of series
        for(i=1;i<n-1;i++)
        {
            R=1/x;
            t1=R*t0;
            t0=t1;
            sum=sum+t1;
        }
    fprintf(fp,"%.2f\t%.3f\t%f\n",x,sum,log(sum));
    }    
}