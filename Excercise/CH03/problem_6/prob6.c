#include<stdio.h>
#include<math.h>

int main()
{
    FILE*fp=NULL;
    fp=fopen("prob6.txt","w");

    double z,t0,t1,R,sum,accuracy;
    accuracy=0.00001;

    for(z=-10;z<=0;z=z+0.05)
    {
        int i=1;
        t0=1;    //defining first term of series
        sum=t0; //first term is also first partial sum
        do{
            R=pow(z,3)/((3*i)*(3*i-1));
            t1=R*t0;
            sum=sum+t1;
            t0=t1;
            i++;
        } while(fabs(t1/sum)>accuracy);
        sum=sum*0.35503;
        fprintf(fp,"%lf\t%lf\n",z,sum);
    }    
}