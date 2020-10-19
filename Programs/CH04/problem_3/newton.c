// finding root using newton raphson method
#include<stdio.h>
#include<math.h>
 
// defining the function
float f(float x)
{
  return sin(x)-x*cos(x);
}
// derivative of the function
float df(float x)
{
  return x*sin(x);
}
 
int main()
{
  float x0,x1,h,accuracy=0.00001;
  int n,i;  // n= np of intervals

  FILE*fp=NULL;
  fp=fopen("newton.txt","w");

  //Want to give multiple initial guesses
  printf("How many times you want to give intial guess:");
  scanf("%d",&n);

  for (i=1;i<=n;i+=1)
  {
    printf("\nEnter the initial guess (x0):");
    scanf("%f",&x0);
    do
    {
    	h=-f(x0)/df(x0);
      x1=x0+h;
      x0=x1;
      fprintf(fp,"%f\t%f\n",x1,f(x1));
    } while(fabs(h/x0)>accuracy);
    printf("root=%f\tf(x1)=%f\taccuracy=%f\n",x1,f(x1),accuracy);
  }
}