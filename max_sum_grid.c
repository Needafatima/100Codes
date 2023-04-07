#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>

int kadanes(int arr[], int n, int* start, int* finish){
    int sum = 0, maxSum = INT_MIN, i;
    int local_start = 0;
    *finish = -1;
    for(i = 0; i < n; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
            local_start = i+1;
        }
        if(sum > maxSum){
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
    if(*finish != -1){
        return maxSum;
    }
    else{
        maxSum = 0;
        *start = *finish = 0;
        for(i = 0; i < n; i++){
            if(arr[i] > maxSum){
                maxSum = arr[i];
                *start = *finish = i;
            }
        }
        return maxSum;
    }
}

void findMaxGrid(int cols, int M[][cols], int rows){
    int maxSum = INT_MIN, final_start, final_finish, final_left, final_right;
    int left, right, i, j;
    int temp[rows], sum, start, finish;
    for(left = 0; left < cols; left++){
        memset(temp, 0, sizeof(temp));

        for(right = left; right < cols; right++){
            for(i = 0; i < rows; i++)
                temp[i] += M[i][right];

            sum = kadanes(temp, rows, &start, &finish);

            if(sum >maxSum){
                maxSum = sum;
                final_start = start;
                final_finish = finish;
                final_left = left;
                final_right = right;
            }
        }
    }
    printf("%d\n", maxSum);
    printf("%d %d %d %d\n", final_start, final_finish, final_left, final_right);
}

int main() {


    int n, m, i, j;
    scanf("%d %d", &n, &m);
    int M[n][m];
    for(i = 0; i < n; i++){
        for(j = 0; j < m ; j++){
            scanf("%d", &M[i][j]);
        }
    }
    findMaxGrid(m, M, n);
    return 0;
}
