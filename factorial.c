#include<stdio.h>
#include<time.h>
#include<stdlib.h>

                    /* Finding factorial of a number using recursion */

long int factorial(long int n)
{
    long int f;
    if(n==1)
    {
        return 1;
    }
    f=n*factorial(n-1);
    return f;
}

int main()
{
    int n=5;
    printf("Factorial of %d = %d\n", n, factorial(n));
    return 0;
}
