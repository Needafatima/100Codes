#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>

int kadanes(int arr[],int n){
    int sum = 0, maxSum = INT_MIN, i;
    int local_start = 0, finish = -1, start = 0;
    for(i = 0; i < n; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
            local_start = i + 1;
        }
        if(sum > maxSum){
            maxSum = sum;
            start = local_start;
            finish = i;
        }
    }
    if(finish == -1){
        maxSum = arr[0];
        for(i = 0; i < n; i++){
            if(arr[i]>maxSum){
                maxSum = arr[i];
            }
        }
    }
    return maxSum;
}

int main(){
    int n = 5;
    int arr[5] = {2, 3, -1, 4, -2};
    int res = kadanes(arr, n);
    printf("The maximum subarray sum = %d\n", res);
    return 0;
}
