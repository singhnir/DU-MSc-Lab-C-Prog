#include <stdio.h>
#include <math.h>

// define parameters of system
double f1 = 1.0;
double f2 = 1.0;

double 
f3 (double t)  
{
	return ( 4*t ) ;
}

double 
f4 ( double t ) 
{
	int i = 0;

	double term = 1;
	double sum  = term;

	do {
		term*=-pow(t,2)/(double)(2i+3)*(2i+2);
                sum +=term;
		i++;
	} while ( i <= 10 ) ;
	return sum;
}

// global 
// it's better to define initial conditions in main
// because usually a single plot should show multiple initial conditions  

double y_ini = 0.0;   // global variables cannot be dynamic  
double x_ini = 1.0;  //  y' = x

double t_ini = 0.0;
double dt    = 0.01;


// return multiple step_size values
typedef struct 
{
	double x;
	double y;
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
func1(double x, double y, double t) 
{
	return ( x ); 
}

// x'
double 
func2(double x, double y, double t) 
{
	return( ( f4(t) - f3(t)*y - f2*x ) / f1 );
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
	double x_RK4 = x_ini; 
	double y_RK4 = y_ini;   

	step step_size;

	printf ("%8s \t %8s \n","time", "y"); 

		for ( t = t_ini ; t <= 1; t+=dt ) {

		step_size = RK4_step (x_RK4, y_RK4, t, dt);
		x_RK4     = x_RK4   + step_size.x ;
		y_RK4     = y_RK4   + step_size.y ;

		printf ("%f \t %f \n", t+dt, y_RK4 );

		}
		
}
