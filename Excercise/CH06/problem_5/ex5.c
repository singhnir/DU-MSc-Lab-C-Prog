#include <stdio.h>
#include <math.h>

/*
 * Receipe
 * 1. figure all the constants
 * 2. do root/integration for sample function and check it's correct
 * 3. plot the figure before root finding
 * 4. put all together to fit the question
 */

/*
 * What are constants?
 * integration limits, integration step size
 */

/*
 *   mathematical function (2 variables)
 *     -> integrator
 *      -> root_finding for the integration results 
 *         [if roots are found for different integration rules then
 *          do include sect(float rule(float x), float a, float b)]
 *       -> print roots
 */


float t0 = 0;
float t1 = 2*M_PI;
float integ_steps  = 500;

float acc = 0.00001;

FILE *p = NULL;

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
	float a = t0;
	float b = t1;
	float n = integ_steps;

	float sum = 0;
	float h   = (b-a)/(float)n;

	for (int i=1; i<n; i++) {
		if (i%2 ==0)
			sum+=2*func(a+i*h, z);
		else
			sum+=4*func(a+i*h, z);
	}

	return ( h/3.0*( func(a,z) + func(b,z) + sum ) );
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
 		if (root != -1) {
			fprintf(p,"%f\n", root);
			// break; // uncomment if only 1st root is needed 
		}
 	}

	fclose(p);
	return 0;
}
