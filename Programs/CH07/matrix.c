// program to print and add 2x3 matrices
#include<stdio.h>

float a[2][3]={{.1,.2,.3},{-.2,-.4,-.6}};
float b[2][3]={{.3,.4,.5},{.6,.7,.8}};

float c[2][3];	// addition matrix
int i,j;

int main()
{
	printf("addition matrice:\n");
	for (i=0;i<=1;++i)
	{
		for (j=0;j<=2;++j)
		{
			c[i][j]=a[i][j]+b[i][j];
			// printing the matrices
			printf("%.2f\t",c[i][j]);
		}
		printf("\n");
	}
}