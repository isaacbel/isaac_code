#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>

typedef struct node{
    int x;
   struct node *next;
}list;

typedef struct {
    list *head;
    list *tail;
    int size;
}queue;

queue* creat_queue();
int size_queue(queue*q);
bool is_empty(queue*q);
int peek(queue*q, bool *status);
void enqueue(queue*q,int value);
void write_queue(queue*q,int size);
int dequeue(queue*q,bool *status );
void destroy(queue*q);

int main(){
    
    queue*q =creat_queue();
    char choix;
    int values,maxI,minI;
    bool status;
    printf("Intervalle [minI, maxI] des valeurs %c prendre al%catoirement\n",133,130);
    printf("---------------------------------------------------------\n");
    printf("Donner la borne inf%crieure : ",130);
    scanf("%d", &minI);
    printf("Donner la borne sup%crieure : ",130);
    scanf("%d", &maxI);
    values = minI + rand() % (maxI - minI + 1);
    for(int i=1;i<=values;i++){
        int val=minI + rand() % (maxI - minI + 1);;
        enqueue(q,val);
    }
    printf("\n");
    int size = q->size;
    write_queue(q,size);
    Sleep(1);

    do{
       int V = dequeue(q,&status);
       int size = q->size;
       if(status){
       printf("the value is %d\n",V);
  
       printf("the new queue is : \n");
       write_queue(q,size);
       printf("\n\nIf u wanna dequeue another value enter 'Y' to repeat or any other key to exit: ");
       }else{
        printf("the queue is empty\n");
        break;
       }
       
        scanf(" %c", &choix); 
        while (getchar() != '\n');
    } while (choix == 'Y' || choix == 'y') ;
    
  return 0;
}

queue* creat_queue(){
    queue*q =(queue*)malloc(sizeof(queue));
     if (q == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    q->head =NULL;
    q->tail=NULL;
    q->size =0;

    return q;
}
int size_queue(queue*q){

    return q->size;
}
bool is_empty(queue*q){
    return (q->size ==0);
}
int peek(queue*q, bool *status){
    if (is_empty(q)){
        *status = false;
        return -1;
    }   
    *status =true;
    return q->head->x;  
}
void enqueue(queue*q,int value){
    list *node =(list*)malloc(sizeof(list));
    node->x = value;
    node->next =NULL;
    if(is_empty(q)){
        q->head =node;
        q->tail =node;
    }
    else{
        q->tail->next =node;
    }
    q->tail =node;
    q->size++;
}


void write_queue(queue*q,int size) {
    if (is_empty(q)) {
        printf("The queue is empty.\n");
    } 
    else if (size == 1){
        printf("         +------------------+------------------+\n");
        printf("         | %-16s | %-16s |\n", "Value", "Address");
        printf("         +------------------+------------------+\n");
        printf(" tail--->| %-16d | %-16p | <--- head \n", q->head->x, q->head);
        printf("         +------------------+------------------+\n");
    }
    else {
       
        printf("+------------------+------------------+\n");
        printf("| %-16s | %-16s |\n", "Value", "Address");
        printf("+------------------+------------------+\n");
        printf("| %-16d | %-16p | <--- head \n", q->head->x, q->head);
        printf("+------------------+------------------+\n");
        list* p = q->head->next;

        while (p != NULL) {
            if(p->next == NULL){
                printf("| %-16d | %-16p | <--- tail\n", p->x, p);
                printf("+------------------+------------------+\n");
            }
            else{
            printf("| %-16d | %-16p |\n", p->x, p);
            printf("+------------------+------------------+\n");
            }
            p = p->next;
        }    
       
    }
}


int dequeue(queue*q,bool *status ){

    if(is_empty(q)){
        *status =false;
        return -1;
    }
    int value =q->head->x;
    *status =true;
    list*p = q->head;
    if(q->size == 1){
        q->head =NULL;
        q->tail =NULL;
    }
    else{
    q->head =q->head->next;
    }
    q->size--;
    free(p);

    return value;
}
void destroy(queue*q){

    list*p = q->head;
    while(p != NULL){
        
        list*u=p;
        p=p->next;
        free(u);
    }
    free(q);
}

