#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ char c; struct Node *prev,*next; } Node;

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node *head=NULL,*t=NULL;
    for(int i=0;i<n;i++){
        char s[8]; scanf("%s",s);
        Node* p=malloc(sizeof(Node)); p->c=s[0]; p->prev=p->next=NULL;
        if(!head) head=t=p; else{ t->next=p; p->prev=t; t=p; }
    }
    if(!head){ printf("True\n"); return 0; }
    Node *l=head,*r=head;
    while(r->next) r=r->next;
    int ok=1;
    while(l!=r && l->prev!=r){
        if(l->c!=r->c){ ok=0; break; }
        l=l->next; r=r->prev;
    }
    printf(ok?"True\n":"False\n");
    return 0;
}
