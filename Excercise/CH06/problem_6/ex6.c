#include <stdio.h>
#include <math.h>

/*
 * Receipe
 * 1. figure all the constants
 * 2. check for sample functions 
 * 3. plot for roots
 * 4. fit all together according  to given question
 * 5. write it to file 
 */

/*
 *   mathematical function (2 variables)
 *     -> integrator
 *      -> root_finding for the integration results
 *         [if roots are found for different integration rules then
 *          do include sect(float rule(float x), float a, float b)]
 *       -> print roots
 */


// constants
// ---------
// integration limits, step_size
float t0           = 0;
float t1           = M_PI; 
int integ_steps    = 500;

float acc = 0.00001;

// order N
int N  = 2;

// for file create declare pointer here
// but use fopen inside main() function
// and change all printf's inside defined 
// functions into fprintf
FILE *p = NULL;

int 
fact(int x)
{
	if (x <= 1)
		return 1;

	return ( x*fact(x-1) ); 
}

float 
func (float o, float z)
{
	return ( cos(z*cos(o))*pow(sin(o),2*N+1) );  // initial check should return t1-t0
}	

float
simpson1 (float z)
{
	// these are fixed 
	float a = t0;
	float b = t1;
	float n = integ_steps; 


	float h = (b-a)/(float)(n);
	float sum = 0;

	for (int i = 1; i < n; i++) {
		if (i%2==0)
			sum+=2*func(a+(i*h),z);
		else
			sum+=4*func(a+(i*h),z);
	}
	return (h/3.0*( func(a,z)+func(b,z)+sum ));
}

// multiplying the factor at last
float 
simpson (float z)
{
	return (simpson1(z)*pow(z,N)/(pow(2,N+1)*fact(N)));
}

// checking function
// float 
// simpson2 (float z)
// {
// 	return (z*z - 1);
// }


float 
sect (float a, float b)
{
	float m;
	if ( simpson(a)*simpson(b) > 0)
		return -2;
	do {
		m =(simpson(b)*a - simpson(a)*b)/ (simpson(b)-simpson(a)) ;
		a = b;
		b = m;
	} while ( fabs(a-b) > acc );

	fprintf (p, "%f\n", b);
	return b;
}

int 
main ()
{
	p = fopen ("ex6.txt", "w");
	float bracket=0.0001;

	// checks
	// -------
	//
	// 1. integration   = ok
	// printf("%f\n", simpson(0));
	//
	// 2.  roots finding = ok
	// for (float i=-3; i<3; i+=bracket)
	//  	sect(i,i+bracket);
	//
	// 3. factorial     = ok
	//  printf("%d\n", fact(3));
	//
	// 4. plot for the given question = ok
	// for (float i = 0.; i<=10.; i+=bracket)
        // 	printf("%f %f\n",i,simpson(i));	

	for (float i = 0.; i<=10.; i+=bracket)
		sect(i,i+bracket);

	fclose(p);
	return 0;
}
