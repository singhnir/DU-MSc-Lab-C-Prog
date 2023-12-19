#include <stdio.h>
#include <math.h>

float acc = 0.00001;

// float
// func (float x, float y)
// {
// 	return 0;
// }



float 
trapez (float func(float x, float y), float a, float b, float n, float dummy)
{
	float h;
	float sum=0;

	// step size
	h = (b-a)/(float)n;

	for (int i = 1; i<n; i++)
		sum+=func(a+(i*h),dummy);

	return ( h/2.0*(func(a,dummy)+func(b,dummy)+2*sum) );
}


float 
simpson (float func(float x, float y), float a, float b, float n, float dummy)
{
	float h;
	float sum=0;

	// finding step size with number of brackets = n 
	h = (b-a)/(float)n;

	for (int i = 1; i<n; i++) {
		if (i%2 == 0)
			sum+=2*func(a+(i*h),dummy);
		else
			sum+=4*func(a+(i*h),dummy);
	}

	return ( h/3.0*(func(a,dummy)+func(b,dummy)+sum) );
}

float
t_integral(float x, float a)
{
	return ( 4/(float)( 1 - pow(sin(a/2.0),2) * pow(sin(x),2) ) );
}

float 
t_approx(float a)
{
	return ( 2*M_PI*( 1 + pow( (a/4.0),2 ) )) ;
}

FILE *p = NULL; 

int
main()
{
	p = fopen("ex2.txt","w");
	float a=0.0;
	float b=M_PI_2;
	float y1,y2,y3;
	fprintf(p,"A \t simpson_integration \t Approximation \t error\n");
	for (float A = 0.1; A < M_PI; A=A+0.1) {
		y1 = simpson(t_integral,a,b, 500, A);
		y2 = t_approx(A);
		y3 = (y1-y2)/(y1) * 100;

		fprintf(p,"%f \t %f \t %f \t %f \n", A, y1, y2, y3) ;
	}

}
