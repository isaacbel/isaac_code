
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>

#define max 100
typedef int  tab[max] ;


typedef struct Node {
    int x;
    struct Node *next;
} list;

list *new_node(int y) {
    list *tmp = (list *)malloc(sizeof(list));  
    if (tmp == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tmp->x = y;
    tmp->next = NULL;
    return tmp;
}

list *create_list(int Tai) {
    list *head = NULL;
    list *t = NULL;

    printf("Enter node[1]: ");
    int h;
    scanf("%d", &h);
    head = new_node(h);
    t = head;

    for (int i = 1; i < Tai; i++) {
        printf("Enter node[%d]: ", i + 1);
        int y;
        scanf("%d", &y);
        list *tmp = new_node(y);
        t->next = tmp;
        t = tmp;
    }
    return head;
}

void print_list2(list *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("List elements: ");
    while (head != NULL) {
        printf("%d", head->x);
        head = head->next;
        if (head != NULL)
            printf(" -> ");
    }
    printf("\n");
}


void lectTabD1(tab T, int*Tai) {
    printf("Entrer la taille du tableau : ");
    scanf("%d", Tai);
    for (int i = 0; i < *Tai; i++) {
        printf("Enter T[%d]: ", i + 1);
        scanf("%d", &T[i]);
    }
}

void writeTabD1(tab T, int Tai) {
    for (int i = 0; i < Tai; i++) {
        printf("%d\t", T[i]);
    }
    printf("\n");
}

void Merge(tab T, int g, int m, int d) {
    int i, j, k;
    int n1 = m - g + 1;
    int n2 = d - m;
    tab T1, T2;
    
    for (i = 0; i < n1; i++) {
        T1[i] = T[g + i];
    }
    for (j = 0; j < n2; j++) {
        T2[j] = T[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = g;
    while (i < n1 && j < n2) {
        if (T1[i] <= T2[j]) {
            T[k++] = T1[i++];
        } else {
            T[k++] = T2[j++];
        }
    }
    while (i < n1) {
        T[k++] = T1[i++];
    }
    while (j < n2) {
        T[k++] = T2[j++];
    }
}

void fusion_sort(tab T,int g ,int d){
    if(g<d){
        int m =(g+d)/2;
        fusion_sort(T,g,m);
        fusion_sort(T,m+1,d);
        Merge(T,g,m,d);
    }
}

list * reverse_list(list **head) {
    if ((*head)->next == NULL || (*head)==NULL) {
        return *head;
    }
    list*p= reverse_list(&(*head)->next); 
    (*head)->next->next = (*head);
    (*head)->next = NULL;
    return p;
}

list *reverse_list_etirative(list *head){
    list *p =NULL;
    list *t= head;
    list *q = head;
    while(q != NULL){
        t = q->next;
        q->next = p;
        p = q;
        q=t;
    }
    return p;
}

bool search_elem_list(list*h,int v){
    if (h == NULL){
        return false;
    }
    if (h->x == v){
        return true;
    }
    else{
      return search_elem_list(h->next,v) ;
    }
}


int Max(int a, int b) {
    return (a >= b) ? a : b;
}

int  Min(int a, int b) {
    return (a <= b) ? a : b;
}


int find_max_tab(tab T,int tai){
    if(tai == 0){
        return T[tai];
    }
    else{
        return Max(T[tai-1],find_max_tab(T,tai-1));
    }
}

int find_min_tab(tab T,int tai){
    if(tai == 0){
        return T[tai];
    }
    else{
        return Min(T[tai-1],find_min_tab(T,tai-1));
    }
}

int som_element_tab(tab T,int tai){
    
    if(tai ==0){
        return T[tai];
    }
    else{
        return T[tai] + som_element_tab(T,tai-1);
    }
}


float average_elements_tab(tab T, int tai) {
    int v = tai +1;
    if (tai == 0) {
        return T[tai]; // Base case: return the only element
    } else {
        //Recursive case:
        return ((T[tai] + average_elements_tab(T, tai - 1) * (tai)) / v);
    }
}

int fibbo_suit(int x) {
    // Base cases: when x is 0 or 1, return x
    if (x == 0 || x == 1) {
        return x;
    } else {
        // Recursive case: return the sum of the
        // (x-1)th and (x-2)th Fibonacci numbers
        return fibbo_suit(x - 1) + fibbo_suit(x - 2);
    }
}

int main(){
    tab array;
    int Tai;
    int Tai2;
    int v,h;
    printf("Enter Tai: ");
    scanf("%d", &Tai2);

    list *head = create_list(Tai2);
    print_list2(head);
    list*p ;
    //p= reverse_list(&head);
    p =reverse_list_etirative(head);
    print_list2(p);
      
    lectTabD1(array, &Tai);
    printf("Tableau avant tri : ");
    writeTabD1(array, Tai);
    fusion_sort(array,0,Tai-1);
    writeTabD1(array,Tai);

    return 0;
}