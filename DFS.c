#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct vertex
{
    int u,uf,ud,p,status;
}VERTEX;

typedef struct queue
{
    int rear,front;
    int data[SIZE];
}QUE;
QUE create()
{
    QUE q1;
    q1.front=-1;
    q1.rear=0;
    return q1;
}
void enqueue(QUE*q, int n)
{
    if((q->rear)%SIZE==q->front)
    {
        printf("Queue overflow\n");
    }
    else if(q->rear==0 && q->front==-1)
    {
        q->data[q->rear]=n;
        q->front=0;
        q->rear=1;
    }
    else
    {
        q->rear=(q->rear)%SIZE;
        q->data[q->rear]=n;
        q->rear=q->rear+1;
    }
}

int dequeue(QUE*q)
{
    int key;
    if(q->rear==0 && q->front==-1)
    {
        printf("Queue underflow\n");
        return -1;
    }
    else if((q->front)+1==q->rear)
    {
        key=q->data[q->front];
        q->front=-1;
        q->rear=0;
        return key;
    }
    else
    {
        key=q->data[q->front];
        q->front=(q->front+1)%SIZE;
        return key;
    }
}

void read_array(int data[SIZE][SIZE])
{
    int i=0,j=0,k1,k2,k=0;
    int edge;
    char key[5];
    printf("Enter number of edges\n");
    scanf("%d",&edge);
    for(k=0;k<edge;k++)
    {
        printf("Enter the vertices having edge\n");
        scanf("%d %d",&k1,&k2);
        data[k1][k2]=1;
        data[k2][k1]=1;
    }
}

void INITIALISE_VERTEX(VERTEX V[SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        V[i].p=-1;
        V[i].ud=0;
        V[i].uf=0;
        V[i].status=1;
        V[i].u=i;
    }
}

void DFS_VISIT(VERTEX V[SIZE],int s,int time,int adj[SIZE][SIZE])
{
    time=time+1;
    V[s].ud=time;
    V[s].status=2;
    printf("-->%d",V[s].u);
    for(int i=0;i<SIZE;i++)
    {
        if(adj[s][i]==1)
        {
            if(V[i].status==1)
            {
                V[i].p=s;
                DFS_VISIT(V,i,time,adj);
            }
        }
        time=time+1;
        V[s].uf=time;
        V[s].status=3;
    }
}

void DFS(int adj[SIZE][SIZE],int s,VERTEX V[SIZE])
{
    INITIALISE_VERTEX(V);
    int time=0;
    for(int i=0;i<SIZE;i++)
    {
        if(V[i].status==1)
            DFS_VISIT(V,s,time,adj);
    }
}

int main()
{
    VERTEX V[SIZE];
    int adj[SIZE][SIZE]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    read_array(adj);
    printf("DFS traversal:\nsrc");
    int s=0;
    DFS(adj,s,V);
}
