#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct Node{
    int data;
    struct Node * next;
};

void push(struct Node ** headref  , int value){
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node->data = value;
    node->next= *headref;
    *headref = node;
}

void printlist(struct Node ** headref){
    struct Node * node = *headref;
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void deleterepeat(struct Node ** head1ref , struct Node ** head2ref){
    int prev =0 , count = 0;
    struct Node *a = *head1ref , *b=NULL;
    while(a!=NULL){
        if(prev!=a->data){
            prev =a->data;
            b = (struct Node*) malloc(sizeof(struct Node));
            b->data =prev;
            count++;
            b->next = *head2ref;
            *head2ref = b;
        }
        a=a->next;
    }
    printf("%d\n",count);
}

int main(){
    int no , prev ;
    struct Node * head1 = NULL , * head2 = NULL;
    char c;
    scanf("%d%c",&no,&c);
    while(c==' '){
        push(&head1 , no);
        scanf("%d%c",&no,&c);        
    }
    push(&head1 , no);
    deleterepeat(&head1 , &head2);
    printlist(&head2);
    return 0;
}
