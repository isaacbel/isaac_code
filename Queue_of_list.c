#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Display.h"
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>

typedef struct node2{
    int y;
   struct node2 *next3;
}list2;

typedef struct node{
   struct node *next;
   list2 *next2; 
}list;

typedef struct {
    list *head;
    list *tail;
    int size;
}queue;

queue* creat_queue();
list2 *create_list(int Tai);
int size_queue(queue*q);
bool is_empty(queue*q);
//int peek(queue*q, bool *status);
void enqueue(queue*q);
list2* dequeue(queue*q,bool *status );
void destroy(queue*q);
void print_list2(list2*head);
void write_queue(queue*q,int size);

int main(){

    queue*q =creat_queue();
    char choix;
    int values,maxI,minI;
    bool status;
    
    printf("enter the size of the queue :");
    scanf("%d",&values);
    for(int i=1;i<=values;i++){
        enqueue(q);
    }
    
    printf("\n");
    int size = size_queue(q);
    write_queue(q,size);;
    printf("\n");

    list2 *t = dequeue(q,&status);
    printf("Dequeue : \n");
    print_list2(t);
    printf("\n");
    printf("The new queue is : \n");
    write_queue(q,size);
    return 0;
}
//---------------------------------------------------------------------

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
list2*new_node(int y) {
    list2 *tmp = (list2 *)malloc(sizeof(list2));  
    if (tmp == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tmp->y = y;
    tmp->next3 = NULL;
    return tmp;
}

list2 *create_list(int Tai) {
    list2 *head2 = NULL;
    list2 *t = NULL;

    printf("Enter node[1]: ");
    int h;
    scanf("%d", &h);
    head2 = new_node(h);
    t = head2;

    for (int i = 1; i < Tai; i++) {
        printf("Enter node[%d]: ", i + 1);
        int y;
        scanf("%d", &y);
        list2 *tmp = new_node(y);
        t->next3 = tmp;
        t = tmp;
    }
    return head2;
}

void enqueue(queue*q){
   printf("enter Tai of the list : ");
   int Tai;
   scanf("%d",&Tai); 
   list2 * L = create_list(Tai);
   list*p = (list*)malloc(sizeof(list));
   p->next2 =L;
   p->next =NULL;

    if(is_empty(q)){
        q->head =p;
        q->tail =p;
        p->next =NULL;
    }
    else{
        q->tail->next =p;
    }
    q->tail =p;
    q->size++;

}

list2 * dequeue(queue*q,bool *status ){
    if(is_empty(q)){
        *status = false;
        return NULL;
    }
    list2*tmp = q->head->next2;
    q->head->next2 =NULL;
    list* t =q->head;
    *status = true;
    if(q->size == 1){
        q->head =NULL;
        q->tail =NULL;

    }else{
        q->head =q->head->next;
    }
    q->size--;
    free(t);
    return tmp;

}
void print_list2(list2 *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

   // printf("List elements: ");
    while (head != NULL) {
        printf("%d", head->y);
        head = head->next3;
        if (head != NULL)
            printf(" -> ");
    }
    printf("\n");
}

void write_queue(queue* q, int size) {
    if (is_empty(q)) {
        printf("The queue is empty.\n");
    } 
    else if (size == 1) {
        printf("         +------------------+------------------------------------------------------+\n");
        printf("         | %-16s | %-48s \n", "head address", "link list");
        printf("         +------------------+------------------------------------------------------+\n");
        printf(" head--->|                  |\n");
        printf(" tail--->| %-16p | ", (void*)q->head->next2);
        print_list2(q->head->next2);
        printf("         +------------------+------------------------------------------------------+\n");
    }
    else {
        printf("        +------------------+------------------------------------------------------+\n");
        printf("        | %-16s | %-50s \n", "head list", "link list");
        printf("        +------------------+------------------------------------------------------+\n");
        printf("head--->| %-16p | ", (void*)q->head->next2);
        print_list2(q->head->next2);
        
        printf("        +------------------+------------------------------------------------------+\n");
        list* p = q->head->next;

        while (p != NULL) {
            list2 *t = p->next2;
            if (p->next == NULL) {
                printf("tail--->| %-16p | ", (void*)t);
                print_list2(t);
                printf("        +------------------+------------------------------------------------------+\n");
            }
            else {
                printf("        | %-16p | ", (void*)t);
                print_list2(t);
                printf("        +------------------+------------------------------------------------------+\n");
            }
            p = p->next;
        }    
    }
}




void destroy(queue*q){

    list*p = q->head;
    while(p != NULL){
        list2 *t =p->next2;
        while(t != NULL){
            list2 *t2 = t;
            t = t->next3;
            free(t2);
        }
        free(t);
        list*u=p;
        p=p->next;
        free(u);
    }
    free(q);
}




