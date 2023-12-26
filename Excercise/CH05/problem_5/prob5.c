#include <stdio.h>
#include <math.h>

// define parameters of system
double alpha = 50.0;

// global 
// it's better to define initial conditions in main
// because usually a single plot should show multiple initial conditions  

double y_ini = 0.0;  // global variables cannot be dynamic  
double x_ini = 0.1;  // 
double z_ini = 1.0;  //  

double t_ini = 0.0;
double dt    = 0.01;


// return multiple step_size values
typedef struct 
{
	double x;
	double y;
	double z;
}step;

/*
 * given the 2nd order equation
 *        f1 y'' + f2 y' + f3 y = f4 
 * decompose as
 *         y' = x 
 *         x' = ( f4(t) - f3(t) y - f2 x ) / f1
 */

// y'
double 
func1(double x, double y, double z, double t)
{
	return ( alpha*x - x*z - y ) ;
}

// x'
double 
func2(double x, double y, double z, double t) 
{
	return ( -10*(x-y) ) ;
}

// z'
double 
func3(double x, double y, double z, double t)
{
	return ( (x*y) - (8.0*z)/3.0 ) ;
}



step 
RK4_step(double x, double y, double z, double t, double dt)
{
	step step_size;

	double slope_y, k1, k2, k3, k4;   // func1
	double slope_x, m1, m2, m3, m4;  //  func2
	double slope_z, l1, l2, l3, l4; //   func3

	k1    = func1(x, y, z, t);   // y'
	m1    = func2(x, y, z, t);  //  x'  
	l1    = func3(x, y, z, t); //   z'  

	k2    = func1(x + (m1*dt/2.0) , y + (k1*dt/2.0), z + (l1*dt/2.0), t + dt/2.0 ); 
	m2    = func2(x + (m1*dt/2.0) , y + (k1*dt/2.0), z + (l1*dt/2.0), t + dt/2.0 ); 
	l2    = func3(x + (m1*dt/2.0) , y + (k1*dt/2.0), z + (l1*dt/2.0), t + dt/2.0 ); 

	k3    = func1(x + (m2*dt/2.0) , y + (k2*dt/2.0), z + (l2*dt/2.0), t + dt/2.0 ); 
	m3    = func2(x + (m2*dt/2.0) , y + (k2*dt/2.0), z + (l2*dt/2.0), t + dt/2.0 ); 
	l3    = func3(x + (m2*dt/2.0) , y + (k2*dt/2.0), z + (l2*dt/2.0), t + dt/2.0 ); 

	k4    = func1(x + (m3*dt), y + (k3*dt), z + (l3*dt), t + dt);
	m4    = func2(x + (m3*dt), y + (k3*dt), z + (l3*dt), t + dt); 
	l4    = func3(x + (m3*dt), y + (k3*dt), z + (l3*dt), t + dt); 


        // in the form a_i * k_i  
	slope_y = 1/(double)6.0 * ( 1*k1 + 2*k2 + 2*k3 + 1*k4 ) ;
	slope_x = 1/(double)6.0 * ( 1*m1 + 2*m2 + 2*m3 + 1*m4 ) ;
	slope_z = 1/(double)6.0 * ( 1*l1 + 2*l2 + 2*l3 + 1*l4 ) ;

	step_size.y = slope_y * dt;	
	step_size.x = slope_x * dt;	
	step_size.z = slope_z * dt;	

   	return ( step_size ); 
}

int 
main ()
{
	double t; 
	double x_RK4 = x_ini; 
	double y_RK4 = y_ini;   
	double z_RK4 = z_ini;   

	step step_size;

	printf ("%8s \t %8s \t %8s \t %8s \n","time", "x", "y", "z"); 

		for ( t = t_ini ; t <= 20.0; t+=dt ) {

		step_size = RK4_step (x_RK4, y_RK4, z_RK4, t, dt);
		x_RK4     = x_RK4   + step_size.x ;
		y_RK4     = y_RK4   + step_size.y ;
		z_RK4     = z_RK4   + step_size.z ;

		printf ("%f \t %f \t %f \t %f \n", t+dt, x_RK4, y_RK4, z_RK4 );

		}
		
}
