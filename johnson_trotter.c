#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#define LEFT_TO_RIGHT true
#define RIGHT_TO_LEFT false

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int searchArr(int arr[], int n, int mobile){
    int i;
    for(i = 0; i < n; i++){
        if(arr[i] == mobile){
            return i+1;
        }
    }
}

int getMobile(int arr[], bool dir[], int n){
    int mobile_prev = 0, mobile = 0;
    int i;
    for(i = 0; i < n; i++){
        if(dir[arr[i]-1] == RIGHT_TO_LEFT && i != 0){
            if(arr[i] > arr[i - 1] && arr[i] > mobile_prev){
                mobile = arr[i];
                mobile_prev = mobile;
            }
        }

        if(dir[arr[i] - 1] == LEFT_TO_RIGHT && i != n-1){
            if(arr[i] > arr[i + 1] && arr[i] > mobile_prev){
                mobile = arr[i];
                mobile_prev = mobile;
            }
        }
    }
    return mobile;
}

void johnsonTrotter(int arr[], bool dir[], int n){
    int i;
    int mobile = getMobile(arr, dir, n);
    int pos = searchArr(arr, n , mobile);

    if(dir[arr[pos - 1] - 1] == LEFT_TO_RIGHT)
        swap(&arr[pos - 1], &arr[pos]);
    else
        swap(&arr[pos -1], &arr[pos - 2]);

    for(i = 0; i < n; i++){
        if(arr[i] > mobile){
            if(dir[arr[i] - 1] == LEFT_TO_RIGHT)
                dir[arr[i] - 1] = RIGHT_TO_LEFT;
            else
                dir[arr[i] - 1] = LEFT_TO_RIGHT;
        }
    }

    for(i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int fact(int n){
    int res = 1;
    int i;
    for(i = 2; i <= n; i++){
        res *= i;
    }
    return res;
}

void printPermutation(int n){
    int arr[n], i;
    bool dir[n];
    for(i = 1;i <= n;i++){
        arr[i-1] = i;
        printf("%d", i);
    }
    printf("\n");
    for(i = 0; i < n; i++){
        dir[i] = RIGHT_TO_LEFT;
    }
    for(i = 1; i < fact(n); i++){
        johnsonTrotter(arr, dir, n);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printPermutation(n);
    return 0;
}
