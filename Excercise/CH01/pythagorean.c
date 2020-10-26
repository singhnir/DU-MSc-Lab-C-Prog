//a program to finnd all the distinct sets of Pythagorean numbers less than 100
#include<stdio.h>

int main()
{
    int a,b,c,n=100;
    printf("distinct sets of Pythagorean numbers less than 100\n");
    printf("\na\tb\tc\n");
    for (a=1;a<=n;++a)
    {
        for (b=a;b<=n;++b)
        {
            for (c=b;c<=n;++c)
            {
                if (c*c==a*a+b*b)
                {
                    printf("%d\t%d\t%d\n",a,b,c);
                }
            }
        }
    }
}
