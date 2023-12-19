#include <stdio.h>
#include <math.h>

/*
 * Receipe
 * 1. figure all the constants
 * 2. do root/integration for sample function and check it's correct
 * 3. plot the figure before root finding
 * 4. put all together to fit the question
 */

/* What are constants?
 * integration limits, integration step size
 */
float t0 = 0;
float t1 = 2*M_PI;
float n  = 500;

float acc = 0.00001;

float 
func(float x, float z)
{
	return	( cos(z*cos(x))/(2*M_PI)  );
}

/*
 * Variable is z in integration
 */
float
simpson(float z)
{
	float sum = 0;
	float h   = (t1-t0)/(float)n;

	for (int i=1; i<n; i++) {
		if (i%2 ==0)
			sum+=2*func(t0+i*h, z);
		else
			sum+=4*func(t0+i*h, z);
	}

	return ( h/3.0*( func(t0,z) + func(t1,z) + sum ) );
}

/*
 * find roots that simpson returns
 */
float 
sect (float a, float b)
{
	float m;
	if (simpson(a)*simpson(b) > 0)
		return -1;
	do {
		m = ( a*simpson(b)-b*simpson(a)) / ( simpson(b)-simpson(a) );
		a = b;
		b = m;
	} while ( fabs(a-b) > acc);

	return a;
}


	
int 
main ( )
{
	float root;
	float bracket = 0.0001;

 	for (float z = 0.0; z<=12. ; z+=bracket) {
 		// printf("%f %f \n", z, simpson(z)); // for plotting
 		root=sect(z, z+bracket);
 		if (root != -1) 
			printf("%f\n", root);
 	}

	return 0;
}
