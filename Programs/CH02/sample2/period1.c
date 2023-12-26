#include <stdio.h>
#include <math.h>
#include <complex.h>

FILE *p=NULL;
float period = 4.0;

void
triangle()
{
	float t ;
	for ( float i = 0.0 ; i < 20. ; i+=0.1 ) {
		t = fmodf(i,period);
		if (t<=2.0){
			if (t<=1.0)
				fprintf(p,"%f  %f\n", i, t );
			else 
				fprintf(p,"%f  %f\n", i, 2.0-t );
		}
		else 
			fprintf(p,"%f  0.0\n", i);
	}

	fprintf(p,"\n \n"); // for using gnuplot's index 
}

void
circle()
{
	float complex t;
	float r= 1.0;
	for (float i = 3.0; i< 20; i+=period) {
		for ( float theta = 0; theta < M_PI; theta+=0.01 ) {
			fprintf(p,"%f   %f \n", i+r*cos(theta), r*sin(theta) ); 
			
			/*
			 * // Another way using <complex.h> 
			 * // ------------------------------------
			 * t = r*cexp(I*theta);
			 * fprintf(p,"%f   %f \n", i+creal(t), cimag(t) ); 
			 */
		}
        }
}

int 
main ()
{ 
p = fopen("period.txt","w");
triangle();
circle();
return 0;
}
