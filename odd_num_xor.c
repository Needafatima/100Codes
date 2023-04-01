#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

                /* Finding the number which is not repeated even number of times in an array using xor */

int findNum(int arr[],int n){
    int i,xor = arr[0];
    for(i=1;i<n;i++){
        xor ^= arr[i];
    }
    return xor;
}

int main(){
    int arr[5] = {7,8,7,8,1};
    int n = sizeof(arr)/sizeof(int);
    int res = findNum(arr,n);
    printf("Number in array not repeated even number of times: %d\n",res);
    return 0;
}
