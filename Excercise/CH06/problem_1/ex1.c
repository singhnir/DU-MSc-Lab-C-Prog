#include <math.h>
#include <stdio.h>

/*
 *  mathematical function
 *   -> integrator (different integrators)
 *    -> compare accuracy by no of integration step need so n is variable
 *     -> print no of steps and integration value
 */

FILE *p   = NULL;
float acc = 0.00001;

// integration constants
float t0 = 5;
float t1 = 10;

float
func(float x)
{
	return atan(x)/(x*x);
}

float 
func1(float x)
{
	return (x);
}

float
trapez(int n)
{
	float a = t0;
	float b = t1;

	float sum = 0;
	float h = (b-a)/(float)(n);	

	for (int i = 1; i<n; i++) {
		sum+=2*func(a+i*h);
	}

	return( h/2.0*(func(a)+func(b)+sum) );
}

float
simpson(int n)
{
	float a = t0;
	float b = t1;

	float sum = 0;
	float h = (b-a)/(float)(n);	

	for (int i = 1; i<n; i++) {
		if (i%2==0)
			sum+=2*func(a+i*h);
		else
			sum+=4*func(a+i*h);
	}

	return( h/3.0*(func(a)+func(b)+sum) );
}

float
integ_steps( float rule(int n) ) 
	/*
	 * now float simpson(int n) and float trapez(int n) can be passed
	 * as a integration rule to figure opt n that give answer close to
	 * acc, in the main function this will be called as
	 * integ_steps(trapez) , integ_steps(simpson)
	 */
{
	float initial, final=-1;

	int n = 2;  // initial step for integration
	do {
		initial = final;
		n+=2; // always even no of steps for simpson 
		final   = rule(n); 
	} while ( fabs(initial-final) >= acc );

	printf("took %d steps ", n);
	return final;

}

int
main ()
{
	// checking with func1
	printf("10 fixed steps \n");
	printf("%f\n", trapez(10));
	printf("%f\n", simpson(10));

	printf("\n \n");
	
	printf("varied steps based on accuracy \n");
	printf("%f\n", integ_steps(trapez));
	printf("%f\n", integ_steps(simpson));

	return 0;
}
