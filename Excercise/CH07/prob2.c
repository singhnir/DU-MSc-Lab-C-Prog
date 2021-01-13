// program to calculate the commutator [a,b]
// make sure file matops.c is in same directory
#include<stdio.h>
#include<math.h>
#include"matops.c"
// function to generate the matrices
void input_matrix(int n,double A[10][10],double B[10][10])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            A[i][j]=(double)i/(double)(i+j);
            B[i][j]=(double)j/(double)(i+j);
        }
    }  
}
// main program to calculate the commutator
int main()
{
    int n=4;
    double a[10][10],b[10][10],ab[10][10],ba[10][10],com[10][10];
    input_matrix(n,a,b);

    printf("printing the matrix a:\n");
    print_matrix(n,a);
    printf("\nprinting the matrix b:\n");
    print_matrix(n,b);

    product_matrix(n,a,b,ab);   //commutator 1st term
    product_matrix(n,b,a,ba);   //commutator 2nd term
    subtraction_matrix(n,ab,ba,com);
    printf("\ncommutator c=[a,b]=ab-ba:\n");
    print_matrix(n,com);
}