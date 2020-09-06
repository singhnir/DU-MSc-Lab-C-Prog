/* program to cheack whether a given number is a Palindrome number
*Palindrome Numbers are those numbers which do not change when the order is reversed. Thus 11; 22; 33 etc. are palindrome numbers as are 121; 313; 212; 12321 etc. */
#include<stdio.h>
int main()
{
	int num,rev=0,temp;
	//all variables must be  integer types
	printf("Let's begin this game, enter any number and I'll tell you if it is a palindrome!\n");
	scanf("%d",&num);
	temp=num;
	while (temp !=0)
	{
		rev=rev*10;
		rev=rev+temp%10;
		temp=temp/10;
	}
	if (num==rev)
	{
		printf("\n %d Voila, You got it lucky, check with diffrent number.\n",num);
	}
	else {
		printf("\n %d Sorry if you were looking a palindrome number, try again.\n",num);
	}
	return 0;
}
