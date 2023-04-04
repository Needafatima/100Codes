#include<stdio.h>
#include<stdlib.h>
#define INF 9999
#define SIZE 5
#define NIL -1
int distance[SIZE];

void getgraph(int W[SIZE][SIZE])
{
    int i,j;
    printf("Enter the %dx%d weight matrix of the graph(Enter 9999 if edge doesn't exist\n",SIZE,SIZE);
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            scanf("%d",&W[i][j]);
        }
        printf("\n");
    }
}

void printmatrix(int matrix[SIZE][SIZE])
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
            printf("\n");
    }
    printf("\n");
}

void INITIALISE_SINGLE_SOURCE(int parent[SIZE])
{
    distance[0]=0;
    parent[0]=NIL;
    for(int i=1;i<SIZE;i++)
    {
        distance[i]=INF;
        parent[i]=NIL;
    }

}

void output()
{
    printf("\n\nPath\tDistance\n");
    for(int i=0;i<SIZE;i++)
    {
        printf("0 to %d\t%d\n",i,distance[i]);
    }
}

void print(int array[SIZE])
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

int right(int i)
{
    return 2*i+1;
}

int left(int i)
{
    return 2*i;
}

void swap(int *Q1,int *Q2)
{
    int T;
    T=*Q1;
    *Q1=*Q2;
    *Q2=T;
}

void min_heapify(int n,int queue[n],int i)
{
    int r,l,small=i;
    r=right(i);
    l=left(i);
    while(l<n && distance[queue[small]]>distance[queue[l]])
        small=l;
    while(r<n && distance[queue[small]]>distance[queue[r]])
        small=r;
    if(small!=i)
    {
        swap(&queue[small],&queue[i]);
        min_heapify(n,queue,small);
    }
}

void sorted_heap(int n,int queue[SIZE])
{
    int i;
    for(i=n/2;i>=0;i--)
    {
        min_heapify(n,queue,i);
    }
    swap(&queue[0],&queue[n-1]);
}

int extract_min(int n,int queue[SIZE])
{
    return queue[n-1];
}



void dijkstra(int W[SIZE][SIZE])
{
    int parent[SIZE],queue[10],n=5;
    INITIALISE_SINGLE_SOURCE(parent);
    for(int i=0;i<SIZE;i++)
    {
        queue[i]=i;
    }
    int u;
    while(n)
    {
        sorted_heap(n,queue);
        u=extract_min(n,queue);
        n=n-1;
        for(int i=0;i<SIZE;i++)
        {
            if(W[u][i]!=0)
            {
                if(distance[i]>distance[u]+W[u][i])
                {
                    distance[i]=distance[u]+W[u][i];
                    parent[i]=u;
                }
            }
        }
    }
    output();
}

int main()
{
    int W[SIZE][SIZE];
    int i,p;
    getgraph(W);
    dijkstra(W);
    return 0;
}
