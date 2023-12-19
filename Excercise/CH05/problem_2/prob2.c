#include <stdio.h>
#include <math.h>

// define parameters of system
double a = 0.1;      // alpha = 0.1, 0.5, 1.0
double k = 1.0;
double m = 1.0;

// global 
// double y_ini = a;  // global variables cannot be dynamic  
double x_ini = 0.0;  //  y' = x
double t_ini = 0.0;
double dt    = 0.01;


// return multiple step_size values
typedef struct 
{
	double x;
	double y;
} step;

/*
 * given the 2nd order equation
 *         y'' + sin(y) = 0
 * decompose as
 *         y' = x 
 *         x' = -sin(y) 
 */

// y'
double 
func1(double x, double y, double t) 
{
	return ( x ) ;
}

// x'
double 
func2(double x, double y, double t) 
{
	return( -sin(y) );
}


step 
RK4_step(double x, double y, double t, double dt)
{
	step step_size;

	double slope_x, m1, m2, m3, m4;
	double slope_y, k1, k2, k3, k4;

	k1    = func1(x, y, t);  // y'
	m1    = func2(x, y, t); //  x'  

	k2    = func1(x + (m1*dt/2.0) , y + (k1*dt/2.0), t + dt/2.0 ); 
	m2    = func2(x + (m1*dt/2.0) , y + (k1*dt/2.0), t + dt/2.0 ); 

	k3    = func1(x + (m2*dt/2.0) , y + (k2*dt/2.0), t + dt/2.0 ); 
	m3    = func2(x + (m2*dt/2.0) , y + (k2*dt/2.0), t + dt/2.0 ); 

	k4    = func1(x + (m3*dt), y + (k3*dt) , t + dt);
	m4    = func2(x + (m3*dt), y + (k3*dt) , t + dt); 


        // in the form a_i * k_i  
	slope_y = 1/(double)6.0 * ( 1*k1 + 2*k2 + 2*k3 + 1*k4 ) ;
	slope_x = 1/(double)6.0 * ( 1*m1 + 2*m2 + 2*m3 + 1*m4 ) ;

	step_size.y = slope_y * dt;	
	step_size.x = slope_x * dt;	

   	return ( step_size ); 
}

double
actual ( double t )
{
return ( a * cos( t ) ) ;
}

int 
main ()
{
	double t; 
	double y_RK4   = a;
	double x_RK4   = x_ini;
	step step_size;

	double required_interval= dt;
	double no_of_terms = (required_interval / (float) dt);

        // no of terms in the required interval depending on dt
       //  and making sure it's a integer

	int n =1; // starting off with 1st term
	printf ("no of terms %f \n", no_of_terms);

	printf ("%8s \t %8s \t %8s \n","time","actual", "RK4"); 

	for ( t = t_ini ; t <= 8*M_PI; t+=dt ) {
		step_size = RK4_step (x_RK4, y_RK4, t, dt);
		x_RK4     = x_RK4   + step_size.x ;
		y_RK4     = y_RK4   + step_size.y ;

	 // print only if it's required interval length
        //  and x greater than 1

	if ( fmodf(n,no_of_terms) == 0.0 && t+dt >= 0  ) { 
		printf ("%f \t %f \t %f \n", t+dt, actual(t+dt), y_RK4 );
	}

		n++;
	}

}
	
