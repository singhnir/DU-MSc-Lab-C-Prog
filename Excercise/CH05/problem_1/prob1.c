#include<stdio.h>
#include<math.h>
// defining the function to be solved
double f(double x, double y){
    return x+y;
}
double euler(double f(double x,double y),double x0,double y0,double x,double h){
    double y;   
    while(fabs(x-x0)>0.00001){
        y=y0+h*f(x0,y0);        
        y0=y;       
        x0=x0+h;
    }
    return y;
}
double rk2(double f(double x,double y),double x0,double y0,double x,double h){
    double y,k1,k2;
    while(fabs(x-x0)>0.00001){
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        y=y0+k2;
        y0=y;
        x0=x0+h;
    }
    return y;
}
double rk4(double f(double x, double y), double x0, double y0, double x, double h){
    double y,k1,k2,k3,k4;
    while(fabs(x-x0)>0.00001){
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        k3=h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0+h,y0+k3);
        y=y0+(k1+2*k2+2*k3+k4)/6;
        y0=y;
        x0=x0+h;
    }
    return y;
}
int main(){
    double x0,y0,x,y,h;
    printf("Enter the initial values(x0 & y0):");
    scanf("%lf%lf",&x0,&y0);
    printf("Enter the step size h:");
    scanf("%lf",&h);

    printf("x\t\tEuler(y)\tRK2(y)\t\tRK4(y)\n");
    for(x=1;x<=5;x=x+0.1){
        printf("%lf\t",x);

        y=euler(f,x0,y0,x,h);
        printf("%lf\t",y);

        y=rk2(f,x0,y0,x,h);
        printf("%lf\t",y);

        y=rk4(f,x0,y0,x,h);
        printf("%lf\n",y);
    }  
}