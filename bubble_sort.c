#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//function to swap value of two variables
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}


//function to sort an integer array
//of n integers using bubble sort
int BSort(int A[],int n)
{
	int i,j,count=0,flag=1;
	for(i=1;i<n && flag;i++)
	{
	    flag=0;
		for(j=n-1;j>=i;j--)
		{
			if(A[j] < A[j-1])
			{
			swap(&A[j],&A[j-1]);
			count++;
			flag=1;
			}
		}
	}
	return count;
}

//function to fill an integer array of
//size n randomly
void FillArrayRandom(int A[],int n)
{
	int i,no;
	for(i=0;i<n;i++)
	{
		no=rand()%1000;
		A[i]=no;
	}
}
//function to print array elements

void print(int A[],int n)
{
	int i;
	printf("\nArray elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}

//function to fill an integer array of
//size n in increasing order
void FillArraySorted(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		A[i]=i;
	}
}

//function to fill an integer array of
//size n in decreasing order
void FillArrayReverse(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        A[i]=n-i;
    }
}

//main driver function to invoke above functions
int main()
{
    double d;
    time_t start,end;
	int size=50,A[size],i,j,count;
	FillArrayRandom(A,size);
	//FillArraySorted(A,size);
	//FillArrayReverse(A,size);
	print(A,size);
	printf("\n\nBsort algorithm begins\n");
	count=BSort(A,size);
	print(A,size);
	printf("\n\n Number of swaps = %d\n",count);
    return 0;
}
