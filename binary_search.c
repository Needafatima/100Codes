#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int search_binary(int n,int number[10],int key)
{
    int i,status=0,low=0,high=n-1,midterm;
    while(low<=high || high>=low)
    {
        midterm=(low+high)/2;
        if(key==number[midterm])
            {
                status=1;
        break;
            }
            else if(key<number[midterm])
            {
                high=midterm-1;
            }
            else
                low=midterm+1;

    }
    return status;
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    int status = search_binary(5, arr, n);
    status == 0 ? printf("%d not found in array\n", n) : printf("%d found in array\n", n);
    return 0;
}
