// program is written only for integer square matrices
#include<stdio.h>
#include<math.h>

// function to enter the elements of matrice
void input_matrix(int n,int matrix[10][10])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
}
// function to print the matrice
void print_matrix(int n,int matrix[10][10])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
}
// function for matrices addition
void addition_matrix(int n,int A[10][10],int B[10][10],int ADD[10][10])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ADD[i][j]=A[i][j]+B[i][j];
		}
	}
}
// function for matrices subtraction
void subtraction_matrix(int n,int A[10][10],int B[10][10],int SUB[10][10])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			SUB[i][j]=A[i][j]-B[i][j];
		}
	}
}
// function for matrices multiplication
void product_matrix(int n,int A[10][10],int B[10][10],int PROD[10][10])
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
int trace(int n,int matrix[10][10])
{
	int trace=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				trace=trace+matrix[i][j];
			}
		}
	}
	return trace;
}

void transfer_matrix(int n,int A[10][10],int B[10][10])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			B[i][j]=A[i][j];
		}
	}
}
// main function to do our job
int main()
{
    int m,n,A[10][10],B[10][10],C[10][10];

    printf("Enter the dimensions of square matrix:");
    scanf("%d",&n);

    printf("\nEnter the elements of matrix A:\n");
    input_matrix(n,A);
    printf("Matrix A:\n");
    print_matrix(n,A);

    printf("\nEnter the elements of matrix B:\n");
    input_matrix(n,B);
    printf("Matrix B:\n");
    print_matrix(n,B);

 	addition_matrix(n,A,B,C);
    printf("\nAddition of matrix A and B:\n");
    print_matrix(n,C);

 	subtraction_matrix(n,A,B,C);
    printf("\nSubtraction of matrix A and B:\n");
    print_matrix(n,C);

 	product_matrix(n,A,B,C);
    printf("\nMultiplication of matrix A and B:\n");
    print_matrix(n,C);

 	printf("\ntrace of matrix A: %d\n",trace(n,A));
 	printf("trace of matrix B: %d\n",trace(n,B));

 	transfer_matrix(n,A,B);
    printf("\nNew matrix B (elements of A):\n");
    print_matrix(n,B);
}