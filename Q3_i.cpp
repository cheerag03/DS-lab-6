#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *prev,*next; } Node;

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node *head=NULL,*t=NULL;
    for(int i=0;i<n;i++){
        int x; scanf("%d",&x);
        Node* p=malloc(sizeof(Node)); p->data=x; p->prev=p->next=NULL;
        if(!head) head=t=p; else{ t->next=p; p->prev=t; t=p; }
    }
    int c=0; Node* cur=head;
    while(cur){ c++; cur=cur->next; }
    printf("%d\n", c);
    return 0;
}
