#ifndef my_h
#define my_h
typedef struct Node{
    int data;
    int height;
    struct Node * left;
    struct Node * right;
}Node;
int height(Node * n);
void stroim_height(Node * n);
int raznica(Node * n);
Node * right_rot(Node *n);
Node * left_rot(Node *n);
Node * balance(Node * n);
Node * add(Node *root, int value);
void freetree(Node * root);
void printtree(Node * root, int level);
void obhod(Node * root);
#endif