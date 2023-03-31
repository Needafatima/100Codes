#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

                    /* Minimum ticket cost problem using dynamic programming */

int min(int a,int b){
    if(a>b)
        return b;
    else
        return a;
}

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int min_cost(int arr[],int cost[3],int n){
    int lastday = arr[n-1],i;
    int dp[lastday+1];
    bool daysTravelled[lastday+1];
    for(i = 0;i<n;i++){
        daysTravelled[arr[i]] = true;
    }
    dp[0] = 0;
    for(i = 1;i<=lastday;i++){
        if(!daysTravelled[i]){
            dp[i] = dp[i-1];
            continue;
        }
        dp[i] = dp[i-1] + cost[0];
        dp[i] = min(dp[i],dp[max(i-7,0)]+cost[1]);
        dp[i] = min(dp[i],dp[max(i-30,0)]+cost[2]);
    }
    /*for(i = 0;i<=lastday;i++){
        if(!daysTravelled[i]){
            continue;
        }
        printf("%d ",dp[i]);
    }
    printf("\n");*/
    return dp[lastday];
}

int main(){
    int arr[6] = {1, 4, 6, 7, 8, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cost[3] = {2, 7, 15};
    int res = min_cost(arr,cost,n);
    printf("%d\n",res);
    return 0;
}
