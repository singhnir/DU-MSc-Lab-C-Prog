// plotting the square modulus of the orbital wave function for diff values of l & m
// this program will generate four datasheets for each function
#include<stdio.h>
#include<math.h>

float theta30(float x)  //defining the function for l=3 m= 0
{
 float l3m0=3.0*sqrt(14.0)/4.0*(5.0/3.0*pow(cos(x),3)-cos(x));
 return l3m0;
}
float theta31(float x)  //defining the function for l=3 m= ±1
{
 float l3m1=(sqrt(42))/(8)*sin(x)*(5*pow(cos(x),2)-1);
 return l3m1;
}
float theta32(float x)  //defining the function for l=3 m= ±2
{
 float l3m2=sqrt(105)/4*pow(sin(x),2)*cos(x);
 return l3m2;
}
float theta33(float x)  //defining the function for l=3 m= ±3
{
 float l3m3=(sqrt(70))/(8)*(pow(sin(x),3));
 return l3m3;
}
//main function will call above functions
int main()
{
 float theta;
 float x1,x2,x3,x4,y1,y2,y3,y4;

 FILE*fp1=NULL;
 FILE*fp2=NULL;
 FILE*fp3=NULL;
 FILE*fp4=NULL;
 fp1=fopen("l3m0.txt","w");  // for l=3 m= 0
 fp2=fopen("l3m1.txt","w");  // for l=3 m= ±1
 fp3=fopen("l3m2.txt","w");  // for l=3 m= ±2
 fp4=fopen("l3m3.txt","w");  // for l=3 m= ±3

 //Loop to calculate and store data-points
 for(theta=0;theta<=2*M_PI;theta=theta+0.01)
 {
   // for l=3 m= 0
   x1=theta30(theta)*theta30(theta)*cos(theta);
   y1=theta30(theta)*theta30(theta)*sin(theta);
   // for l=3 m= ±1
   x2=theta31(theta)*theta31(theta)*cos(theta);
   y2=theta31(theta)*theta31(theta)*sin(theta);
   // for l=3 m= ±2
   x3=theta32(theta)*theta32(theta)*cos(theta);
   y3=theta32(theta)*theta32(theta)*sin(theta);
   // for l=3 m= ±3
   x4=theta33(theta)*theta33(theta)*cos(theta);
   y4=theta33(theta)*theta33(theta)*sin(theta);

   fprintf(fp1,"%f\t%f\n",x1,y1);  // for l=3 m= 0
   fprintf(fp2,"%f\t%f\n",x2,y2);  // for l=3 m= ±1
   fprintf(fp3,"%f\t%f\n",x3,y3);  // for l=3 m= ±2
   fprintf(fp4,"%f\t%f\n",x4,y4);  // for l=3 m= ±3
 }
}
