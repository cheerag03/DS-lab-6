#include <stdio.h>
#include <stdlib.h>

typedef struct CNode{ int data; struct CNode *next; } CNode;

CNode* create(int x){ CNode* p=malloc(sizeof(CNode)); p->data=x; p->next=NULL; return p; }

void insert_first(CNode** tail,int x){
    CNode* p=create(x);
    if(!*tail){ *tail=p; p->next=p; return; }
    p->next = (*tail)->next;
    (*tail)->next = p;
}
void insert_last(CNode** tail,int x){
    insert_first(tail,x);
    *tail = (*tail)->next;
}
void insert_after(CNode** tail,int val,int x){
    if(!*tail) return;
    CNode* cur = (*tail)->next;
    do{
        if(cur->data==val){
            CNode* p=create(x);
            p->next=cur->next;
            cur->next=p;
            if(cur==*tail) *tail = p;
            return;
        }
        cur=cur->next;
    } while(cur!=(*tail)->next);
}
void insert_before(CNode** tail,int val,int x){
    if(!*tail) return;
    CNode* cur=(*tail)->next, *prev=*tail;
    do{
        if(cur->data==val){
            CNode* p=create(x);
            p->next=cur;
            prev->next=p;
            if(cur==(*tail)->next) (*tail)->next=p;
            return;
        }
        prev=cur;
        cur=cur->next;
    } while(cur!=(*tail)->next);
}
int delete_val(CNode** tail,int val){
    if(!*tail) return 0;
    CNode *cur=(*tail)->next, *prev=*tail;
    do{
        if(cur->data==val){
            if(cur==prev){ free(cur); *tail=NULL; return 1; }
            prev->next=cur->next;
            if(cur==*tail) *tail=prev;
            free(cur);
            return 1;
        }
        prev=cur;
        cur=cur->next;
    } while(cur!=(*tail)->next);
    return 0;
}
int search(CNode* tail,int val){
    if(!tail) return -1;
    CNode* cur=tail->next; int pos=1;
    do{ if(cur->data==val) return pos; pos++; cur=cur->next; } while(cur!=tail->next);
    return -1;
}
void display(CNode* tail){
    if(!tail){ printf("Empty\n"); return; }
    CNode* cur = tail->next;
    do{ printf("%d ",cur->data); cur=cur->next; } while(cur!=tail->next);
    printf("%d\n", tail->next->data);
}

int main(){
    CNode* tail=NULL;
    int ch,a,b;
    while(scanf("%d",&ch)==1){
        if(ch==1){ scanf("%d",&a); insert_first(&tail,a); }
        else if(ch==2){ scanf("%d",&a); insert_last(&tail,a); }
        else if(ch==3){ scanf("%d %d",&a,&b); insert_after(&tail,a,b); }
        else if(ch==4){ scanf("%d %d",&a,&b); insert_before(&tail,a,b); }
        else if(ch==5){ scanf("%d",&a); printf("%d\n", delete_val(&tail,a)); }
        else if(ch==6){ scanf("%d",&a); printf("%d\n", search(tail,a)); }
        else if(ch==7){ display(tail); }
        else break;
    }
    return 0;
}
