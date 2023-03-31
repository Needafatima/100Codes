#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

                    /* Subset sum problem */

int subset_sum(int arr[],int s,int n){
    int dp[n+1][s+1];
    int i,j;
    for(j=1;j<=s;j++){
        dp[0][j] = 0;
    }
    for(i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=s;j++){
            if(dp[i-1][j]==1){
                dp[i][j] = 1;
            }
            else if(arr[i-1]>j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][s];
}

int main(){
    int arr[4] = {2,3,5,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 9;
    int res = subset_sum(arr,sum,n);
    printf("%d\n",res);
}
