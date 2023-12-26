#include <stdio.h>
#include <math.h>

FILE *p = NULL; 
float acc = 0.00001;

/*
 *  Mind map
 *  --------
 *   mathematical function
 *     -> integrator
 *      -> plot for integrator
 */

// integration constants
float t0          = 0;
float t1          = M_PI/2.0;
float integ_steps = 500;

float
func(float x, float A)
{
	return ( 4/(float)( 1 - pow(sin(A/2.0),2) * pow(sin(x),2) ) );
}

float 
func_approx(float A)
{
	return ( 2*M_PI*( 1 + pow((A/4.0),2)) ) ;
}


float 
trapez (float A)
{
	float a = t0;
	float b = t1;
	float n = integ_steps;

	float h;
	float sum=0;

	// step size
	h = (b-a)/(float)n;

	for (int i = 1; i<n; i++)
		sum+=2*func(a+(i*h),A);

	return ( h/2.0*(func(a,A)+func(b,A)+sum) );
}


float 
simpson (float A)
{
	float a = t0;
	float b = t1;
	float n = integ_steps;

	float h;
	float sum=0;

	// finding step size with number of brackets = n 
	h = (b-a)/(float)(n);

	for (int i = 1; i<n; i++) {
		if (i%2 == 0)
			sum+=2*func(a+(i*h),A);
		else
			sum+=4*func(a+(i*h),A);
	}

	return ( h/3.0*(func(a,A)+func(b,A)+sum) );
}



int
main()
{
	p = fopen("ex2.txt","w");

	float y1,y2,y3;

	fprintf(p,"#A \t simpson_integration \t Approximation \t error\n");
	for (float A = 0.1; A < M_PI; A=A+0.1) {

		y1 = simpson(A);
		y2 = func_approx(A);
		y3 = fabs(y1-y2)/(y1) * 100; // percentage error

		fprintf(p,"%f \t %f \t %f \t %f \n", A, y1, y2, y3) ;
	}

	fclose(p);

}
