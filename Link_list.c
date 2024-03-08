#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

int long_list(list*head){
    list *t = head;
    int i=0;
    while(t != NULL){
       i++;
       t=t->next;
    }
    return i;
}

void rech_plus_freq(list *head){

    list *t=NULL;
    list *q=NULL;
    list *p = head;
    int cpt;
    int k =0;
    int num;
    for(int i=1;i<=long_list(head);i++){
        t=head;
        cpt =0;
        while(t != NULL){

            if (p->x == t->x){
                cpt ++;
            }
            t=t->next;
        }
        if (cpt > k){
            k = cpt ;
            num = p->x;
        }

        p->x = p->next->x;
    }

    printf("\nla valeur dans la list la plus frequente est : %d et sa frequence %d ",num,k);
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

void print_list(list *head, int Tai) {
    for (int i = 0; i < Tai; i++) {
        printf(" %d", head->x);
        head = head->next;
    }
    printf("\n");
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

void eclate_list(list *head){

    list *t =head;
    list *h1 =NULL;
    list *h2 = NULL;
    list *q,*p,*k,*l;
    while(t != NULL){
        if (t->x % 2 == 0){
            if (h1 == NULL){
               h1 = new_node(t->x);
               q=h1;
            }
            else{
                l=new_node(t->x);
                q->next =l;
                q=l;
            }
        }
        else{
             if (h2 == NULL){
               h2 = new_node(t->x);
               p=h2;
            }
            else{
                k=new_node(t->x);
                p->next =k;
                p=k;
            }

        }
        t=t->next;
    }
    print_list2(h1);
    print_list2(h2);

}

list *tri_bulle(list*head){
    list *t =(list *)malloc(sizeof(list));
    t=head;
    list *end = NULL;
    bool permute;
    do{
        t=head;
         permute = false;
        while(t->next !=NULL){
            if(t->x > t->next->x){
                int temp = t->x;
                t->x = t->next->x;
                t->next->x = temp;
                permute = true;

            }
            t =t->next;
        }
        
    }while (permute == true);
    return head;
}

list *tri_interclassement_list(list *head1, list *head2) {
    
    list *head3 =NULL;
    list*t1 = head1;
    list*t2 =head2;
    list*t3 =head3;

    while (t1 != NULL && t2 != NULL){
        if (t1->x <= t2->x){
            if (head3 == NULL){
                head3 = new_node(t1->x);
                t3 = head3;
            }
            else{
                if(t3->x != t1->x){
                list*tmp =new_node(t1->x);
                t3->next =tmp;
                t3 =tmp;
                }
            }
            t1=t1->next;
        }
        else{
             if (head3 == NULL){
                head3 = new_node(t2->x);
                t3 = head3;
                
            }
            else{
                if(t3->x != t2->x){
                list*tmp =new_node(t2->x);
                t3->next =tmp;
                t3=tmp;
                }
            }
            t2=t2->next;

        }

        
    }
    while(t1 != NULL){
         if(t3->x != t1->x){
            list *tmp =new_node(t1->x);
            t3->next =tmp;
            t3 =tmp;
         }
            t1=t1->next;
    }
    while(t2 != NULL){
           if(t3->x != t2->x){
            list *tmp =new_node(t2->x);
            t3->next =tmp;
            t3=tmp;
           }
            t2=t2->next;
    }    

    return head3;
}

void accessval(list *head,int val,list *t){
    
     t = head;
    while(t != NULL){
        if (t->x == val){
            printf("%p\n",t);
            break;
        }
        t=t->next;
    }
    if (t== NULL){
        printf("la valeur %d n'est existe \n",val);
    }

}

void accesspos(list *head,int pos,list *t){
    t=head;
    int i=1;

    while(t !=NULL){
        if(i == pos){
            printf("%p\n",t);
            break;
        }
        t=t->next;
        i++;

    }
    if (t== NULL){
        printf("la postion %d n'est existe \n",pos);
    }
}

list* list_insert_pos(list *head, int pos,int y){
    list *t =(list *)malloc(sizeof(list));
    list *q =(list *)malloc(sizeof(list));
    t=head;
    list *u = new_node(y);
    int cpt =1;
    if (pos == 1){
        u->next=t;
        head = u;   
    }
    else{
    while(cpt < pos){
        cpt++;
        q=t;
        t=t->next;
    }
    q->next =u;
    u->next=t;
    }
    return head;
}

list * list_supp(list *head,int pos){
    list *t =(list *)malloc(sizeof(list));
    list *q =(list *)malloc(sizeof(list));
    t=head;
    int cpt =1;
    if (pos == 1){
        head= t->next;
        free(t);
    }
    else{
    while(cpt < pos){
        cpt++;
        q=t;
        t=t->next;
    }
    q->next=t->next;
    free(t);
    }
    return head;
}

list * list_supp_val(list* head,int val){
    list *t =(list *)malloc(sizeof(list));
    list *q =(list *)malloc(sizeof(list));
    t=head;
    if (t->x == val){
       head= t->next;
       
    }
    else{
    while(t->x != val && t != NULL){
        q=t;
        t=t->next;
    }
    }
    if (t!= NULL){

    
     q->next=t->next;
    free(t);
    }else{
        printf("the value doesn't exist in the list");
    }
  return head;
}


void free_list(list *head) {
    list *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int Tai,Tai2;
    int v,h;
    printf("Enter Tai: ");
    scanf("%d", &Tai);

    list *head = create_list(Tai);
    print_list2(head);
    int qw =long_list(head);
    
    printf("\nla longueur de la list est : %d",qw);
    eclate_list(head);
    rech_plus_freq(head);
    list *t=NULL;
    printf("\nenter la valeur tu veux verifuer ");
    
    scanf("%d",&v);
    accessval(head,v,t);

    t=NULL;
    printf("enter la postion tu veux verifuer ");
    
    scanf("%d",&h);
    accesspos(head,h,t);

    printf("Enter Tai2: ");
    scanf("%d", &Tai2);

    list *head2 = create_list(Tai2);
    print_list2(head2);
    //head=tri_bulle(head);
    //print_list2(head);
   list *head3 =tri_interclassement_list(head,head2);
   print_list2(head3);

    printf("enter the value you wanna insert :");
    int o;
    scanf("%d",&o);
    printf("enter the position you wanna insert in :");
    int p;
    scanf("%d",&p);
    head= list_insert_pos(head,p,o);
    print_list2(head);

    printf("enter the position you wanna supp  :");
    int pos;
    scanf("%d",&pos);
    head= list_supp(head,pos);
    print_list2(head);
    printf("enter the value you want to delet :");
    int val;
    scanf("%d",&val);
    head= list_supp_val(head,val);
    print_list2(head);

    free_list(head);
    free_list(head2);

    return 0;
}
