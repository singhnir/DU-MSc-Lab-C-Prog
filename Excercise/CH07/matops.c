// it contains functions for the matrix operations
// (add,sub,product,trace,transferring elements)
// use #include"matops.c" in the program you wished to use this
#include<stdio.h>
#include<math.h>

// function to print the matrice
void print_matrix(int n,double matrix[10][10])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%.2lf\t",matrix[i][j]);
		}
		printf("\n");
	}
}

// function for matrices addition
void addition_matrix(int n,double A[10][10],double B[10][10],double ADD[10][10])
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			ADD[i][j]=A[i][j]+B[i][j];
		}
	}
}
// function for matrices subtraction
void subtraction_matrix(int n,double A[10][10], double B[10][10], double SUB[10][10])
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            SUB[i][j]=A[i][j]-B[i][j];
        }
    }
}
// function for matrices multiplication
void product_matrix(int n,double A[10][10], double B[10][10], double PROD[10][10])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            PROD[i][j]=0;
            for(int k=1;k<=n;k++)
            {
                PROD[i][j]=PROD[i][j]+A[i][k]*B[k][j];  
            }
        }
    }   
}
// function for matrice trace
int trace(int n,double matrix[10][10])
{
	int trace=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==j)
			{
				trace=trace+matrix[i][j];
			}
		}
	}
	return trace;
}

void transfer_matrix(int n,double A[10][10],double B[10][10])
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			B[i][j]=A[i][j];
		}
	}
}