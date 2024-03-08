#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


typedef struct Node {
    int puiss;
    int conf;
    struct Node *next;
} list;




list *new_node(int x,int y) {
    list *tmp = (list *)malloc(sizeof(list));  
    if (tmp == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tmp->puiss = x;
    tmp->conf = y;
    tmp->next = NULL;
    return tmp;
}



list* lect_poly(int Tai) {
    list* head = NULL;
    list* t = NULL;

    // Read the first coefficient and power
    printf("Enter coefficient [1]: ");
    int coefficient, power;
    scanf("%d", &coefficient);
    printf("Enter power: ");
    scanf("%d", &power);
    head = new_node(power, coefficient);
    t = head;

    // Read the remaining coefficients and powers
    for (int i = 1; i < Tai; i++) {
        printf("Enter coefficient [%d]: ", i + 1);
        scanf("%d", &coefficient);
        printf("Enter power: ");
        scanf("%d", &power);
        if (power <= t->puiss) {
            printf("Error: The power must be greater than the previous power.\n");
            i--; 
            continue;
        }
        list* tmp = new_node(power, coefficient);
        t->next = tmp;
        t = tmp;
    }
    return head;
}

void writepoly(list *head) {
    list *t = head;
    while(t != NULL){
        if (t->conf != 0) {
           if(t->puiss == 0){
            printf("%d",t->conf);
           } 
           else{
            printf("%dx^%d ", t->conf, t->puiss);
           }
            if (t->next != NULL && t->next->conf > 0) {
                printf("+ ");
            }
            
        }
        t=t->next;
    }
    printf("\n");
}

int calcule(list *head,int x){
       int sum=0;
       list *t=head;
       while(t != NULL){
        sum+=t->conf*pow(x,t->puiss);
        t=t->next;
       }
    return sum;   
}

void derive( list *head,list **drv){

    list *t=head;
    *drv = NULL;
    list *tmp=NULL;
    while(t != NULL){

        if (*drv == NULL){
            *drv = new_node(t->puiss -1,t->puiss*t->conf);
            tmp = *drv;
        }
        else{
            tmp->next =new_node(t->puiss -1,t->puiss*t->conf);
            tmp = tmp->next;
        }
      t=t->next;
    }
}



int comparelist(const void *a, const void *b) {
     list *head1 = (list*)a;
     list *head2 = (list*)b;
    return head2->puiss - head1->puiss;
}

int long_list(list*head){
    list *t = head;
    int i=0;
    while(t != NULL){
       i++;
       t=t->next;
    }
    return i;
}


list *somme_poly(list *head1, list *head2) {
    list *t1 = head1;
    list *t2 = head2;
    list *tmp = NULL;
    list *head3 = NULL;

    // Handle the case when both lists are not empty
    while (t1 != NULL && t2 != NULL) {
        if (head3 == NULL) {
            if (t1->puiss == t2->puiss) {
                head3 = new_node(t1->puiss, t1->conf + t2->conf);
                tmp = head3;
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->puiss < t2->puiss) {
                head3 = new_node(t1->puiss, t1->conf);
                tmp = head3;
                t1 = t1->next;
            } else {
                head3 = new_node(t2->puiss, t2->conf);
                tmp = head3;
                t2 = t2->next;
            }
        } else {
            if (t1->puiss == t2->puiss) {
                tmp->next = new_node(t1->puiss, t1->conf + t2->conf);
                tmp = tmp->next;
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->puiss < t2->puiss) {
                tmp->next = new_node(t1->puiss, t1->conf);
                tmp = tmp->next;
                t1 = t1->next;
            } else {
                tmp->next = new_node(t2->puiss, t2->conf);
                tmp = tmp->next;
                t2 = t2->next;
            }
        }
    }

    // Handle the case when one of the lists is empty
    while (t1 != NULL) {
        if (head3 == NULL) {
            head3 = new_node(t1->puiss, t1->conf);
            tmp = head3;
        } else {
            tmp->next = new_node(t1->puiss, t1->conf);
            tmp = tmp->next;
        }
        t1 = t1->next;
    }

    while (t2 != NULL) {
        if (head3 == NULL) {
            head3 = new_node(t2->puiss, t2->conf);
            tmp = head3;
        } else {
            tmp->next = new_node(t2->puiss, t2->conf);
            tmp = tmp->next;
        }
        t2 = t2->next;
    }

    return head3;
}


list *somme_poly2(list *head1, list *head2) {
    // Convert linked lists to arrays for sorting
    int len1 = long_list(head1);
    int len2 = long_list(head2);
     list *arr1 = malloc(len1 * sizeof( list));
     list *arr2 = malloc(len2 * sizeof( list));

    // Copy linked lists to arrays
    int i = 0;
    while (head1 != NULL) {
        arr1[i++] = *head1;
        head1 = head1->next;
    }
    i = 0;
    while (head2 != NULL) {
        arr2[i++] = *head2;
        head2 = head2->next;
    }

    // Sort arrays
    qsort(arr1, len1, sizeof( list), comparelist);
    qsort(arr2, len2, sizeof( list), comparelist);

    // Merge sorted arrays to create the result list
    list *head3 = NULL;
    list *tmp = NULL;
    int idx1 = 0, idx2 = 0;
    while (idx1 < len1 || idx2 < len2) {
        int p1 = (idx1 < len1) ? arr1[idx1].puiss : INT_MIN;
        int p2 = (idx2 < len2) ? arr2[idx2].puiss : INT_MIN;
        if (p1 > p2) {
            if (head3 == NULL) {
                head3 = new_node(arr1[idx1].puiss, arr1[idx1].conf);
                tmp = head3;
            } else {
                tmp->next = new_node(arr1[idx1].puiss, arr1[idx1].conf);
                tmp = tmp->next;
            }
            idx1++;
        } else if (p1 < p2) {
            if (head3 == NULL) {
                head3 = new_node(arr2[idx2].puiss, arr2[idx2].conf);
                tmp = head3;
            } else {
                tmp->next = new_node(arr2[idx2].puiss, arr2[idx2].conf);
                tmp = tmp->next;
            }
            idx2++;
        } else { // p1 == p2
            if (head3 == NULL) {
                head3 = new_node(arr1[idx1].puiss, arr1[idx1].conf + arr2[idx2].conf);
                tmp = head3;
            } else {
                tmp->next = new_node(arr1[idx1].puiss, arr1[idx1].conf + arr2[idx2].conf);
                tmp = tmp->next;
            }
            idx1++;
            idx2++;
        }
    }

    // Free allocated memory for arrays
    free(arr1);
    free(arr2);

    return head3;
}


list * Mul_poly(list *head1 ,list *head2){
    list *t1 = head1;
    list*t2 =NULL;
    list*tmp =NULL;
    list *head3 = NULL;
    list*head4 = NULL;
    int cpt = 1;
    while( t1 != NULL){
       t2 = head2;
       head4 = NULL;
       if (cpt <2){
       while(t2 != NULL){ 
        if(head3 == NULL){
            head3 =new_node(t1->puiss + t2->puiss,t1->conf * t2->conf);
            tmp = head3;
            t2=t2->next;
        }
         else{ 
            tmp->next =new_node(t1->puiss + t2->puiss,t1->conf * t2->conf);
            tmp =tmp->next;
            t2 =t2->next; 
         }
        } 
       }else{
        while(t2 != NULL){ 
        if(head4 == NULL){
            head4 =new_node(t1->puiss + t2->puiss,t1->conf * t2->conf);
            tmp = head4;
            t2=t2->next;
        }
         else{ 
            tmp->next =new_node(t1->puiss + t2->puiss,t1->conf * t2->conf);
            tmp =tmp->next;
            t2 =t2->next; 
         }
        }


       }
        head3 = somme_poly(head3,head4);
       t1=t1->next;
       cpt++;
    }

    return head3;

}

int main(){

    int Tai,Tai2;
    printf("enter the Tai of the poly : ");
    scanf("%d",&Tai);
   list*head= lect_poly(Tai);
    writepoly(head);
    list*drv;
    // derive(head,&drv);
     // writepoly(drv);
     printf("enter the Tai of the poly : ");
    scanf("%d",&Tai2);
   list*head2= lect_poly(Tai2);
    writepoly(head2);
     list *h =somme_poly(head2 ,head);
     writepoly(h);
     h =Mul_poly(head ,head2);
     writepoly(h);


    
}

