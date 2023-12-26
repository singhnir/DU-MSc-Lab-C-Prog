#include <stdio.h>
#include <math.h>

// global 

double y_ini = 1.0;
double x_ini = 0.0;
double dx    = 0.01;

typedef struct 
{
	double x;
	double y;
}step;

double 
func(double y, double x) 
{
	return( y + x );
}

double 
euler_step(double x, double t, double dt)
{
	double slope, k1;

	k1    = func(x,t);

	slope = 1*k1;          // in the form a_i * k_i  
	return ( slope*dt );  // returning step_size

}

double 
RK2_step(double x, double t, double dt)
{
	double slope, k1, k2;

	k1    = func(x,t);
        // half a step of dt but calculated with k1 as slope
	k2    = func(x + (k1*dt/2.0) , t + dt/2.0 );

	slope = 1/2.0 * (1* k1 + 1*k2);  // in the form a_i * k_i  
	return ( slope*dt );            //  returning step_size
}


step 
RK4_step(double x, double t, double dt)
{
	step step_size;
	double  slope, k1, k2, k3, k4;
	
	k1    = func(x,t);
	k2    = func(x + (k1*dt/2.0) , t + dt/2.0 ); 
	k3    = func(x + (k2*dt/2.0) , t + dt/2.0 ); 
	k4    = func(x + (k3*dt) , t + dt); 

        // in the form a_i * k_i  
	slope  = 1/(double)6.0 * ( 1*k1 + 2*k2 + 2*k3 + 1*k4 );

	step_size.x = slope*dt;

   	return ( step_size ) ; 
}

double
actual ( double x)
{
return ( 2*exp(x) - x - 1.0 ) ;
}

int 
main ()
{
	double x; 
	double y_euler = y_ini;
	double y_RK2   = y_ini;
	double y_RK4   = y_ini;

	double required_interval=0.10;
	double no_of_terms = ceil(required_interval / (float) dx);

	 // no of terms in the required interval depending on dx
	//  and making sure it's a integer

	int n =1; // starting off with 1st term
	printf ("no of terms %f \n", no_of_terms);

	printf ("time \t actual \t RK4 \t RK2 \t Euler \n");

	for ( x = x_ini ; x <= 5.0; x+=dx ) {

		y_RK4   = y_RK4   + RK4_step  (y_RK4   , x, dx).x;
		y_RK2   = y_RK2   + RK2_step  (y_RK2   , x, dx);
		y_euler = y_euler + euler_step(y_euler , x, dx);

     	 // print only if it's required interval length
        //  and x greater than 1

	if ( fmodf(n,no_of_terms) == 0.0 && x+dx >= 1  ) { 
	    printf ("%f \t %f \t %f \t %f \t %f \n",  x+dx, actual(x+dx), y_RK4, y_RK2, y_euler);
	}

	n++;
	}

}
	
/*
 *  Learnt lesson math.h's fmodf is unreliable for decimal floats 
 *  make sure to use that only for integer values 
 *
 *  common RK4 algo seems accurate to 6 decimal place even at dx of 0.01 
 */
