// program to use matalloc function and generate matrices
// make sure "MAKEMAT.C" file is in same directory
#include<stdlib.h>
#include<stdio.h>
#include"MAKEMAT.c"

int main()
{
	int i,j,m=3,n=2;
	float **a,**b;
	a=matalloc(m,n);
	b=matalloc(m,n);
	printf("the given matrix:\n");

	for(i=1;i<=m;++i)
	{
		for(j=1;j<=n;++j)
		{
			a[i][j]=(float)(i*i+j*j)/(float)(i+2*j+2);
			b[i][j]=a[i][j];
			printf("%.2f\t",b[i][j]);
		}
		printf("\n");
	}
}