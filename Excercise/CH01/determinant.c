// program to determine the roots of a quadratic equation.
#include<stdio.h>
#include <math.h>
int main()
{
    int a,b,c,det;
    float x1,x2;
    printf("Enter the value of a,b and c: ");
    scanf("%d%d%d",&a,&b,&c);
    det=b*b-4*a*c;
    printf("determinant of given values:%d\n",det);
    if (det>0)
    {
    	x1=(-b+sqrt(det))/(2*a);
    	x2=(-b-sqrt(det))/(2*a);
    	printf("The roots of quadratic equation are:\n");
    	printf("x1=%0.2f\tx2=%0.2f\n",x1,x2);
    }
    else if (det==0)
    {
    	x1=(-b)/(2*a);
    	x2=(-b)/(2*a);
    	printf("Both the roots of quadratic equation are equal which are:\n");
    	printf("x1=%0.2f\tx2=%0.2f\n",x1,x2);
    }
    else if (det<0)
    {
    	printf("\nThe roots of such quadratic equation are imaginary.\n");
    }
}
