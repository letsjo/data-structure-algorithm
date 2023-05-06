#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *top = NULL;

int isEmpty(){
    if (top == NULL){
        printf("stack is empty\n");
        return 1;
    }
    return 0;
}

int push(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    return 0;
}

int pop(){
    if(!isEmpty()){
        Node *temp = top;
        int data = temp->data;
        top = top->next;
        free(temp);
        return data;
    }
}

int printStackReverse(Node *top){
    Node *temp = top;
    if(temp->next != NULL){
        printStackReverse(temp->next);
    }
    printf("%d ", temp->data);
}

int printStack(){
    Node *temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int input;
    int value;

    printf("Make Stack\n");

    while (1){
        printf("Please select option(0: exit / 1: push / 2: pop / 3: printStack): ");
        scanf("%d",&input);
        
        if (input==0){
            printf("EXIT");
            break;
        }
        if (input==1){
            printf("push: ");
            scanf("%d",&value);
            push(value);
            continue;
        }
        if (input==2){
            printf("pop: %d\n", pop());
            continue;
        }
        if (input==3){
            printStackReverse(top);
            printf("\n");
            continue;
        }
    }
    return 0;
}

