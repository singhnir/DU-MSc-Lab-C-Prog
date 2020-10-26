/*sinx.c - This program calculates sin(x)
*a circle have 360 deg or 2*pi rad. (which is 2 × 3.1415=6.2831) rad in a circle.
*1 rad= 57.2957795 deg & 1 deg = 0.01745329 rad.*/
#include <stdio.h>
#include <math.h>
int main()
{
 	float deg,rad, val;
 	printf("Enter an angle in degrees: ");
 	scanf("%f",&deg);
 	rad = 0.0174532925*deg;
 	val = sin(rad);
 	printf("\nGiven angle in radians: %.2f\n",rad);
 	printf("The value of sin(%.0f): %.2f\n",deg,val);
}
