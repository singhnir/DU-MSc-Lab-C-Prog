#include <stdio.h>
#include <math.h>

float acc = 0.00001;

float
bisec (float func(float x, float y), float a, float b)
{
	int iteration=0;
	float dummy =0;
	float m;

	// initial check
	if (func(a,dummy) * func(b,dummy) >= 0)
		return 0;

	do {
		m = (a+b)/(2.0);
		if (func(a,dummy)*func(m,dummy) <= 0)
			b=m;
		else
			a=m;
		iteration++;
	} while( fabs(b-a) >= acc );

	printf("done in %d", iteration);
	return b;
}

float
sect (float func(float x, float y), float a, float b)
{
	int iteration=0;
	float dummy =0;
	float m;

	// initial check
	if (func(a,dummy) * func(b,dummy) >= 0)
		return 0;

	do {
		m = (func(b,dummy)*a - func(a,dummy)*b) /  (float) func(b,dummy) - func(a,dummy);
		a = b;
		b = m;
		iteration++;
	} while( fabs(b-a) >= acc );

	printf("done in %d", iteration);
	return b;
}

float 
trapez (float func(float x, float y), float a, float b, float n)
{
	float h;
	float sum=0;
	float dummy=0;	

	// step size
	h = (b-a)/(float)n;

	for (int i = 1; i<n; i++)
		sum+=func(a+(i*h),dummy);

	return ( h/2.0*(func(a,dummy)+func(b,dummy)+2*sum) );
}


float 
simpson (float func(float x, float y), float a, float b, float n)
{
	float h;
	float sum=0;
	float dummy=0;	

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

/* 
 * in case  accuracy  is  being  compared  between different algorithms
 * no of iteration is to be found rather than explicit value defined by 
 * programmer 
 */

float
integ ( float algo(float func(float x, float y), float a, float b, float n), float a, float b, float func(float x, float y))
{
	int iter = 2;
	float initial, final;
	do {
		initial = final;		
		final   = algo(func, a,b,iter);
		iter+=2; // better suit both the rules
		} while (fabs(initial-final)>=acc);

	printf("calulated in %d brackets", iter);
	return final;
}



