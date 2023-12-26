#include <stdio.h>
#include <math.h>

// define parameters of system
double r1 = 0.25;      
double r2 = 0.01;
double r3 = 1.0;
double r4 = 0.01;

// global 
// it's better to define initial conditions in main
// because usually a single plot should show multiple initial conditions  

// double y_ini = a;  // global variables cannot be dynamic  
double x_ini = 100.0;  //  y' = x
double t_ini = 0.0;
double dt    = 0.01;


// return multiple step_size values
typedef struct 
{
	double x;
	double y;
} step;

/*
 * given the 2 1st order equation
 *         y' = r3y + r4xy 
 *         x' = r1x - r2xy
 */

// y'
double 
func1(double x, double y, double t) 
{
	return ( -r3*y + r4*x*y ) ;
}

// x'
double 
func2(double x, double y, double t) 
{
	return( r1*x - r2*x*y );
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

int 
main ()
{
	double t; 
	double x_RK4, y_RK4;   

	step step_size;
	int n=1;

        // no of terms in the required interval depending on dt
       //  and making sure it's a integer

	printf ("%8s \t %8s \t %8s \n","time","x", "y"); 

	for ( double y_ini = 5.0; y_ini <=25.0; y_ini+=5.0) {

		y_RK4 = y_ini;
		x_RK4 = x_ini;
        
		for ( t = t_ini ; t <= 20; t+=dt ) {

		step_size = RK4_step (x_RK4, y_RK4, t, dt);
		x_RK4     = x_RK4   + step_size.x ;
		y_RK4     = y_RK4   + step_size.y ;

		printf ("%f \t %f \t %f \n", t+dt, x_RK4, y_RK4 );

		}
		
	}
}
