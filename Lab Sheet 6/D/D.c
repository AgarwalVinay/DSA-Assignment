#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n  , no , min = INT_MAX;
char command[10];

struct Node{
    int data;
    struct Node * next;
};

void push(struct Node ** headref ,struct Node ** minstack,  int value){
    struct Node * node = (struct Node  *) malloc(sizeof(struct Node));
    struct Node * minnode = (struct Node  *) malloc(sizeof(struct Node));
    node->data = value;
    node->next = *headref;
    *headref =  node;
    min= (min<value ? min : value);
    minnode->data =min;
    minnode->next =*minstack;
    *minstack = minnode;
    printf("OK pushed %d\n",value);
}

void pop(struct Node ** headref,struct Node ** minstack){
    if((*headref)==NULL){
        printf("STACK UNDERFLOW\n");
        return;
    }
    printf("OK popped %d\n",(*headref)->data);
    (*headref) = (*headref)->next;
    (*minstack) = (*minstack)->next;
}

int main(){
    scanf("%d",&n);
    struct  Node * head = NULL ,*minstack = NULL;
    while(n--){
        scanf("%s",command);
        if(command[0]=='p' &&command[1]=='u'){
            scanf("%d",&no);
            push(&head ,&minstack, no );
        }//push
        else if(command[0]=='p' &&command[1]=='o') pop(&head,&minstack); //pop
        else if(command[0]=='p' &&command[1]=='e'){
            if(head!=NULL) printf("%d\n",head->data);
            else printf("STACK UNDERFLOW\n");
        }
        else{
            if(head!=NULL) printf("%d\n",minstack->data);
            else printf("STACK UNDERFLOW\n");
        } // getmin
    }
    return 0;
}