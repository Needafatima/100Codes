#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

                /* 0/1 knapsack using dynamic programming */

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int knapsack(int wt[],int val[],int w,int n){
    int dp[n+1][w+1],i,j;
    for(i=0;i<=n;i++){
            for(j=0;j<wt[0];j++)
                dp[i][j] = 0;
    }
    for(j=0;j<=w;j++){
        dp[0][j] = 0;
    }
    for(i=1;i<=n;i++){
        for(j=wt[0];j<=w;j++){
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}

int main(){
    int wt[4] = {2,3,5,6};
    int val[4] = {5,8,10,12};
    int n = sizeof(wt)/sizeof(int);
    int w = 10;
    int res = knapsack(wt,val,w,n);
    printf("Maximum value carried in 0/1 knapsack: %d\n",res);
    return 0;
}
