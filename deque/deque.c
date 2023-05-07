#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *front = NULL;
Node *end = NULL;

int isEmpty(){
    if (front == NULL || end == NULL){
        return 1;
    }
    return 0;
}

void appendFront(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(front == NULL){
        front = newNode;
        end = newNode;
    } else {
        newNode -> next = front;
        front = newNode;
    }
}

void append(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(end == NULL){
        front = newNode;
        end = newNode;
    } else {
        newNode -> prev = end;
        end -> next = newNode;
        end = newNode;
    }
}

int popLeft(){
    Node *temp = front;
    int data = temp->data;
    front = front -> next;
    free(temp);
    return data;
}

int pop(){
    Node *temp = end;
    int data = temp->data;
    end = temp->prev;
    free(temp);
    return data;
}

void printList(){
    Node *temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp -> next;
    }
    printf("\n");
}

void deleteData(int value){
    if(!isEmpty()){
        Node *temp = front;
        int i = 0;
        while(temp != NULL){
            if (temp->data == value){
                if(temp->prev == NULL){
                    front = front -> next;
                    front -> prev = NULL;
                } else if (temp->next == NULL){
                    end = temp -> prev;
                    end -> next = NULL;
                } else {
                    temp -> prev -> next = temp -> next;
                    temp -> next -> prev = temp -> prev;
                }
                free(temp);
                break;
            }
            temp = temp->next;
        }
    }
}

void deleteAt(int pos){
    if(!isEmpty()){
        Node *temp = front;
        int i = 0;
        while(i < pos){
            temp = temp->next;
            i++;
        }
        if(temp->prev == NULL){
            front = front -> next;
        }
        else if (temp->next == NULL){
            end = end -> prev;
            end -> next = NULL;
        }
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

void searchData(int data){
    if(!isEmpty()){
        Node *temp = front;
        int i = 0;
        while(temp != NULL){
            if(temp->data == data){
                printf("found %d at position %d\n", data, i);
                return;
            }
            temp = temp->next;
            i++;
        }
        printf("not found\n");
    }
}

void main(){
    int input;
    int value;
    int pos;

    printf("Make Linked List\n");

    while(1){
        printf("1: append / 2: appendFront / 3: searchData / 4: popLeft / 7: deleteAt / 8: deleteData / 9. printList / 0: exit\n");
        printf("Please select option: ");
        scanf("%d",&input);

        if (input == 0) {
            printf("EXIT");
            break;
        }
        else if (input == 1) {
            printf("append: ");
            scanf("%d", &value);
            append(value);
        }
        else if (input == 2){
            printf("appendFront: ");
            scanf("%d", &value);
            appendFront(value);
        }
        else if (input == 3){
            printf("searchData: ");
            scanf("%d", &value);
            searchData(value);
        }
        else if (input == 4){
            printf("popLeft: %d", popLeft());
            printf("\n");
        }
        else if (input == 7){
            printf("deleteAt: ");
            scanf("%d", &pos);
            deleteAt(pos);
        }
        else if (input == 8){
            printf("deleteData: ");
            scanf("%d", &value);
            deleteData(value);
        }
        printf("deque: ");
        printList();
        printf("\n");
    } 
}