// program to export data points for given periodic step function
#include<stdio.h>
#include <math.h>

float f(float x)
{
  if(x>=0 && x<=M_PI)    // for given range
  {
    return 1;
  }
  else if(x>=M_PI && x<=2*M_PI)  // for given range
  {
    return -1;
  }
  // Since it's a periodic function at 2*pi
  else if(x>=2*M_PI)
  {
    // so every time  x>2*pi we take the x value back by 2*pi
    return f(x-2*M_PI);
  }
  else if(x<0)
  {
    // so every time  x<2*pi we add the x value by 2*pi
    return f(x+2*M_PI);
  }
}
//main function will call above function
int main()
{
  float x;

  FILE*fp=NULL;
  fp=fopen("periodic.txt","w");
  //Loop to calculate and store data-points
  for (x=-6*M_PI;x<=6*M_PI;x=x+0.1)
  {
    fprintf(fp,"%f\t%f\n",x,f(x));
  }
}
