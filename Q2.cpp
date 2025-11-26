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
    if(!head){ printf("\n"); return 0; }
    Node* cur=head;
    do{ printf("%d ", cur->data); cur=cur->next; } while(cur!=head);
    printf("%d\n", head->data);
    return 0;
}
