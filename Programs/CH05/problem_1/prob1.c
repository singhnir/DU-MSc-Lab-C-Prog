#include <stdio.h>
#include <math.h>

/*
 *  A great place to start adventure with ode solvers
 *  https://github.com/apf99/SDOF-Simulator/blob/master/sdof_simulator2.py
 *  precious 30mins - https://www.youtube.com/watch?v=-WhS5iuvGr0 (aliter: https://yewtu.be/watch?v=-WhS5iuvGr0)
 *
 *  This piece of code and notes are implemention of above in C
 *
 *  y_i+1         = y_i + step_size
 *  step_size     = del_t * (slope) 
 *  finding 'good' estimate of slope defines algorithm
 *  base is taylor series.
 *  slope is in form a_i*k_i  a_i's are weights and they sum to 1
 *  k_i's are slope calculated with respect to initial conditions 
 */

/*
--------------------------------------------------------------------------
naive estimate of slope is simply the f'(x,y) 1st term in taylor expansion
what's better?

Euler - Method
--------------

slope = 1 * k1
k1    = f'(y,t) // calculated at point y

step_size = (slope)*dt = k1*dt


RK2 - Method 1
--------------


k_1   = f'(y,t)
k_2   = f'(y + k1*(del_t/2), t+(del_t/2) ) // 1/2 step in dt for k2 slope

now average these 
slope = 1/2 (1* k_1 + 1 * k_2)

step_size = del_t * slope


RK2 - Method 2
--------------

k1    = f'(y,t)
k2    = f'(y+k1*del_t, t+del_t) // whole step in dt for k2 slope

slope = 1/1 (1*k_2)

step_size = del_t * slope

RK4 - weighted average of 4 steps 
---------------------------------

k1    = f'(y,t)
k2    = f'(y+k1*(del_t/2),t+del_t/2)
k3    = f'(y+k2*(del_t/2),t+del_t/2)
k4    = f'(y+k3*(del_t)  ,t+del_t)

slope = 1/6 ( 1*k1 + 2*k2 + 2*k3 + 1*k4 ) 

rk_4_step_size = del_t * slope


What's the criteria to check accuracy in physical system?

on the conservation of energy regime, try calculating E for  each
numerically intergrated points and compare each method's E values

---------------------------------------------------------------------
*/


double y_ini = 1.0;
double t_ini = 0.0;
double dt    = 0.005;


double 
func(double x, double t) 
{
	return( x*pow(t,2) + pow(t,2) * sin(pow(t,3)) ) ;
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


double 
RK4_step(double x, double t, double dt)
{
	double slope, k1, k2, k3, k4;

	k1    = func(x,t);
        //  half a step of dt wrt  to previous slope k1
	k2    = func(x + (k1*dt/(double)2.0) , t + (dt/(double)2.0) ); 
        //  half a step of dt wrt  to previous slope k2
	k3    = func(x + (k2*dt/(double)2.0) , t + dt/(double)2.0 ); 
        //  full   step of dt wrt  k3 
	k4    = func(x + (k3*dt) , t + dt); 

        // in the form a_i * k_i  
	slope = 1/(double)6.0 * ( 1*k1 + 2*k2 + 2*k3 + 1*k4 ) ;

   	return ( slope * dt ) ; 
}

double
actual ( double t)
{
return (-0.3* cos(pow(t,3)) - 0.1*sin(pow(t,3)) + 1.3*exp(pow(t,3)/(float)3));
}

int 
main ()
{
	double t; 
	double y_euler = y_ini;
	double y_RK2   = y_ini;
	double y_RK4   = y_ini;

	printf ("time \t actual \t RK4 \t RK2 \t Euler \n");
	for ( t = t_ini ; t <= 1.0; t+=dt ) {

		y_RK4   = y_RK4   + RK4_step  (y_RK4   , t, dt);
		y_RK2   = y_RK2   + RK2_step  (y_RK2   , t, dt);
		y_euler = y_euler + euler_step(y_euler , t, dt);

	// print only if t is a multiple of something	

	printf ("%f \t %f \t %f \t %f \t %f \n", t+dt, actual(t+dt), y_RK4, y_RK2, y_euler);
	}

}
	
