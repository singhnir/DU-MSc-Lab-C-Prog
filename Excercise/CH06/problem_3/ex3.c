#include <stdio.h>
#include <math.h>

float acc   = 0.00001;
int integ_n = 800;    // integration steps

// parameters
float   l = 1.;
float   k = 1.;
float   m = 1.;


// function for which root needs to be found
// r_0 and r_m values
float
func_root (float r, float E )
{
	return	( 2*m*E/(l*l) - 2*m*(-k)/(r*l*l) - 1/(r*r) );	
}

// function for which integral is evaluated
float
func (float r, float E)
{
	return ( pow(r,2)* sqrt(func_root(r,E)) );
}


float
bisec (float a, float b, float E)
{
	int iteration=0;
	float m;

	// initial check
	if (func_root(a,E) * func_root(b,E) >= 0)
		return -1;	

	do {
		m = (a+b)/(2.0);
		if (func_root(a,E)*func_root(m,E) <= 0)
			b=m;
		else
			a=m;
		iteration++;
	} while( fabs(b-a) >= acc );

//	printf("done in %d \n", iteration);
	return b;
}

float
sect (float a, float b, float E)
{
	int iteration=0;
	float m;

	// initial check
	if (func_root(a,E) * func_root(b,E) >= 0)
		return -1;

	do {
		m = (func_root(b,E)*a - func_root(a,E)*b) /  (float) func_root(b,E) - func_root(a,E);
		a = b;
		b = m;
		iteration++;
		printf ("%f \t %f\n", b,m);
	} while( fabs(b-a) >= acc );

	printf("done in %d", iteration);
	return b;
}

float 
trapez (float a, float b, float E)
{
	float h;
	float sum=0;

	// step size
	h = (b-a)/(float)integ_n;

	for (int i = 1; i<integ_n; i++)
		sum+=2*func(a+(i*h),E);

	return ( h/2.0*(func(a,E)+func(b,E)+sum) );
}

float 
simpson (float a, float b, float E) 
{
	float h;
	float sum=0;

	// finding step size with number of brackets = n 
	h = (b-a)/(float)integ_n;

	for (int i = 1; i<integ_n; i++) {
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

	// change of variable of integration from (a to b) --> (-1 to +1)
	// f(x) limits (a  to  b) change to
	// f(y) limits (-1 to +1)
	// such that y = (a+b)/2.0 + (b-a)/2.0*x 
	
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
	float roots[5]; // create an array for storing multiple roots
	int r_index=0;  // corresponding index

	float bracket = 0.00001;
	float E = -0.18;
	// float E = -0.25;

	for (float i = bracket ; i<=10; i=i+bracket) {

		// secant method give inf for this function!
		roots[r_index] = bisec(i,i+bracket, E);

		if (roots[r_index] != -1) // returning -1 means brackets are same sign
			r_index++;        // it doesn't, so store the value and 
					  // increment the index for next roots  
	}

	// last roots[] arrray element will have -1 since that's end of loop 
	// dont include that in no of root
	//
	// printf ("no of roots =  %d \n", r_index);
	// for (int i=0; i<r_index; i++)
	// 	printf("%f\n", roots[i]);
	// return 0;
	//
	
	float a = roots[0];
	float b = roots[1];	
	
	printf ("r_upper \t trapezoidal \t simpsons \t guass_quadrature \n");
	for(float i = a; i<= b; i+=0.01)  	
		printf ( "%f \t %f \t %f \t %f \n", i, trapez(a,i,E), simpson(a,i,E), quad(a,i,E) );

	return 0;
}




