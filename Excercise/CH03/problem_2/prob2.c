#include<stdio.h>
#include<math.h>

int main()
{
    FILE*fp=NULL;
    fp=fopen("prob2.txt","w");

    double x,t0,t1,R,sum,accuracy;
    accuracy=0.00001;

    for(x=0;x<=M_PI;x=x+0.01)
    {
        int i=1;
        t0=1;   //defining first term of series
        sum=t0; //first term is also first partial sum
        do{
            R=-(x*x)/((2*i-1)*(2*i));
            t1=R*t0;
            sum=sum+t1;
            t0=t1;
            i++;
        } while(fabs(t1/sum)>accuracy);
        fprintf(fp,"%.4f\t%.4f\n",x,sum);
        // .4f ensures 4 significant figures
    }
}
