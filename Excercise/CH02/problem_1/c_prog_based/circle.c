//plotting a circle of radius 3 centered at (5,5).
//circle eq: (x-h)^2+(y-k^2)=r^2 where (h,k)=centre and r=radii
#include<stdio.h>
#include<math.h>

int main()
{
  FILE*fp=NULL;
  fp=fopen("circle.txt","w");

  float r;
  float x,y,h,k;
  printf("Enter the radius of the circle: ");
  scanf("%ff",&r);
  printf("Enter the centre coordinates (h,k): ");
  scanf("%f%f",&h,&k);
  /*Loop to calculate and store data-points*/
  for(x=h-r;x<=h+r;x=x+0.1)
  {
    y=sqrt(r*r-(x-h)*(x-h))+k; 
    fprintf(fp,"%f\t %f\n",x,y);
  }
  for(x=h+r;x>=h-r;x=x-0.1)
  {
    y=-sqrt(r*r-(x-h)*(x-h))+k; 
    fprintf(fp,"%f\t %f\n",x,y);
  }
}