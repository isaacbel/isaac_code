#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 

typedef struct{
    int *array;
    int capacity;
    int top;
}Stack;
Stack *creat_stack(int capacity);
int is_empty(Stack*stack);
int is_full(Stack*stack);
void push(Stack*stack ,int val);
int pop(Stack*stack);
int peek(Stack*stack);
void destroy(Stack*stack);
void write_stack(Stack*q);

int main(){
    printf("enter the capacity of the array : ");
    int cp ;
    int i;
    scanf("%d",&cp);
    Stack*stack = creat_stack(cp);
    for( i=0;i<cp;i++){
        printf("push[%d] : ",i+1);
        int val;
        scanf("%d",&val);
        push(stack,val);
    }
    write_stack(stack);
    printf("\n");
    printf("the value poped is %d ",pop(stack));
    printf("\n the new stack is : \n");
    write_stack(stack);
    printf("push[%d] : ",i+1);
    int val;
    scanf("%d",&val);
    push(stack,val);
    write_stack(stack);
    printf("push[%d] : ",i+2);
    
    scanf("%d",&val);
    
    
    if (is_full(stack)) {
        printf("Stack is full. Would you like to push another element? (Y/N): ");
        char choice;
        scanf(" %c", &choice); // Notice the space before %c to consume newline
        if (choice == 'Y' || choice == 'y') {
            int* temp = realloc(stack->array, (cp + 2) * sizeof(int));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                destroy(stack);
                exit(EXIT_FAILURE);
            } else {
                stack->array = temp;
                stack->capacity = cp + 2;
                push(stack, val);
                cp++;
                printf("The element has been pushed successfully.\n");
            }
        }
    } else {
        push(stack, val);
        printf("push[%d]: ", cp + 2);
        scanf("%d", &val);
        push(stack, val);
    }

    write_stack(stack);
    destroy(stack);

    return 0;
}

Stack *creat_stack(int capacity){
    if(capacity <=0){
        return NULL;
    }
    Stack *stack =(Stack*)malloc(sizeof(Stack));
    if (stack == NULL){
        return NULL;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array =(int*)malloc(sizeof(int)*capacity);
    return stack;
}
int is_empty(Stack*stack){
    return (stack->top == -1);
}

int is_full(Stack*stack){
    return(stack->top == stack->capacity -1);
}

void push(Stack*stack ,int val){
    if(is_full(stack)){
        printf("the que is full ");
        exit(0);
    }
    stack->array[++stack->top] = val;

}
int pop(Stack*stack){
    if(is_empty(stack)){
        return -1;
    }
    return stack->array[stack->top--];
}
int peek(Stack*stack){
    if(is_empty(stack)){
        return -1;
    }
    return stack->array[stack->top];
}
void destroy(Stack*stack){
    free(stack->array);
    free(stack);
}
void write_stack(Stack*q) {
    if (is_empty(q)) {
        printf("The queue is empty.\n");
    } 
    
    else {
       
        printf("+------------------+------------------+\n");
        printf("| %-16s | %-16s |\n", "Value", "Address");
        printf("+------------------+------------------+\n");
        for(int i=0;i<=q->top;i++) {
            if(q->top == i){
                printf("| %-16d | %-16p | <--- top\n", q->array[i], &q->array[i]);
                printf("+------------------+------------------+\n");
            }
            else{
            printf("| %-16d | %-16p |\n", q->array[i],&q->array[i]);
            printf("+------------------+------------------+\n");
            }
            
        }    
    }   
    
}

