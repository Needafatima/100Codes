#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node*p,*l,*r;
    int value;
}*NODE;


NODE create()
{
    NODE newn=(NODE)malloc(sizeof(struct node));
    newn->l=NULL;
    newn->r=NULL;
    newn->p=NULL;
    return newn;
}
//procedure to insert into BST
NODE insert(NODE root,int key)
{
    NODE y=NULL;
    NODE x=root;
    while(x!=NULL)
    {
        y=x;
        if(x->value<key)
            x=x->r;
        else
            x=x->l;
    }
    NODE z=create();
    z->value=key;
    z->p=y;
    if(y==NULL)
        root=z;
    else if(y->value<key)
        y->r=z;
    else
        y->l=z;
    return root;
}

NODE minimum(NODE x)
{
    while(x->l!=NULL)
    {
        x=x->l;
    }
    return x;
}

NODE successor(NODE x)
{
    if(x->r!=NULL)
    {
        return minimum(x->r);
    }
    NODE y;
    y=x->p;
    while(y!=NULL && x!=y->l)
    {
        x=y;
        y=x->p;
    }
    return y;
}

void transplant(NODE root,NODE u,NODE v)
{
    if(u->p==NULL)
    {
        root=v;
    }
    else if(u->p->l==u)
        u->p->l=v;
    else
        u->p->r=v;
    if(v!=NULL)
    {
        v->p=u->p;
    }
}

NODE delete_node(NODE root,int key)
{
    NODE x=root;
    NODE y=NULL;
    while(x!=NULL)
    {
        if(x->value==key)
            break;
        else if(x->value<key)
            x=x->r;
        else
            x=x->l;
    }
    if(x==NULL)
        return root;
    if(x->l==NULL)
    {
        transplant(root,x,x->r);
    }
    else if(x->r==NULL)
    {
        transplant(root,x,x->l);
    }
    else
    {
        NODE y;
        y=successor(x);
        if(y->p!=x)
        {
            transplant(root,y,x->r);
            y->r=x->r;
            y->r->p=y;
        }
        transplant(root,y,x);
        y->l=x->l;
        y->l->p=y;
    }
    return root;
}

int search(NODE root,int key)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->value==key)
        return 1;
    if(root->value<key)
       return search(root->r,key);
    else
        return search(root->l,key);
}

void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->l);
        printf("%d\t",root->value);
        inorder(root->r);
    }
}

int main()
{
    NODE root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,10);
    root=insert(root,35);
    root=insert(root,55);
    root=insert(root,60);
    inorder(root);
    printf("\n");
    root=delete_node(root,55);
    inorder(root);
    printf("\n");
    NODE m=minimum(root);
    printf("Minimum = %d\n",m->value);
    int status=search(root,60);
    if(status==1)
        printf("60 found in BST\n");
    else
        printf("60 not found in BST\n");
    return 0;
}
