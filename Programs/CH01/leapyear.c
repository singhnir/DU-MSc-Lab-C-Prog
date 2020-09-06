// program to check if the given year is the leap year
#include <stdio.h>

int main()
{
   int year;
   printf("Enter a year to check if it is a leap year:");
   scanf("%d", &year);
   // leap year if perfectly visible by 400
   if (year % 400 == 0) {
      printf("Congrulations! %d is a leap year.\n", year);
   }
   // not a leap year if visible by 100
   // but not divisible by 400
   else if (year % 100 == 0) {
      printf("Too bad! %d is not a leap year.\n", year);
   }
   // leap year if not divisible by 100
   // but divisible by 4
   else if (year % 4 == 0) {
      printf("Congrulations! %d is a leap year.\n", year);
   }
   // all other years are not leap year
   else {
      printf("Too bad! %d is not a leap year.\n", year);
   }
   return 0;
}
