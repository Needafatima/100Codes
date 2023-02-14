#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define INF 99999

/* The rows of the cost matrix indicate the candidates and columns indicate tasks.
    cost[i][j] indicates cost of assigning jth task to ith candidate.
    One candidate can be assigned only one task*/

void populateCost(int n,int cost[n][n])     //Function to populate the cost array
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("cost[%d][%d]:",i,j);
            scanf("%d",&cost[i][j]);
        }
    }
}

void initDP(int DPtable[],int n)            //Function which initializes the DP table
{
    int i;
    DPtable[0]=0;
    for(i=1;i<n;i++)
    {
        DPtable[i]=INF;
    }
}

void showDP(int DPtable[],int n)            //Function to print content of DP table
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",DPtable[i]);
    }
    printf("\n");
}

int minCost(int DPtable[],int size,int n,int cost[n][n])    //Function to calculate the possible minimum cost
{
    int x,j,mask,temp;
    for(mask=0;mask<size;mask++)
    {
        temp=mask;
        x=0;                    //Finding number of set bits in mask
        while(temp){
            if((temp%2)!=0)
            {
                x++;            //x variable holds the number of set bits in the mask
            }
            temp=temp>>1;
        }
        for(j=0;j<n;j++)
        {
            if(!(mask&(1<<j)))      //if jth bit in mask is not set then i.e., jth task is not assigned
            {
                /*Assigning jth task to xth person and finding the minimum cost (either the cumulative cost or initial cost)*/
                DPtable[mask|(1<<j)] = DPtable[mask|(1<<j)]>(DPtable[mask]+cost[x][j]) ? (DPtable[mask]+cost[x][j]) : DPtable[mask|(1<<j)];
            }
        }
    }
    return DPtable[size-1];
}

int main()
{
    int n,least_cost;
    scanf("%d",&n);
    int size = pow(2,n);
    int cost[n][n];
    int DPtable[size];
    populateCost(n,cost);
    initDP(DPtable,size);
    least_cost=minCost(DPtable,size,n,cost);
    printf("DP table: ");
    showDP(DPtable,size);
    printf("The minimum cost is: %d\n",least_cost);
    return 0;
}
