//Algorithm of fibonacci series using recursion
#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    printf("Enter the number of term until when fibonacci series is to be found\n");
    scanf("%d",&n);
    n=fib(n);
    printf("%d",n);
    return 0;
}

