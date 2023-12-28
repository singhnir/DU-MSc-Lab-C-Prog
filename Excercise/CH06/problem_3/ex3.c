#include <stdio.h>
#include <math.h>
#include <stdlib.h>

FILE *p;
float acc       = 0.00001;
int integ_steps = 800;    // integration steps
		    
/*
 * Mind Map
 * --------
 *
 *  mathematical function
 *   -> root_finding
 *    -> roots as integrator's limits (a,b)
 *     -> plot for integrator
 */

		      
// parameters
float   L = 1.;
float   K = 1.;
float   M = 1.;


// function for which root needs to be found
// r_0 and r_m values
float
func_root (float r, float E )
{
	return	( 2*M*E/(L*L) - 2*M*(-K)/(r*L*L) - 1/(r*r) );	
}

// 2 variable function for which integral is evaluated
float
func (float r, float E)
{
	return ( pow(r,2)* sqrt(func_root(r,E)) );
}


float
bisec (float a, float b, float E)
{
	float m;

	// initial check
	if (func_root(a,E) * func_root(b,E) >= 0)
		return -11;	

	do {
		m = (a+b)/(2.0);
		if (func_root(a,E)*func_root(m,E) <= 0)
			b=m;
		else
			a=m;
	} while( fabs(b-a) >= acc );

	return b;
}

float
sect (float a, float b, float E)
{
	float m;

	// initial check
	if (func_root(a,E) * func_root(b,E) >= 0)
		return -11;

	do {
		m = (func_root(b,E)*a - func_root(a,E)*b) /  (float) (func_root(b,E) - func_root(a,E));
		a = b;
		b = m;
	} while( fabs(b-a) >= acc );

	return b;
}

float 
trapez (float a, float b, float E)
{
	float n = integ_steps;

	float h;
	float sum=0;

	h = (b-a)/(float)n;

	for (int i = 1; i<n; i++)
		sum+=2*func(a+(i*h),E);

	return ( h/2.0*(func(a,E)+func(b,E)+sum) );
}

float 
simpson (float a, float b, float E) 
{
	float n = integ_steps;

	float h;
	float sum=0;

	h = (b-a)/(float)n;

	for (int i = 1; i<n; i++) {
		if (i%2 == 0)
			sum+=2*func(a+(i*h),E);
		else
			sum+=4*func(a+(i*h),E);
	}

	return ( h/3.0*(func(a,E)+func(b,E)+sum) );
}


/* based on the GAUSS.C file included */
float
quad (float a, float b, float E)
{
	float sum   = 0;
	int n = 8;   // switch case n = order of gauss quadrature
	float x[20]; // roots
	float w[20]; // weights

	#include "GAUSS.C" // a switch case file in present working directory 

        /* 
	 * change of variable of integration from y -> x 
	 *
         *       b                        +1
         *      /           (b - a)     /
         *     |  y * dy  = ------- *  |  x * dx
         *    /                2      /
         *     a                       -1
	 *
	 * with subsitution 
	 *
         *           (a + b)   (b - a)
         *       y = ------- - ------- * x
         *              2         2
	 *
	 *  integration(f(y)) limits (a  to  b)  changes to
	 *  integration(f(x)) limits (-1 to +1) 
	 *  now GAUSS quadrature can be applied in the (-1 to 1) limit
         */

	for (int i=0; i<n/2; i++) {
		sum+=w[i]*func( ((a+b) + (b-a)*x[i])/2.0, E );
		sum+=w[i]*func( ((a+b) - (b-a)*x[i])/2.0, E ); // symmetry roots 
	}

	return (sum*(b-a)/2.0); 
}


int 
plotting (float E)
{
	for (float i=0.;  i <=10.; i=i+0.001)
		printf ("%f \t %f \n", i, func_root(i,E));
	return 0;
}

int 
main()
{
	p = fopen("ex3.txt","w");

//	float roots[5]; // create an array for storing multiple roots

/*
 *	if array variables are not allowed
 *	use calloc from stdlib.h to redefine the above array 
 */
	float *roots = calloc(5,sizeof(float));
	int r_index=0;  // corresponding index

	float bracket = 0.00001;
	float E = -0.18;
	// float E = -0.25;

	for (float i = bracket ; i<=10; i=i+bracket) {

		roots[r_index] = sect(i,i+bracket, E);

		if (roots[r_index] != -11) // returning -11 means brackets are same sign
			r_index++;         // if it doesn't, store the value and increme
					   // nt the index for next roots  
	}

	/* last roots[] arrray element will have -1 since that's end of loop 
	 * dont include that in no of root - following will print roots
	 *
	 * printf ("no of roots =  %d \n", r_index);
	 * for (int i=0; i<r_index; i++)
	 * 	printf("%f\n", roots[i]);
	 * return 0;
	 */
	
	float a = roots[0];
	float b = roots[1];	
	
	// print integration results from lower a to all iterations till b
	fprintf (p,"#upper limit \t trapezoidal \t simpsons \t guass_quadrature \n");
	for(float i = a; i<= b; i+=0.01)  	{
		fprintf (p, "%f \t %f \t %f \t %f \n", 
				i, trapez(a,i,E), simpson(a,i,E), quad(a,i,E) );
	}

	fclose(p);

	// free the allocated pointer
	free(roots);

	return 0;
}
