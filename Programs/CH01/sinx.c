// sinx.c - This program calculates sin(x)
#include <stdio.h>
#include <math.h>

main()
{
	float x,y;
	//x is factor of pi y is value of sin(x)
	printf("Enter the value of factor of pi\n");
	scanf("%f",&x);
	y = sin(x);
	printf("%f, %f\n", x,y);
	return 0;
}
