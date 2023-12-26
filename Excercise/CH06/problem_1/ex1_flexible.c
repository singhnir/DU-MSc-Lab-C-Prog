#include <math.h>
#include"template.c"

float
f1(float x, float y)
{
	return atan(x)/(x*x);
}

int
main ()
{
	float a=5;
	float b=10;

	printf("trapezoidal = %f\n",trapez(f1, a, b, 200)); 
	printf("simpson     = %f\n",simpson(f1, a, b, 200)); 

	printf("now with auto iterations \n");

	printf(", trapezoidal = %f\n",integ(trapez, a, b, f1)); 
	printf(", simpson     = %f\n",integ(simpson, a, b,f1)); 

}
