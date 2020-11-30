// plotting the function
#include<stdio.h>
#include<math.h>

float f(float x, float y){
    return pow(x,3)+pow(y,3)+x*y+1;
}
int main()
{
    FILE*fp=NULL;
    fp=fopen("prob3a.txt","w");
    float x,y;
    for(x=-1.5;x<=1.5;x=x+0.1)
    {
        for (y=-2;y<=2;y=y+0.1)
        {
            fprintf(fp,"%f\t%f\t%f\n",x,y,f(x,y));
        }
    }
}