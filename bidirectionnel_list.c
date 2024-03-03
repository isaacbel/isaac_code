#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node *next;
    struct Node *prev;
} list;

list *new_node_doubly(int y) {
    list *tmp = (list *)malloc(sizeof(list));  
    if (tmp == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tmp->x = y;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

list *create_list_doubly(int Tai,list**tail) {
    list *head = NULL;
    list *t = NULL;
    
    printf("Enter node[1]: ");
    int h;
    scanf("%d", &h);
    head = new_node_doubly(h);
    t = head;


    for (int i = 1; i < Tai; i++) {
        printf("Enter node[%d]: ", i + 1);
        int y;
        scanf("%d", &y);
        list *tmp = new_node_doubly(y);
        t->next = tmp;
        tmp->prev =t;
        t = tmp;
    }
    *tail = t;
    return head;
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


list* list_insert_pos(list *head, list **tail, int pos, int y) {
    list *t = head;
    list *u = new_node_doubly(y);
    int cpt = 1;

    if (head == NULL || pos == 1) {
        u->next = head;
        if (head != NULL)
            head->prev = u;
        head = u;
        if (*tail == NULL)
            *tail = u;
    } else if (pos == long_list(head) + 1) {
        (*tail)->next = u;
        u->prev = *tail;
        *tail = u;
    } else {
        while (cpt < pos - 1 && t != NULL) {
            cpt++;
            t = t->next;
        }
        if (t == NULL) {
            printf("Invalid position\n");
            return head;
        }
        u->next = t->next;
        if (t->next != NULL)
            t->next->prev = u;
        t->next = u;
        u->prev = t;
    }
    return head;
}

list *list_supp(list *head, list **tail, int pos) {
    list *t = head;
    int cpt = 1;

    if (pos == 1) {
        head = t->next;
        head->prev = NULL;
        free(t);
    } else if (pos == long_list(head)) {
        list *p = *tail;
        *tail = (*tail)->prev;
        free(p);
    } else {
        while (cpt < pos) {
            cpt++;
            t = t->next;
        }

        t->prev->next = t->next;
        t->next->prev = t->prev;
        free(t);
    }
    return head;
}


void print_list_doubly2(list *head,list*tail) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    list *t=NULL;

    printf("List elements: ");
    while (head != NULL) {
        printf("%d", head->x);
        
        head = head->next;
        if (head != NULL)
            printf(" -> ");
    }
    printf("\n");

    printf("List elements in reverse: ");
    while (tail != NULL) {
        printf("%d", tail->x);
        tail = tail->prev;
        if (tail != NULL)
            printf(" -> ");
    }
    printf("\n");
}

int main() {
    int Tai;
    printf("Enter Tai: ");
    scanf("%d", &Tai);

    list *head, *tail;
    head = create_list_doubly(Tai, &tail);
    print_list_doubly2(head,tail);

    printf("Enter the value you want to insert: ");
    int o;
    scanf("%d", &o);
    printf("Enter the position you want to insert in: ");
    int p;
    scanf("%d", &p);
    head = list_insert_pos(head, &tail, p, o);
    print_list_doubly2(head,tail);

    printf("Enter the position you want to remove: ");
    int pos;
    scanf("%d", &pos);
    head = list_supp(head, &tail, pos);
    print_list_doubly2(head,tail);

    return 0;
}