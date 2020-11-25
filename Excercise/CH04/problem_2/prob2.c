// bessel function
#include<stdio.h>
#include<math.h>
//factorial function declaration
double factorial(int n){
    if (n>=1)
        return n*factorial(n-1);
    else
        return 1;
}
// finding the sum of the bessel series 
double Jn(double x, int n){
    int k=1;
    double t0,t1,R,sum,acc=0.00001;
    t0=1/factorial(n);
    sum=t0;
    do{
        R=-(x*x/4)/(k*(n+k));
        t1=R*t0;
        sum=sum+t1;
        t0=t1;
        k++;
    }while(fabs(t1/sum)>acc);
    sum=sum*pow(x/2,n);
    return sum;
}
// function for J0
double J0(double x){
    return Jn(x,0);
}

int main()
{
  //xm=root, (xl,xr)=guess intervals
  float x,xm,xl,xr,accuracy=0.00001,xinc=0.5,z,a,b,x1,x2;
  int n,i;  // n= np of intervals

  printf("Enter the min value x (a):");
  scanf("%f",&a);
  printf("Enter the max value x (b):");
  scanf("%f",&b);
  // tabulating the function in range [a,b]
  printf("x\tJ0(x)\n");
  for (x=a;x<=b;x+=0.1)
  {
    printf("%.2f\t%f\n",x,J0(x));
  }
  // Want to give multiple large intervals
  printf("How many times you want to input intervals:");
    scanf("%d",&n);

  for (i=1;i<=n;i+=1)
  {
    printf("\nInput the intervals:\n");
    scanf("%f%f",&x1,&x2);
    printf("xm\t\tJ0(xm)\t\taccuracy\n");
    for (x=x1;x<=x2;x+=xinc)
    {
      if (J0(x)*J0(x+xinc)<0)
      {
        xl=x;
        xr=x+xinc;
        do
        {
          xm=(xl+xr)/2.0;
          if (J0(xm)*J0(xl)>0)
          {
            xl=xm;
          }
          if (J0(xm)*J0(xl)<0)
          {
            xr=xm;
          }
          z=fabs((xl-xr)/(xl+xr));
          printf("%f\t%f\t%f\n",xm,J0(xm),z);
        }
        while(z>accuracy);
        printf("\nroot=%f\tJ0(xm)=%f\taccuracy=%f\n",xm,J0(xm),z);
      }
    }
  }
}