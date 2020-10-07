// exponential series for fixed x and different n
#include<stdio.h>
#include<math.h>

int main()
{
    FILE*fp=NULL;
    fp=fopen("xfixed.txt","w");
    int i,n,t0;
    double x,t1,R,sum;
    x=5;    //fixing x=5
    t0=1;   //defining first term of series
    sum=t0; //first term is also first partial sum
    printf("Enter the number of terms: ");
    scanf("%d",&n);

    printf("x\tn\tSn");
    // loop for summing terms using ratio
    for(i=1;i<=n;i++)
    {
        R=x/i;
        t1=R*t0;
        sum=sum+t1;
        t0=t1;
        //printf("\n%.2f\t%d\t%.2f\n",x,i,sum);
        fprintf(fp,"%d\t%.2f\n",i,sum);
    }
}
