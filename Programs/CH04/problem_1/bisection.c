// finding root using Bisection Method
#include<stdio.h>
#include<math.h>
 
// defining the function
float f(float x)
{
  return sin(x)-x*cos(x);
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
  printf("x\tf(x)\n");
  for (x=a;x<=b;x+=0.1)
  {
    printf("%.2f\t%f\n",x,f(x));
  }
  // Want to give multiple large intervals
  printf("How many times you want to input intervals:");
    scanf("%d",&n);

  for (i=1;i<=n;i+=1)
  {
    printf("\nInput the intervals:\n");
    scanf("%f%f",&x1,&x2);

    for (x=x1;x<=x2;x+=xinc)
    {
      if (f(x)*f(x+xinc)<0)
      {
        xl=x;
        xr=x+xinc;
        do
        {
          xm=(xl+xr)/2.0;
          if (f(xm)*f(xl)>0)
          {
            xl=xm;
          }
          if (f(xm)*f(xl)<0)
          {
            xr=xm;
          }
          z=fabs((xl-xr)/(xl+xr));
          printf("xm=%f\tf(xm)=%f\tz=%f\taccuracy=%f\n",xm,f(xm),z,accuracy);
        }
        while(z>accuracy);
        printf("\nroot=%f\tf(xm)=%f\tz=%f\taccuracy=%f\n",xm,f(xm),z,accuracy);
      }
    }
  }
}