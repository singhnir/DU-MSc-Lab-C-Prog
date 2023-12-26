#include <stdio.h>
#include <math.h>

/*
 * mind map
 * --------
 *  mathematical function
 *    -> integrator
 *     -> root_finding for the integration results
 *      -> print roots
 */

FILE *p = NULL;
float acc = 0.00001;

// intervals for integration
float t0= 0;
float t1= M_PI;
// step_size for integration
int integ_steps = 500;

// parameters
int   N = 1;
float A = 1.5;

// function for which integral is evaluated
// integration variable = t;
float
func (float t, float x)
{
	return ( cos(pow(x,A)*cos(t))*pow(sin(t),2*N+1) );
}

float 
trapez (float x)
{


	float a = t0;
	float b = t1;
	float n = integ_steps;

	float sum=0;

	// step size
	float h = (b-a)/(float)n;

	for (int i = 1; i<n; i++)
		sum+=2*func(a+(i*h),x);

	return ( h/2.0*(func(a,x)+func(b,x)+sum) );
}

float 
simpson (float x)
{
	float a = t0;
	float b = t1;
	float n = integ_steps;

	float sum=0;

	// finding step size with number of brackets = n 
	float h = (b-a)/(float)n;

	for (int i = 1; i<n; i++) {
		if (i%2 == 0)
			sum+=2*func(a+(i*h),x);
		else
			sum+=4*func(a+(i*h),x);
	}

	return ( h/3.0*(func(a,x)+func(b,x)+sum) );
}


// for this integration rule is fixed as trapez
// see next example to see how to change the rule
// and pass different functions
float
bisec (float rule(float x), float a, float b)
{
	float m;
	
	// initial check
	if (rule(a) * rule(b) >= 0)
		return -1;	

	do {
		m = (a+b)/(2.0);
		if (rule(a)*rule(b) <= 0)
			b=m;
		else
			a=m;
	} while( fabs(b-a) >= acc );

	return a;
}


// this is sample to pass function directly
// ie either the integration rule can be 
// simpsons or trapez or quadrature sum
// and it should be called as 
// sect(quardrature, a,b) in main
float
sect (float rule(float x), float a, float b)
{
	float m;

	// initial check
	if (rule(a) * rule(b) >= 0)
		return -11;

	do {
		m = (rule(b)*a - rule(a)*b) /  (float) (rule(b) - rule(a));
		a = b;
		b = m;
	} while( fabs(b-a) >= acc );

	return a;
}


int 
plotting (float x)
{
	for (float i=0.;  i <=10.; i=i+0.001) {
		fprintf (p,"%f \t %f \n", i, func(i,x)); }
		fprintf(p,"\n \n"); // for using index in gnuplot
	return 0;
}


int 
main()
{
	p=fopen("ex4.txt","w");

	float root;
	float bracket = 0.01;

	for (float i = 0.1; i < 10.0; i+=bracket) {
		root=sect(trapez, i,i+bracket);
		// print roots only when intervals are of diff sign 
		if ( root != -11 ) {
			fprintf(p,"%f \n",root);
		}
	}
	fclose(p);
		
	return 0;
}
