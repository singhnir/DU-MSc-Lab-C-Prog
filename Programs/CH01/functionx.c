//to compute f(x)=x^3+sin(x)*log(x)

#include <stdio.h>
#include <math.h>

//defining the function
float func(float x)
{
    float y;
    y=x*x*x+sin(x)*log(x);
    return (y);
}

//main function which will call above function
int main()
{
	float a,b;
	printf("Enter the value for x:\n");
	scanf("%f",&a);
	// function call
	b = func(a);
	printf("for x=%6.2f the value of function f(x)= %6.2f\n",a,b);
  return 0;
}
