/*To find the HCF (Highest Common Factor) or GCD (Greatest Common Divisor) of two numbers.
*Recall that the HCF of two numbers is the highest or largest common factor of the two.
*Thus, the HCF of 24 and 16 is 8 since 24 = 8x3 and 16 = 8x2*/
#include <stdio.h>
int main()
{
	int first_num,second_num,i,hcf;
	printf("Enter the two integers to find their HCF:\n");
	scanf("%d %d",&first_num,&second_num);

	for (int i=1;i<=first_num && i<=second_num; ++i)
	{
		if (first_num%i==0 && second_num%i==0)
		{
			hcf=i;
		}
	}
	printf("\nHCF of %d and %d is %d.\n",first_num,second_num,hcf);

	return 0;
}
