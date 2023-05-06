#include <stdio.h>
#define STACK_SIZE 10

int stack[STACK_SIZE];
int top = -1;
 
int isFull(){
    if(top >= STACK_SIZE -1){
        printf("stack is full\n");
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top == -1){
        printf("stack is empty\n");
        return 1;
    }
    return 0;
}
 
void push(int data){
    if(!isFull()){
        top++;
        stack[top] = data;
    }
} 
 
int pop(){
    if(!isEmpty()){
        return stack[top--];
    }
}
 
 
void printStack(){
    int i;
    for(i=0; i<=top; i++){
        printf("%d ", stack[i]);
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
            printStack();
            continue;
        }
    }
    return 0;
}