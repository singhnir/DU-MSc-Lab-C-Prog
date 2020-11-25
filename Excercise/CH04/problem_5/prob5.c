// Chebyshev polynomial
#include<stdio.h>
#include<math.h>
// defining the functions
double U0(double x){
    return 1;
}
double U1(double x){
    return 2*x;
}
//General form for given n and x
double Un(double x, int n){
    if(n==0){
        return U0(x);
    }
    else if(n==1){
        return U1(x);
    }
    else{
        //using the recurrence relation
        return 2*x*Un(x,n-1)-Un(x,n-2);
    }
}
//function for U4(x)
double U4(double x){
    return Un(x,4);
}
int main()
{
    FILE*fp=NULL;
    fp=fopen("prob5-U4.txt","w");

    float x,a,b,x1,x2,x3,accuracy=0.00001;
    int n,i;  // n= np of intervals

    printf("Enter the min value x (a):");
    scanf("%f",&a);
    printf("Enter the max value x (b):");
    scanf("%f",&b);
    // tabulating the function in range [a,b]
    printf("x\tf(x)\n");
    for (x=a;x<=b;x+=0.01)
    {
        printf("%.2f\t%f\n",x,U4(x));
        fprintf(fp,"%.2f\t%f\n",x,U4(x));
    }
    // Want to give multiple large intervals
    printf("How many times you want to input intervals:");
    scanf("%d",&n);

    for (i=1;i<=n;i+=1)
    {
        printf("\nInput the intervals:\n");
        scanf("%f%f",&x1,&x2);
        // using secant method
        do
        {
            x3=(x1*U4(x2)-x2*U4(x1))/(U4(x2)-U4(x1));
            x1=x2;
            x2=x3;
        } while(fabs(U4(x2))>accuracy);
        printf("root=%f\tf(x2)=%f\taccuracy=%f\n",x2,U4(x2),accuracy);
    }

}