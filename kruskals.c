#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 5
#define INF -1

typedef struct edge
{
    int weight,u,v;
}EDGE;

void INITIALISE_SET(int set[SIZE])
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        set[i]=i;
    }
}

void merge(EDGE *pt,int p,int q,int r)
{
    EDGE *pt1,*pt2;
    int n=q-p+1,m=r-q,i,j,k=p;
    pt1=(EDGE*)malloc(n*sizeof(struct edge));
    pt2=(EDGE*)malloc(m*sizeof(struct edge));
    for(i=0;i<n;i++)
    {
        *(pt1+i)=*(pt+k);
        k++;
    }
    for(i=0;i<m;i++)
    {
        *(pt2+i)=*(pt+k);
        k++;
    }
    i=0;
    j=0;
    k=p;
    while(i<n && j<m)
    {
        if(((pt1+i)->weight)<=((pt2+j)->weight))
        {
            *(pt+k)=*(pt1+i);
            i++;
        }
        else
        {
            *(pt+k)=*(pt2+j);
            j++;
        }
        k++;
    }
    while(i<n)
    {
        *(pt+k)=*(pt1+i);
        i++;
        k++;
    }
    while(j<m)
    {
        *(pt+k)=*(pt2+j);
        j++;
        k++;
    }
}

void mergesort(EDGE *pt,int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergesort(pt,p,q);
        mergesort(pt,q+1,r);
        merge(pt,p,q,r);
    }
}

void unionset(int status[SIZE],int a,int b)
{
    int i;
    int temp=status[a];
    for(i=0;i<SIZE;i++)
    {
        if(status[i]==temp)
        {
            status[i]=status[b];
        }
    }
}

int findset(int status[SIZE],int a,int b)
{
    if(status[a]==status[b])
        return 1;
    return 0;
}

void getgraph(int W[SIZE][SIZE])
{
    int i,j;
    printf("Enter the %dx%d weight matrix of the graph(Give '-1' if no edge exists):\n",SIZE,SIZE);
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

int main()
{
    int status[SIZE],W[SIZE][SIZE];
    int n=pow(SIZE,2),count=0,k=0,u1,v1;
    n=n/2;
    EDGE *pt=(EDGE*)malloc(n*sizeof(struct edge));
    getgraph(W);
    INITIALISE_SET(status);
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            if(i<j && W[i][j]!=INF)
            {
                (pt+k)->u=i;
                (pt+k)->v=j;
                (pt+k)->weight=W[i][j];
                count++;
                k++;
            }
        }
    }
    int p=0,q=count-1;
    mergesort(pt,p,q);
    printf("Edge in MST \tEdge weight:\n");
    for(int i=0;i<count;i++)
    {
        u1=(pt+i)->u;
        v1=(pt+i)->v;
        if(findset(status,u1,v1)!=1)
        {
            unionset(status,v1,u1);
            printf("%d -- %d \t\t %d\n",u1,v1,W[u1][v1]);
        }
    }
    return 0;
}
