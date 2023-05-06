#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *front = NULL;

int isEmpty(){
    if (front == NULL){
        printf("queue is empty\n");
        return 1;
    }
    return 0;
}

int enqueue(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL){
        front = newNode;
    }else{
        Node *temp = front;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return 0;
}

int dequeue(){
    if(!isEmpty()){
        Node *temp = front;
        int data = temp->data;
        front = front->next;
        free(temp);
        return data;
    }
    return 0;
}

int printQueue(){
    Node *temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int printQueueReverse(Node *front){
    Node *temp = front;
    if(temp->next != NULL){
        printQueueReverse(temp->next);
    }
    printf("%d ", temp->data);
}

int main(){
    int input;
    int value;

    printf("Make Queue\n");

    while (1){
        printf("Please select option(0: exit / 1: enqueue / 2: dequeue / 3: printQueue): ");
        scanf("%d",&input);
        
        if (input==0){
            printf("EXIT");
            break;
        }
        if (input==1){
            printf("enqueue: ");
            scanf("%d",&value);
            enqueue(value);
        }
        if (input==2){
            value = dequeue();
            if (value != 0){
                printf("dequeue: %d\n", value);
            }
        }
        if (input==3){
            printQueue(front);
        }
    }
    return 0;
}
