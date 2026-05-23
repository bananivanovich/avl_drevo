#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int height(Node * n);
int height(Node * n)
{
    if(n!=NULL)
    {
        return n->height;
    }
    return 0;
}



void stroim_height(Node * n);
void stroim_height(Node * n)
{
    if(n!=NULL)
    {
        int left_h=height(n->left);
        int right_h=height(n->right);
        if(right_h >= left_h)
        {
            n->height=right_h + 1;
        }
        else
        {
            n->height=left_h + 1;
        }
    }
    return;
}

int raznica(Node * n);
int raznica(Node * n)
{
    if(n!=NULL)
    {
        return height(n->left)-height(n->right);
    }
    return 0;
}

Node * right_rot(Node *n);
Node * right_rot(Node *n) // левый внук родной, а правого в детдом справа
{
    Node * son = n -> left;
    Node * grandson = son -> right;

    son->right=n;
    n->left=grandson;

    stroim_height(n);
    stroim_height(son);

    return son;
}

Node * left_rot(Node *n);
Node * left_rot(Node *n) // правый внук родной, а левого в детдом слева
{
    Node * son = n -> right;
    Node * grandson = son -> left;

    son->left=n;
    n->right=grandson;

    stroim_height(n);
    stroim_height(son);

    return son;
}

Node * balance(Node * n);
Node * balance(Node * n)
{
    int flag;
    if (n==NULL)
    {
        return NULL;
    }

    

    flag=raznica(n);

    if(flag > 1) // если слева больше
    {
        if(raznica(n -> left) < 0) // если правый внук больше левого (иначе они просто будут перекидывать это поддерево о кругу)
        {
            n -> left = left_rot(n -> left);
        }
        return right_rot(n);
    }
    else
    {
        if(flag < -1) // ровно наоборот
        {
            if(raznica(n -> right) > 0)
            {
                n -> right = right_rot(n -> right);
            }
            n=left_rot(n);
            return n;
        }
    }
    return n; // esli vse norm
}


Node * add(Node *root, int value);
Node * add(Node *root, int value)
{
    if(root==NULL)
    {
        Node * new=(Node*)malloc(sizeof(Node));
        new->data=value;
        new->height = 1;
        new->left=NULL;
        new->right=NULL;
        return new;
    }

    if(value > root->data)
    {
        root->right = add( root->right, value);
    }
    else
    {
        if(value < root->data)
        {
        root->left = add( root->left, value);
        }
        else // чтобы не было дубликатов
        {
            return root;
        }
    }

    stroim_height(root);
    root=balance(root);
    return root;
    //return balance(root);
}


void freetree(Node * root);
void freetree(Node * root)
{
    if(root!=NULL)
    {
        freetree(root->left);
        freetree(root->right);
        free(root);
    }
}

void printtree(Node * root, int level);
void printtree(Node * root, int level)
{
    if(root==NULL)
    {
        return;   
    }

    printtree(root->right, level+1);

    for(int i=0; i<level; i++)
    {
        printf("   ");
    }

    printf("%d \n", root->data);

    printtree(root->left, level+1);
}

void obhod(Node * root);
void obhod(Node * root)
{
    if(root==NULL)
    {
        return;
    }
    obhod(root->left);
    printf("%d ",root->data);
    obhod(root->right);
}
