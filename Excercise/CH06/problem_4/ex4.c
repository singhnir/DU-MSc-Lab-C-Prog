#include <stdio.h>
#include <math.h>

float acc = 0.00001;

// parameters
int   N = 1;
float a = 1.5;

// function for which integral is evaluated
float
func (float t, float x)
{
	return ( cos(pow(x,a)*cos(t))*pow(sin(t),2*N+1) );
}

float 
trapez (float x)
{

	// intervals for integration
	float t0= 0;
	float t1= M_PI;
	// step_size for integration
	int integ_n = 300;

	float h;
	float sum=0;

	// step size
	h = (t1-t0)/(float)integ_n;

	for (int i = 1; i<integ_n; i++)
		sum+=func(t0+(i*h),x);

	return ( h/2.0*(func(t0,x)+func(t1,x)+2*sum) );
}

float 
simpson (float x)
{
	float h;
	float sum=0;
     	int   integ_n = 200; 
	float t0 = 0;
	float t1 = M_PI;

	// finding step size with number of brackets = n 
	h = (t1-t0)/(float)integ_n;

	for (int i = 1; i<integ_n; i++) {
		if (i%2 == 0)
			sum+=2*func(t0+(i*h),x);
		else
			sum+=4*func(t0+(i*h),x);
	}

	return ( h/3.0*(func(t0,x)+func(t1,x)+sum) );
}


// for this integration rule is fixed as trapez
// see next example to see how to change the rule
// and pass different functions
float
bisec (float a, float b)
{
	int iteration=0;
	float m;
	
	// initial check
	if (trapez(a) * trapez(b) >= 0)
		return -1;	

	do {
		m = (a+b)/(2.0);
		if (trapez(a)*trapez(b) <= 0)
			b=m;
		else
			a=m;
		iteration++;
	} while( fabs(b-a) >= acc );

	printf("done in %d \n", iteration);
	return b;
}


// this is sample to pass function directly
// ie either the integration rule can be 
// simpsons or trapez or quadrature sum
// it should be called as sect(quardrature, a,b)
float
sect (float integ(float x), float a, float b)
{
	int iteration=0;
	float m;

	// initial check
	if (integ(a) * integ(b) >= 0)
		return -1;

	do {
		m = (integ(b)*a - integ(a)*b) /  (float) (integ(b) - integ(a));
		a = b;
		b = m;
		iteration++;
//		printf ("%f \t %f\n", b,m);
	} while( fabs(b-a) >= acc );

	return a;
}


int 
plotting (float x)
{
	for (float i=0.;  i <=10.; i=i+0.001)
		printf ("%f \t %f \n", i, func(i,x));
	return 0;
}

int 
main()
{
	float roots[50];
	int   r_index = 0; 

	float bracket = 0.0001;

	for (float i = bracket; i < 10.0; i+=bracket) {
		roots[r_index]=sect(simpson,i,i+bracket);
		if ( roots[r_index] != -1 ) {
			printf("%f \n",roots[r_index]);
		}
	}
		
	return 0;
}
