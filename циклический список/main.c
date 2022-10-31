#include <stdio.h>
#include <stdlib.h>

typedef struct l{
    int field;
    struct l *ptr;
}list;//нода

list *init(int data){
    list *tmp=(list*)malloc(sizeof(list));
    tmp->field=data;
    tmp->ptr=tmp;
    return tmp;
}//O(1)

list *addStart(list* head,int data){
    list *tmp=(list*)malloc(sizeof(list));
    tmp->field=data;
    tmp->ptr=head;
    list *p=head;
    while(p->ptr!=head){
        p=p->ptr;
    }
    p->ptr=tmp;
    return tmp;
}//O(n)

list *deleteStart(list* head){
    list *tmp=head;
    list *p=head;
    tmp=head->ptr;
    while(p->ptr!=head){
        p=p->ptr;
    }
    p->ptr=tmp;
    free(head);
    return tmp;

}//O(n)

void *addEnd(list* head,int data){
    list *tmp=(list*) malloc(sizeof(list));
    tmp->field=data;
    tmp->ptr=head;
    list *p=head;
    while(p->ptr!=head){
        p=p->ptr;
    }
    p->ptr=tmp;
}//O(n)

void *deleteEnd(list* head){
    list *tmp=NULL;
    list *p=head;
    while(p->ptr!=head){
        tmp=p;
        p=p->ptr;
    }
    tmp->ptr=head;
    free(p);
}//O(n)

list *addNPosition(list* head,int data,int n){
    list *tmp=(list*) malloc(sizeof(list));
    tmp->field=data;
    list *p=head;
    int count=1;
    while(count<n-1 && p->ptr!=head){
        p=p->ptr;
        count++;
    }
    tmp->ptr=p->ptr;
    p->ptr=tmp;
    return head;
}//O(n)

list *deleteNPosition(list* head,int n){
    list *tmp=NULL;
    list *p=head;
    int count=1;
    while(count<n && p->ptr!=head){
        tmp=p;
        p=p->ptr;
        count++;
    }
    tmp->ptr=p->ptr;
    free(p);
    return head;
}//O(n)

void *deleteList(list *head){
    list *head1=head->ptr;
    while(head->ptr!=head1){
        list *p=head;
        head=head->ptr;
        free(p);
    }
}//O(n)

list *deleteElem(list *head,int data){
    list *tmp=head;
    list *p=NULL;
    while(tmp->ptr!=tmp && tmp->field!=data){
        p=tmp;
        tmp=tmp->ptr;
    }
    if(tmp==head){
        free(head);
        return tmp->ptr;
    }
    if(!(tmp->ptr) && tmp->field!=data){
        return head;
    }
    p->ptr=tmp->ptr;
    free(tmp);
    return head;
}//O(n)

void print(list *head){
    list *p=head;
    int i=0;
    while(p->ptr!=head){
        printf("%d ", p->field);
        p=p->ptr;
        i++;
    }
    printf("%d ", p->field);
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
