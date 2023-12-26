#include <math.h>
#include <stdio.h>

// incase if storing in file is needed otherwise '>' to redirect
FILE *p;
char filename[50];


// Global Variables - approx invertal be generous ;)
float a = 1.5;
float b = 10.0;

/* 
 * define your function 
 * if implict define 2 parameters ie func(x,y) and start fixing x
 * iterate over y
 *
 * else func(dummy, x)  and choose dummy = (any_number)
 * iterate over x 
 * 
 *       ----legend for variables----
 *       a -  starting value of interval
 *       b -  ending   value of interval
 *       n -  to denote no of iteration in each method
 *       m -  midpoint in bisection, weighted average in sectant
 *       h -  small addition parameter for newton_ralph
 */

/* define function for which root is being found */
float 
func(float dummy, float x)
{
	return (exp(a*x)-b*x*x);
}

/* 1st derivate of func for newton ralph */
float 
func_deri(float dummy, float x)
{
	return (a*exp(a*x) - 2*b*x);
}

float 
sect(float x,float a, float b)
{
	if ( func(x,a) * func(x,b) > 0 )	 
		return 0;
	float m, n=0;
	do {
		m = (func(x,b)*a - func(x,a)*b) / (float) (func(x,b) - func(x,a));
		a = b;
		b = m;
		n ++ ;
	//	printf("%f \t %f\n", x,a); 
	} while ( fabs(a-b) > 0.00001 ); 

	printf("%f \t %f", x,a); 
	printf("\tin %f iternations\n", n);
	return 0;
}

float 
bisec(float x, float a, float b)
{
	if ( func(x,a) * func(x,b) > 0 )	 
		return 0;

	float m, n=0;
	do {
		m = (a + b) / (float) 2;
		if (func(x,m) * func(x,a) <= 0)
			b = m;
		else
			a = m;
		n ++ ;
//		printf("%f \t %f\n", func(x,a), func(x,b)); 
	} while ( fabs(b-a) > 0.00001 ); 

	printf("%f \t %f", x,a); 
	printf("\tin %f iternations\n", n);

	return 0;
}


float
newt (float x, float a, float b)
{
	// h is small addition in newton_raplh
	float h,n=0;
	if ( func(x,a) * func(x,b) > 0 )	 
		return 0;
	do {
	    	 h = -( func(x,a) / (float) func_deri(x,a));       
		 a = a + h;
//		printf ("%f \t %f\n", a, func(x,a) ) ;
		n++;
        } while ( fabs(h/a) > 0.00001 ) ;

	printf ("%f \t %f", x, a );
	printf("\tin %f iternations\n", n);
	return 0;
}


int 
main()
{
	int dummy=1;
  //	for (float j = -2.0; j<=2.0; j+=0.0001)  {
  //      	printf("%f \t %f\n", j, func(dummy,j));
  //	}
  ///

	for (float j = -1.0; j<=1.0; j+=0.001)  {
		bisec (dummy, j, j+0.001);
		sect  (dummy, j, j+0.001);
		newt  (dummy, j, j+0.001);

	}
}


