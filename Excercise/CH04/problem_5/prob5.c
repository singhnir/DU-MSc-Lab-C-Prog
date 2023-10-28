#include <math.h>
#include <stdio.h>

// incase if storing in file is needed otherwise '>' to redirect
FILE *p;
char filename[50];

// Global variable
int dummy      = 1;
float accuracy = 0.00001;

/* 
 * define your function 
 * if implict define 2 parameters ie func(x,y) and start fixing x
 * iterate over y
 * else func(x) 
 * 
 *       ----legend for variables----
 *       a -  starting value of interval
 *       b -  ending   value of interval
 *       n -  to denote no of iteration in each method
 *       m -  midpoint in bisection, weighted average in sectant
 *       h -  small addition parameter for newton_ralph
 */

float 
func(float dummy, float x)
{
	float u0=1,u;
	float u1=2*x;   
	int order = 2;
	do {
		u = 2*x*u1 - u0; // u2, u3, u4
		u0 = u1;
		u1 = u;
		order++ ; // 3,4,5
	} while ( order <= 4 );
	return (u);
	
}

/*
 * 1st derivate of func for newton ralph
 */

float 
func_deri(float x, float y)
{
	return (3*pow(y,2) + x);
}

///
// secant method
///
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
	} while ( fabs(a-b) > accuracy );

	printf("%f \t %f", x,a); 
	printf("\tin %f iternations\n", n);
	return 0;
}

///
// bisection method
///
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
	} while ( fabs(b-a) > accuracy );

	printf("%f \t %f", x,a); 
	printf("\tin %f iternations\n", n);

	return 0;
}


///
// newton - raplhson
///
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


/*
 * for plotting use this function and redirect using '>'
 * eg. gcc -Wall *.c -lm && ./a.out > sample.txt
 * then gnuplot,
 * > plot "sample.txt" using 1:2 with lines
 */
void 
func_plot() 
{
	for (float j = -2.0; j<=2.0; j+=0.0001)  
            	printf("%f \t %f\n", j, func(dummy,j)); 
}


int 
main()
{
	for (float j = -2.0; j<=2.0; j+=0.001)  {
		bisec (dummy, j, j+0.001);
		sect (dummy, j, j+0.001);
		// no possiblity of newt-raplh cause of derivative function
	}
}

