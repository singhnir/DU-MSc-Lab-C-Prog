#include <math.h>
#include <stdio.h>

// incase if storing in file is needed otherwise '>' to redirect
FILE *p;
char filename[50];

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
func(float x, float y)
{
	return (pow(x,3) + pow(y,3) + x*y + 1) ;
}

/*
 * 1st derivate of func for newton ralph
 */

float 
func_deri(float x, float y)
{
	return (3*pow(y,2) + x);
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

/*
# for (float i = -1.5; i<=1.5; i+=0.1){
#  	sprintf(filename,"t%d.txt", n) ;
#  	p = fopen(filename, "w");
#  	for (float j = -2.0; j<=2.0; j+=0.1)  {
#      	bisec
# 		fprintf(p, "%f \t %f\n", j, func(i,j));
#  	}
#  	fclose(p);
# 	n++;
# }
*/

for (float i = -1.5 ; i <= 1.5; i+=0.1) {
	for (float j = -2.0; j<=2.0; j+=0.1)  {
		bisec (i, j, j+0.1);
		newt n(i, j, j+0.1);
		sec   (i, j, j+0.1);
	}
}

}
