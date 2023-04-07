#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>

int countSetBits(int n){
    int count = 0;
    while(n){
        if(n%2 == 1){
            count++;
        }
        n = n>>1;
    }
    return count;
}

int main(){
    int n = 5;
    int res = countSetBits(n);
    printf("%d has %d bits set in its binary representation.\n", n, res);
    return 0;
}
