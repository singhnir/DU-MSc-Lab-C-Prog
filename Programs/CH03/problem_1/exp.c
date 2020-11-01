// Exponential summations for fix n and x values
#include<stdio.h>
#include<math.h>

int main()
{
    int i,n,t0;
    float x,t1,R,sum;

    t0=1;   //defining first term of series
    sum=t0; //first term is also first partial sum

    printf("Enter the value of x: ");
    scanf("%f",&x);
    printf("Enter the number of terms : ");
    scanf("%d",&n);
    // printing for n=0
    printf("x\tn\tsum\n");
    // loop for summing terms using ratio
    for(i=1;i<=n;i++)
    {
        R=x/i;
        t1=R*t0;
        sum=sum+t1;
        t0=t1;
        printf("%.2f\t%d\t%.2f\n",x,i+1,sum);
    }
    printf("\nFor x=%.2f and n=%d, exponential sum= %.2f",x,n,sum);
}
