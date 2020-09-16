// plotting the lissajous figure
// this program will generate three datasheets corresponding to each problem
#include<stdio.h>
#include<math.h>

//defining the function for x values
float x(float theta)
{
    return sin(theta);
}
//defining the function for y values
float y(float theta, float A,float n, float delta)
{
    return A*sin(n*theta+delta);
}
//main function will call both x and y function
int main()
{
    float theta;
    //FILE*fp: declaring a pointer of type file
    //NULL: to make sure the file was successfully opened
    // FILE*fp=NULL;  // for simple one case
    FILE*P_2a=NULL;
    FILE*P_2b=NULL;
    FILE*P_2c=NULL;
    // float A,n,delta;

    // fp=fopen("lissajous.txt","w");  // for simple one case
    P_2a=fopen("P_2a.txt","w");   // for problem 1(a)
    P_2b=fopen("P_2b.txt","w");   // for problem 1(b)
    P_2c=fopen("P_2c.txt","w");   // for problem 1(c)

    /*Loop to calculate and store data-points*/
    for(theta=0;theta<=4*M_PI;theta=theta+0.05)
    {
        /*Change A, n or delta here*/
        // A=1;
        // n=2
        // delta=M_PI/4;
        // fprintf(fp,"%f\t%f\n",x(theta),y(theta,A,n,delta));
        // for problem 1(a)
        fprintf(P_2a,"%f\t%f\t%f\t%f\n",x(theta),y(theta,1,2,M_PI/4),y(theta,1,2.5,M_PI/4),y(theta,1,3,M_PI/4));
        // for problem 1(b)
        fprintf(P_2b,"%f\t%f\t%f\t%f\n",x(theta),y(theta,0.5,2,M_PI/4),y(theta,1,2,M_PI/4),y(theta,2,2,M_PI/4));
        // for problem 1(c)
        fprintf(P_2c,"%f\t%f\t%f\t%f\n",x(theta),y(theta,1,2,M_PI/4),y(theta,1,2,M_PI/2),y(theta,1,2,M_PI));
    }

    // fclose(fp);     //close the file handle
    fclose(P_2a);
    fclose(P_2b);
    fclose(P_2c);
}
