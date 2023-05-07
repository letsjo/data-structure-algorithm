#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;    
}Node;

typedef struct Tree {
    Node *root;
}Tree;

void init_bst(Tree *t)
{
    t->root = NULL;
}

void push(Tree *t, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode ->  data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    
    printf("push: %d \n", newNode->data);

    if(t->root == NULL){
        t->root = newNode;
    } else {
        Node* temp = t->root;
        while (temp != NULL){
            if (temp -> data > value) {
                if (temp -> left == NULL){
                    temp -> left = newNode;
                    break;
                } else {
                    temp = temp -> left;
                }
            } else {
                if (temp -> right == NULL){
                    temp -> right = newNode;
                    break;
                } else {
                    temp = temp -> right;
                }
            }
        }
    }
}

void erase(Tree *t, int value){
    Node *temp = t->root;
    Node *prev = NULL;
    while (temp != NULL){
        if(temp -> data == value){
            if (temp -> left != NULL && temp -> right == NULL){
                if (prev -> data > value){
                    prev -> left = temp -> left;
                } else {
                    prev -> right = temp -> left;
                }
                free(temp);
            } else if (temp -> left == NULL && temp -> right != NULL){
                if (prev -> data > value){
                    prev -> left = temp -> right;
                } else {
                    prev -> right = temp -> right;
                }
                free(temp);
            } else if (temp -> left != NULL && temp -> right != NULL){
                Node *bottom = temp->right;
                Node *prev_bottom = NULL;
                while (bottom->left != NULL){
                    prev_bottom = bottom;
                    bottom = bottom->left;
                }
                if (prev_bottom == NULL){
                    if (prev -> data > value){
                        prev -> left = bottom;
                        bottom -> left = prev -> left;
                    } else {
                        prev -> right = bottom;
                        bottom -> left = prev -> left;
                    }
                    free(temp); 
                } else {
                    temp->data = bottom->data;
                    prev_bottom->left = bottom->right;
                    free(bottom);
                }
            } else {
                if (prev -> data > value){
                    prev -> left = NULL;
                } else {
                    prev -> right = NULL;
                }
                free(temp);
            }
            
            return;
        }
        
        if (temp -> data > value){
            prev = temp;
            temp = temp -> left;
        }
        else {
            prev = temp;
            temp = temp -> right;
        }
    }
}

void searchTree(Tree *t, int value){
    Node* temp = t->root;
    int level = 0;
    int position = 0;
    while (temp != NULL){
        if (temp -> data == value) {
            printf("found value: %d\nlevel: %d\nat position %d\n", value, level, position);
            return;
        }

        if (temp -> data > value){
            temp = temp -> left;
            position = 2*position+1;
            level++;
        }
        else {
            temp = temp -> right;
            position = 2*position+2;
            level++;
        }
    }
    printf("not found\n");
}

void printTree(Node *parent){
    if (parent != NULL){
        printf("%d ", parent->data);
        printTree(parent->left);
        printTree(parent->right);
    }
}

int main()
{
    int input;
    int value;

    Tree t;
    init_bst(&t);

    push(&t, 5);
    push(&t, 2);
    push(&t, 5);
    push(&t, 65);
    push(&t, 25);
    push(&t, 10);
    push(&t, 15);
    push(&t, 60);
    push(&t, 55);
    push(&t, 40);
    push(&t, 30);
    push(&t, 50);
    push(&t, 35);
    push(&t, 45);
    printTree(t.root);
    printf("\n");
    searchTree(&t, 30);
    searchTree(&t, 35);
    erase(&t, 30);
    erase(&t, 40);
    erase(&t, 50);
    printTree(t.root);
    printf("\n");
    searchTree(&t, 30);
    searchTree(&t, 35);

    return 0;
}