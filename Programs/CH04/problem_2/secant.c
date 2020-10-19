// finding root using secant method
#include<stdio.h>
#include<math.h>
 
// defining the function
float f(float x)
{
  return sin(x)-x*cos(x);
}
 
int main()
{
  float x,a,b,x1,x2,x3,accuracy=0.00001;
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
    do
    {
    	x3=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
    	x1=x2;
    	x2=x3;
    } while(fabs(f(x2))>accuracy);
    printf("root=%f\tf(x2)=%f\taccuracy=%f\n",x2,f(x2),accuracy);
  }
}