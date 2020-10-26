/*To find the HCF (Highest Common Factor) or GCD (Greatest Common Divisor) of two numbers.
*Recall that the HCF of two numbers is the highest or largest common factor of the two.
*Thus, the HCF of 24 and 16 is 8 since 24 = 8x3 and 16 = 8x2*/
#include <stdio.h>
int main()
{
	int num1,num2,i,hcf;
	printf("Enter the two integers to find their HCF:\n");
	scanf("%d %d",&num1,&num2);

	for (i=1;i<=num1 && i<=num2;++i)
	{
		if (num1%i==0 && num2%i==0)
		{
			hcf=i;
		}
	}
	printf("\nHCF of %d and %d is %d.\n",num1,num2,hcf);
}
