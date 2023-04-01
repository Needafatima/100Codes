#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

                /* Longest increasing subsequence problem using dynamic programming */

int LIS(int arr[],int n){
    int i,j,dp[n];
    for(i=0;i<n;i++){
        dp[i] = 1;
    }
    int max = 1;
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[j]+1>dp[i])
                dp[i] = dp[j]+1;
        }
        if(dp[i]>max)
            max = dp[i];
    }
    return max;
}

int main(){
    int arr[6] = {5,11,3,15,30,25};
    int n = sizeof(arr)/sizeof(int);
    int res = LIS(arr,n);
    printf("Length of longest increasing subsequence: %d\n",res);
    return 0;
}
