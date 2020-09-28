// plotting the spherical Bessel function for n=0,1,2,3,4,5
#include<stdio.h>
#include<math.h>
 
double J0(double z) //defining the function Jo(z)
{
    return sin(z)/z;
}
double J1(double z) //defining the function J1(z)
{
    return sin(z)/(z*z)-cos(z)/z;
}
double Jn(double z,int n) //defining the function Jn(z)
{
    double bessel;
    if (n==0)
    {
        bessel = J0(z);
    }
    else if(n==1)
    {
        bessel = J1(z);
    }
    else
    {
        //using recurrence relation
        bessel = (2*n-1)*Jn(z,n-1)/z-Jn(z,n-2);
    }
    return bessel;
}
//main function will call above functions
int main()
{
    double z;
    int n;
    //FILE*fp: declaring a pointer of type file
    //NULL: to make sure the file was successfully opened
    FILE*fp=NULL;
    fp=fopen("bessel.txt","w");
    //Loop to calculate and store data-points
    for(z=0.01;z<=5;z=z+0.01)
    {
        fprintf(fp,"%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",z,Jn(z,0),Jn(z,1),Jn(z,2),Jn(z,3),Jn(z,4),Jn(z,5));
    }
    //close the file handle
    fclose(fp);
}