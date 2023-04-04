#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int ssum(int s)
{
    if(s==0)
        return 0;
    if(s==1)
        return 1;
    return s*s+ssum(s-1);
}

int main(){
    int n = 5;
    printf("Sum of squares upto %d = %d\n", n, ssum(n));
    return 0;
}
