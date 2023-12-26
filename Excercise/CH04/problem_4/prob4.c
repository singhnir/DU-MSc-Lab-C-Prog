#include <math.h>
#include <stdio.h>

// incase if storing in file is needed otherwise '>' to redirect
FILE *p;
char filename[50];

// global variables
float epsilon = 0.8;
float omega   = 1.0;
float a_g     = 2.0;

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
func(float t, float psi)
{
	return (psi - epsilon* sin(psi) - omega*t);
}

/*
 * 1st derivate of func for newton ralph
 */

float 
func_deri(float t, float psi)
{
	return (1 - epsilon*cos(psi));
}

float
func_plot(float psi) 
{
	float r, cos_t,sin_t;
	r     = a_g*(1 - epsilon*cos(psi)) ;
	cos_t =	(cos(psi) - epsilon) / (float) (1 - epsilon*cos(psi));
	sin_t = sqrt ( 1 - pow(cos_t,2) ) ;

	printf ("%f \t  %f \n", r*cos_t, r*sin_t);
	/* unsure why to do -y? to symmetrize */
	printf ("%f \t  %f \n", r*cos_t, -r*sin_t);

	return 0;

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

	printf("%f \t %f", x,a); 
	printf("\tin %f iternations\n", n);
	// func_plot(a);

	return 0;
}


int 
main()
{

/*
 int num=1; // for file number t_{no}.txt
 for (float i = 0; i<=2*M_PI/(float)omega; i+=0.1){
  	sprintf(filename,"t_%d.txt", num) ;
  	p = fopen(filename, "w");
  	for (float j = -8.0*M_PI; j<=8.0*M_PI; j+=0.1)  {
 		fprintf(p, "%f \t %f\n", j, func(i,j));
  	}
  	fclose(p);
 	num++;
 }
*/

 for (float i = 0; i<=2*M_PI/(float)omega; i+=0.1){
  	for (float j = -100.0*M_PI; j<=100.0*M_PI; j+=0.01)  {
 		bisec (i, j, j+0.01);
 		sect  (i, j, j+0.01);
 		newt  (i, j, j+0.01);
		 
 	}
 }

}
