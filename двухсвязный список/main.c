#include <stdio.h>
#include <stdlib.h>

typedef struct e{
    int field;
    struct e *next;
    struct e *prev;
}elem;//нода

typedef struct l{
    elem *head;
    elem *tail;
}list;//голова хвост

list *init(int data){
    elem *elem1=(elem*)malloc(sizeof(elem));
    list *tmp=(list*) malloc(sizeof(list));
    elem1->field=data;
    elem1->next=elem1->prev=NULL;
    tmp->head=tmp->tail=elem1;
    return tmp;
}//O(1)

list *addStart(list* head,int data){
    elem *elem1=(elem*)malloc(sizeof(elem));
    elem1->field=data;
    elem1->next=head->head;
    elem1->prev=NULL;
    head->head->prev=elem1;
    head->head=elem1;
    return head;
}//O(1)

list *deleteStart(list* head){
    head->head=head->head->next;
    head->head->prev=NULL;
    free(head->head->prev);
    return head;
}//O(1)

void *addEnd(list* head,int data){
    elem *elem1=(elem*)malloc(sizeof(elem));
    elem1->field=data;
    elem1->prev=head->tail;
    elem1->next=NULL;
    head->tail->next=elem1;
    head->tail=elem1;
    return head;
}//O(1)

void *deleteEnd(list* head){
    head->tail=head->tail->prev;
    head->tail->next=NULL;
    free(head->tail->next);
    return head;
}//O(1)

list *addNPosition(list* head,int data,int n){
    elem *elem1=(elem*) malloc(sizeof(elem));
    elem1->field=data;
    elem *p=head->head;
    int count=1;
    while(count<n-1 && p->next){
        p=p->next;
        count++;
    }
    elem1->next=p->next;
    p->next=elem1;
    return head;
}//O(n)

list *deleteNPosition(list* head,int n){
    elem *tmp=NULL;
    elem *p=head->head;
    int count=1;
    while(count<n && p->next){
        tmp=p;
        p=p->next;
        count++;
    }
    tmp->next=p->next;
    free(p);
    return head;
}//O(n)

void *deleteList(list *head){
    while(head->head->next){
        elem *p=head->head;
        head->head=head->head->next;
        free(p);
    }
}//O(n)

list *deleteElem(list *head,int data){
    elem *tmp=head->head;
    elem *p=NULL;
    while(tmp->next && tmp->field!=data){
        p=tmp;
        tmp=tmp->next;
    }
    if(tmp==head->head){
        head->head=head->head->next;
        free(head->head);
        return head;
    }
    if(!(tmp->next) && tmp->field!=data){
        return head;
    }
    p->next=tmp->next;
    free(tmp);
    return head;
}//O(n)

void print(list *head){
    elem *p=head->head;
    while(p){
        printf("%d ", p->field);
        p=p->next;
    }
    printf("\n");
}//O(n)

int main() {
    list *tmp=init(1);//1
    print(tmp);
    tmp=addStart(tmp,2);//2 1
    print(tmp);
    tmp= addStart(tmp,3);//3 2 1
    print(tmp);
    addEnd(tmp,4);//3 2 1 4
    print(tmp);
    tmp=addNPosition(tmp,5,3);//3 2 5 1 4
    print(tmp);
    tmp= deleteElem(tmp,5);//3 2 1 4
    print(tmp);
    tmp= deleteStart(tmp);//2 1 4
    print(tmp);
    deleteEnd(tmp);//2 1
    print(tmp);
    tmp= addNPosition(tmp,6,2);//2 6 1
    print(tmp);
    tmp= deleteNPosition(tmp,2);//2 1
    print(tmp);
    deleteList(tmp);//смэрть
    return 0;
}
