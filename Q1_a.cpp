#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{ int data; struct Node *prev,*next; } Node;

Node* create(int x){ Node* p=malloc(sizeof(Node)); p->data=x; p->prev=p->next=NULL; return p; }

void insert_begin(Node** h,int x){ Node* p=create(x); if(!*h) *h=p; else{ p->next=*h; (*h)->prev=p; *h=p; } }
void insert_end(Node** h,int x){ Node* p=create(x); if(!*h) *h=p; else{ Node* t=*h; while(t->next) t=t->next; t->next=p; p->prev=t; } }
void insert_after(Node** h,int val,int x){ if(!*h) return; Node* t=*h; while(t && t->data!=val) t=t->next; if(t){ Node* p=create(x); p->next=t->next; p->prev=t; if(t->next) t->next->prev=p; t->next=p; } }
void insert_before(Node** h,int val,int x){ if(!*h) return; if((*h)->data==val){ insert_begin(h,x); return; } Node* t=*h; while(t && t->data!=val) t=t->next; if(t){ Node* p=create(x); p->prev=t->prev; p->next=t; t->prev->next=p; t->prev=p; } }

int delete_value(Node** h,int val){
    if(!*h) return 0;
    Node* t=*h;
    while(t && t->data!=val) t=t->next;
    if(!t) return 0;
    if(t==*h){ *h=t->next; if(*h) (*h)->prev=NULL; free(t); return 1; }
    if(t->next) t->next->prev=t->prev;
    t->prev->next=t->next;
    free(t);
    return 1;
}

int search(Node* h,int val){ int pos=1; while(h){ if(h->data==val) return pos; h=h->next; pos++; } return -1; }

int size_dll(Node* h){ int c=0; while(h){ c++; h=h->next; } return c; }

void display(Node* h){
    if(!h){ printf("Empty\n"); return; }
    while(h){ printf("%d ",h->data); h=h->next; }
    printf("\n");
}

int main(){
    Node* head=NULL;
    int ch,x,val;
    while(scanf("%d",&ch)==1){
        if(ch==1){ scanf("%d",&x); insert_begin(&head,x); }
        else if(ch==2){ scanf("%d",&x); insert_end(&head,x); }
        else if(ch==3){ scanf("%d %d",&val,&x); insert_after(&head,val,x); }
        else if(ch==4){ scanf("%d %d",&val,&x); insert_before(&head,val,x); }
        else if(ch==5){ scanf("%d",&val); printf("%d\n", delete_value(&head,val)); }
        else if(ch==6){ scanf("%d",&val); printf("%d\n", search(head,val)); }
        else if(ch==7){ display(head); }
        else if(ch==8){ printf("%d\n", size_dll(head)); }
        else break;
    }
    return 0;
}
