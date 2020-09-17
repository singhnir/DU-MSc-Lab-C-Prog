// program to export data points from periodic function
#include<stdio.h>
#include<math.h>
//defining the periodic function
float y(float x)
{
  if(x>=0 && x<M_PI)    // for given range
  {
    return x;
  }
  else if(x>=M_PI && x<2*M_PI)  // for given range
  {
    return 2*M_PI-x;
  }
  // Since it's a periodic function at 2*pi
  else if(x>=2*M_PI)
  {
    // so every time  x>2*pi we take the x value back by 2*pi
    return y(x-2*M_PI);
  }
  else if(x<0)
  {
    // so every time  x<2*pi we add the x value by 2*pi
    return y(x+2*M_PI);
  }
}
//main function will call above function
int main()
{
  float x;
  //FILE*fp: declaring a pointer of type file
    //NULL: to make sure the file was successfully opened
  FILE*fp=NULL;
  fp=fopen("triangular.txt","w");
  //Loop to calculate and store data-points
  for (x=-6*M_PI;x<=6*M_PI;x=x+0.1)
  {
    fprintf(fp,"%f\t%f\n",x,y(x));
  }
  //close the file handle
  fclose(fp);
}
