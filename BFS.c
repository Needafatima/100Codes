//BFS implementation using queue

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5
#define INF 9999
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
    else if(q->front==-1 && q->rear==0)
    {
        q->front=0;
        q->data[q->rear]=n;
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
    if(q->front==-1 && q->rear==0)
    {
        printf("Queue underflow\n");
        return -1;
    }
    else if(q->front+1==q->rear)
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
void display_array(int data[SIZE][SIZE])
{
    int i=0,j=0;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            printf("%d\t",data[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i=0,j=0,n,count=0,s,u;
    int matrix[SIZE][SIZE];
    int status[SIZE]={1,1,1,1,1},distance[SIZE]={0,INF,INF,INF,INF};
    QUE q=create();
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            matrix[i][j]=0;
        }
    }
    read_array(matrix);
    //display_array(matrix);
    printf("Enter the source vertex\n");
    scanf("%d",&s);
    enqueue(&q,s);
    //printf("%d\t",q.data[q.front]);
    //printf("rear = %d front = %d\n",q.rear,q.front);
    for(i=0;i<SIZE;i++)
    {
        u=dequeue(&q);
        printf("%d\t",u);
        printf("rear = %d front = %d\n",q.rear,q.front);
        for(j=0;j<SIZE;j++)
        {
            if(matrix[u][j]==1)
            {
                if(status[j]==1)
                {
                    status[j]=2;
                    enqueue(&q,j);
                    printf("%d\t",j);
                    printf("rear = %d front = %d\n",q.rear,q.front);
                    distance[j]=distance[u]+1;
                }
            }
        }
        status[u]=3;
       //printf("%d\t",u);
    }
    printf("\nVertex\tDistance from source\n");
    for(i=0;i<SIZE;i++)
    {
        printf("%d\t%d\n",i,distance[i]);
    }
    return 0;
}
