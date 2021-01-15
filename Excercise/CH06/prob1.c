// problem 1
#include<stdio.h>
#include<math.h>
#include"integral.c"

// defining the function to evaluate
double f(double x)
{
    return atan(x)/(x*x);
}

int main()
{
    int n=2;	// starting with two interval
    double a=5,b=10,integral,answer;
 
    //using simpsons 1/3 for different number of sub-intervals until they converge to the accuracy
    do{
        integral=answer;
        n=n+2;	//n must be even
        answer=simpson13(f,a,b,n);
    }while(fabs(answer-integral)>=0.00001);

    printf("\nThe integral using Simpson's Rule is: %lf\n",answer);
    // using trapezoidal for different number of sub-intervals until they converge to the accuracy
	n=2;
    do{
        integral=answer;
        n++;
        answer=trapezoidal(f,a,b,n);
    }while(fabs(answer-integral)>=0.00001);
    printf("The integral using Trapezoidal Rule is: %lf",answer);

}