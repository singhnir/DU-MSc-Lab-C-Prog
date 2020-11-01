#include<stdio.h>
#include<math.h>

int main()
{
    FILE*fp=NULL;
    fp=fopen("prob4.txt","w");

    double z,t0,t1,R,sum,accuracy;
    accuracy=0.00001;

    for(z=0;z<=1;z=z+0.1)
    {
        int i=1;
        t0=z;   //defining first term of series
        sum=t0; //first term is also first partial sum        
        do{
            R=-(M_PI*M_PI*pow(z,4))/((4*i+1));
            t1=R*t0;
            sum=sum+t1;
            t0=t1;
            i++;
        } while(fabs(t1/sum)>accuracy);
        sum=sum*cos(M_PI*z*z/2);
        fprintf(fp,"%.4lf\t%.4lf\n",z,sum);
        // .4lf ensures 4 significant figures
    }
}
