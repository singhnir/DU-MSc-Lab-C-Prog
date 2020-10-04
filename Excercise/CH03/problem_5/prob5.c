#include<stdio.h>
#include<math.h>

int main()
{
    FILE*fp=NULL;
    fp=fopen("prob5.txt","w");

    double z,t0,t1,R,sum,accuracy;
    accuracy=0.00001;

    for(z=0;z<=5;z=z+0.01)
    {
        int k=2;
        t0=1/(2*sqrt(M_PI));    //defining first term of series
        sum=t0; //first term is also first partial sum
        do{
            R=(4*z*z*(3-k))/(2*k*(k-1));
            t1=R*t0;
            sum=sum+t1;
            t0=t1;
            k=k+2;
        } while(fabs(t1/sum)>accuracy);
        fprintf(fp,"%lf\t%lf\n",z,sum);
    }   
}