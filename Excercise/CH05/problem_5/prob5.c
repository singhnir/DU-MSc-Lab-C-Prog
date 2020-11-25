// Lorenz equations
#include<stdio.h>
#include<math.h>

float dx(float t,float x,float y,float z)
{
	return -10*(x-y);
}
float dy(float t,float x,float y,float z)
{
	// change value of alpha here
	return 100*x-x*z-y;
}
float dz(float t,float x,float y,float z)
{
	return x*y-(8*z)/3;
}

int main()
{
	FILE*fp=NULL;
    fp=fopen("prob5.txt","w");
    fprintf(fp,"#t\tx\ty\tz\n");

    float x,y,z,t,h=0.01;
	float k1,k2,k3,k4,m1,m2,m3,m4,n1,n2,n3,n4;

	// giving initial conditions
	t=0,x=1,y=2,z=3;
	do
	{
		fprintf(fp,"%f\t%f\t%f\t%f\n",t,x,y,z);
		k1=h*dx(t,x,y,z);
		m1=h*dy(t,x,y,z);
		n1=h*dz(t,x,y,z);

		k2=h*dx(t+h/2,x+k1/2,y+m1/2,z+n1/2);
		m2=h*dy(t+h/2,x+k1/2,y+m1/2,z+n1/2);
		n2=h*dz(t+h/2,x+k1/2,y+m1/2,z+n1/2);

		k3=h*dx(t+h/2,x+k2/2,y+m2/2,z+n2/2);
		m3=h*dy(t+h/2,x+k2/2,y+m2/2,z+n2/2);
		n3=h*dz(t+h/2,x+k2/2,y+m2/2,z+n2/2);

		k4=h*dx(t+h,x+k3,y+m3,z+n3);
		m4=h*dy(t+h,x+k3,y+m3,z+n3);
		n4=h*dz(t+h,x+k3,y+m3,z+n3);

		x=x+(k1+2*k2+2*k3+k4)/6;
		y=y+(m1+2*m2+2*m3+m4)/6;
		z=z+(n1+2*n2+2*n3+n4)/6;
		t=t+h;

	} while(t<=10);
}