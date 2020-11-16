// exponential series sum for fixed n and different x
#include<stdio.h>
#include<math.h>

int main()
{
    FILE*fp=NULL;
    fp=fopen("nfixed.txt","w");
    int i,n;
    double x,t0,t1,R,sum;

    printf("Enter the number of terms: ");
    scanf("%d",&n);
    // loop for summing terms using ratio
    for(x=0.0;x<=6.0;x=x+0.1)
    {
        i=1;
        t0=1;    //defining first term of series
        sum=t0; //first term is also first partial sum
        do{
            R=x/i;
            t1=R*t0;
            sum=sum+t1;
            t0=t1;
            i++;
        } while(i<=n);
        fprintf(fp,"%lf\t%lf\n",x,sum);
    }
}