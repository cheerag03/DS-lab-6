#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node* next; } Node;

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node *head=NULL,*t=NULL;
    for(int i=0;i<n;i++){
        int x; scanf("%d",&x);
        Node* p=malloc(sizeof(Node)); p->data=x; p->next=NULL;
        if(!head) head=t=p; else{ t->next=p; t=p; }
    }
    if(t) t->next=head;
    if(!head){ printf("0\n"); return 0; }
    int c=0; Node* cur=head;
    do{ c++; cur=cur->next; } while(cur!=head);
    printf("%d\n", c);
    return 0;
}
