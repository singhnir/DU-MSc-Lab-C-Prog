#include<stdio.h>
#include<math.h>

int main()
{
    int i,n;
    float x,t0,t1,R,sum;

    printf("Enter the value of x:");
    scanf("%f",&x);
    printf("Enter the no. of terms n:");
    scanf("%d",&n);
    t0=x;   //defining first term of series
    sum=t0; //first term is also first partial sum
    printf("n\ttn\tSn");
    // loop for summing terms using ratio
    for(i=1;i<n;i++)
    {
        R=-(x*x)/(2*i+1)/(2*i);
        t1=R*t0;
        sum=sum+t1;
        t0=t1;
        printf("\n%d\t%.2f\t%.2f\n",i+1,t1,sum);
    }
    printf("\nFor x=%.2f and n=%d, sine sum= %.4f",x,n,sum);
    return 0;
}