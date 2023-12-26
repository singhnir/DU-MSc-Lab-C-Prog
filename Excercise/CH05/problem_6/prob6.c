#include <math.h>
#include <stdio.h>

/*
 *  Let me Nit Pick - The question is asking for a Orbit diagram not
 *  a bifurcation diagram, bif'n is in context of stability analysis 
 *  not for period doubling,  there you  go hehe non-linear dynamics
 */ 

// difference equation of naive population model  x = ax(1-x)

double x_ini = 0.72; 

float 
func( double x, double alpha )
{
	double n = 1;
	do {	
		x += alpha*x* ( 1 - x );
		n++;
		if ( n >= 10000.0 )                        // taking care of transient behaviour
			printf ("%f \t %f \n", alpha, x ) ;   //  either a fixed point or oscillates with period 
	} while ( n <= 10100.0 ); 

	return 0;
}


int 
main () 
{
	double x = x_ini;  
	for ( double alpha = 0.0 ; alpha <= 4.0 ; alpha+=0.005) {
		func (x, alpha);
	}
	return 0;
}
