// it contains functions to evaluate the integration and roots
// (trapezidal,simson,bisection, secant)
// use #include"integral.c" in the program you wished to use this

//Function to perform factorial
double factorial(int n)
{
  int i;
  double fact=1;
  for(i=n;i>=1;i--)
  {
    fact=fact*i;
  }
  return fact;
}
/*************************************************/
/***************TRAPEZOIDAL METHOD***************/
/************ONE VARIABLE EXPRESSION************/
/*************************************************/
double trapezoidal(double func(double x),double a,double b,int n)
{
  int i;
  double x,h,integral,sum=0;
  h=fabs(b-a)/n;
  // to calculate the summation term
  for(i=1;i<n;++i)
  {
    x=a+i*h;
    sum=sum+func(x);
  }
  integral=(h/2)*(func(a)+func(b)+2*sum);
  return integral;
}

/*************************************************/
/***************TRAPEZOIDAL METHOD***************/
/************TWO VARIABLE EXPRESSION************/
/*************************************************/
double trap(double f(double x,double var),double var,double a,double b,double n)
{
  int i;
  double x,h,integral,sum=0;
  h=fabs(b-a)/n;
  // to calculate the summation term
  for(i=1;i<n;++i)
  {
    x=a+i*h;
    sum=sum+f(x,var);
  }
  integral=(h/2)*(f(a,var)+f(x,var)+2*sum);
  return integral;
}

/*************************************************/
/***************SIMPSON'S 1/3 METHOD***************/
/************ONE VARIABLE EXPRESSION************/
/*************************************************/
double simpson13(double func(double x),double a,double b,double n)
{
  double x,h,integral,sum=0;
  int i;
  h=fabs(b-a)/n;
  // to calculate the summation term
  for(i=1;i<n;++i)
  {
    x=a+i*h;
    if(i%2==0){
      sum=sum+2*func(x);
    }
    else{
      sum=sum+4*func(x);
    }
  }
  integral=(h/3)*(func(a)+func(b)+sum);
  return integral;
}

/*************************************************/
/***************SIMPSON'S 3/8 METHOD***************/
/************ONE VARIABLE EXPRESSION************/
/*************************************************/
double simpson38(double func(double x),double a,double b,double n)
{
  double x,h,integral,sum=0;
  int i;
  h=fabs(b-a)/n;
  // to calculate the summation term
  for(i=1;i<n;++i)
  {
    x=a+i*h;
    if(i%3==0){
      sum=sum+2*func(x);
    }
    else{
      sum=sum+3*func(x);
    }
  }
  integral=(3*h/8)*(func(a)+func(b)+sum);
  return integral;
}


/*************************************************/
/***************ROOT FINDING***************/
/*************BISECTION METHOD*************/
/*************************************************/

double bisection(double f(double x),float a,float b)
{
  double x,xm,xl,xr,accuracy=0.00001,xinc=0.5,z;
  for (x=a;x<=b;x+=xinc)
    {
      if (f(x)*f(x+xinc)<=0)
      {
        xl=x;
        xr=x+xinc;
        do
        {
          xm=(xl+xr)/2.0;
          if (f(xm)*f(xl)>=0)
          {
            xl=xm;
          }
          if (f(xm)*f(xl)<=0)
          {
            xr=xm;
          }
          z=fabs((xl-xr)/(xl+xr));
          //printf("xm=%f\tf(xm)=%f\tz=%f\taccuracy=%f\n",xm,J0(xm),z,accuracy);
        }
        while(z>accuracy);
        printf("\nroot=%f\tf(xm)=%f\tz=%f\taccuracy=%f\n",xm,f(xm),z,accuracy);
      }
    }
}

/*************************************************/
/***************ROOT FINDING***************/
/***************SECANT METHOD***************/
/*************************************************/
double sec(double f(double x), double x1, double x2)
{
    int i=1;
    double x3;
    //printf("iter\tx1\t\tx2\t\tx3\t\tf(x3)\n");
    do{
        x3=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
        //printf("%d\t%lf\t%lf\t%lf\t%lf\n",i,x1,x2,x3,f(x3));
        x1=x2;
        x2=x3;
        i++;
    }while(fabs(f(x3))>0.00001);
    return x3;
}
double secant(double f(double x), double a, double b)
{
    double x,xb; // x starting point a, xb tending from a to b
    for(x=a;x<=b;x=x+0.01)
    {
        xb=x+0.01;
        if(f(x)*f(xb)<=0){
            printf("\nIn the interval: %.3lf and %.3lf\n",x,xb);
            double root=sec(f,x,xb);
            printf("The root is: %.4lf\n",root);
        }
    }
}
