#include<stdio.h>
#include<stdlib.h>

int count;

struct Node{
    int data;
    struct Node * next;
};

void printlist(struct Node ** headref){
    struct Node * node = *headref;
    while(node !=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void append(struct Node ** headref , int value){
    struct Node * node =(struct Node *)malloc(sizeof(struct Node)) , *last = *headref;
    node->data = value;
    node->next = NULL;
    count++;
    if(*headref ==NULL){
        *headref = node;
        return ;
    }
    while(last->next !=NULL) last = last->next;
    last->next = node;
}

void spiral(struct Node ** headref){
    struct Node * first=*headref , * fn=NULL , * last=*headref , *lp=*headref;
    if(count == 1 || count == 2) return;
    //positioning the pointers
    while(last->next !=NULL ) last=last->next;
    while(lp->next !=last) lp=lp->next;
    //dont move headptr
    
    while(last !=first && count){
        fn = first->next;
        first->next= last;
        first = fn;
        fn =  fn->next;
        count--;
        if(!count || count==1) break;//important condition , is no more actions are required or just one is required then no use of performing any action
        count--;
        last->next =first;
        last= lp;
        lp= first;
        while(lp->next !=last) lp=lp->next;
    }
    last->next =NULL;

}

int main(){
    char c;
    int no;
    struct Node * head = NULL;
    scanf("%d%c",&no,&c);
    while(c==' '){
        append(&head , no);
        scanf("%d%c",&no,&c);
    }
    append(&head , no);
    spiral(&head);
    printlist(&head);
    return 0;
}