#include<stdio.h>
#include<math.h>

//factorial function declaration
double factorial(int n)
{
    if (n>=1)
        return n*factorial(n-1);
    else
        return 1;
}

int main()
{
    FILE*fp=NULL;
    fp=fopen("prob3.txt","w");

    double t0,t1,R,sum,x,accuracy=0.00001;
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);

    for(x=0;x<=10;x=x+0.1)
    {
        int k=1;
        t0=1/factorial(n);
        sum=t0;     
        do{
            R=-(x*x/4)/(k*(n+k));
            t1=R*t0;
            sum=sum+t1;
            t0=t1;
            k++;
        } while(fabs(t1/sum)>accuracy);
        sum=sum*pow(x/2,n);
        fprintf(fp,"%.4lf\t%.4lf\n",x,sum);
        // .4lf ensures 4 significant figures
        //printf("%lf\t%lf\n",x,sum);
    }     
}
