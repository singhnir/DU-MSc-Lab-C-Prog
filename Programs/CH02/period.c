#include <stdio.h>
#include <math.h>
#include <complex.h>
FILE *p=NULL;
float period = 2.0;

void
triangle()
{
	float t ;
	for ( float i = 0.0 ; i < 20. ; i+=0.1 ) {
		t = fmodf(i,period);
		if (t<=1.0)
		fprintf(p,"%f  %f\n", i, t );
		else
		fprintf(p,"%f  %f\n", i, 2.0-t );
	}

	fprintf(p,"\n \n");
}

void
circle()
{
	float complex t;
	float r= 0.3;
	for (float i = 1.0; i< 20; i+=2.0) {
	
	for ( float theta = 0; theta < 2*M_PI; theta+=0.1 ) {
		// t = 0.1*cexp(I*theta);
		fprintf(p,"%f   %f \n", i+r*cos(theta), 1+r*sin(theta) ); 
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
fclose(p);
}
