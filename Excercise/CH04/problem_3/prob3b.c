// finding the roots
#include<stdio.h>
#include<math.h>


int main()
{
    FILE*fp=NULL;
    fp=fopen("prob3b.txt","w");

    float x,y,f1,f2,f,df,h,acc=0.00001;

    for (x=-1.5;x<=1.5;x+=0.1)
    {
        for (y=-2.0;y<=2.0;y=y+0.1)
        {
            f1=y*y*y+x*y+x*x*x+1.0;
            f2=pow((y+0.1),3)+x*(y+0.1)+x*x*x+1.0;

            if (f1*f2<0)
            {
                do{
                    f=y*y*y+x*y+x*x*x+1.0;
                    df=3.0*y*y+x;
                    h=-f/df;
                    y=y+h;
                }while(fabs(h/y)>acc);
                fprintf(fp,"%f\t%f\n",x,y); 
            }
        }
    }
}