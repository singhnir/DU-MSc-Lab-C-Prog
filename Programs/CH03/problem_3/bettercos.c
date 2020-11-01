// evaluting cosine(x) BETTER VERSION
#include<stdio.h>
#include<math.h>
int main()
{

    double x,t0,t1,R,sum,accuracy=0.00001;
    printf("Enter the value of x:");
    scanf("%lf",&x);

    t0=1;   //defining first term of series
    sum=t0; //first term is also first partial sum

    printf("n\ttn\tSn\tfabs(tn/sum)\n");

    // displaying t0 term and sum
    printf("1\t%.2f\t%.2f\t%f\n",t0,sum,fabs(t0/sum));

    int i=1;
    do{
        R=-(x*x)/((2*i-1)*(2*i));
        t1=R*t0;
        sum=sum+t1;
        t0=t1;
        i++;
        printf("%d\t%.2f\t%.2f\t%f\n",i,t1,sum,fabs(t1/sum));
    } while(fabs(t1/sum)>accuracy);
    printf("\nThe sum of cos(%.2f) is: %f summing %d terms.",x,sum,i);
}
