#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node * next;
}

void append(struct Node ** node , int value){
    struct Node * node = (struct Node *)malloc(sizeof(struct Node)) , *last = *headref;
    node->data =value;
    node->next =NULL;
    if(last==NULL){
        *headref = node;
        return;
    }
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = node;
}


void reverse(struct Node ** headref){
    struct Node *head = NULL,**headptr =&head , *node= *headref , *a; 
    while(node!=NULL){
        a=(struct Node *) malloc(sizeof(struct Node ));
        a->data =node->data;
        a->next = head;
        head = node;
    }
    headptr=&head;
    *headref = *headptr;
}

void printlist(struct Node ** headref){
    struct Node * node=  * headref;
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}


int main(){
    int n,no;
    struct Node *head= NULL;
    scanf("%d",&n);
    while(n--){
        char str[10];
        scanf("%s %d",str,&no);
        fflush(stdin);
        if(str[0]=='a') {append(&head , no);}
        else if(str[0]=='i');
        else if(str[0]=='f');
        else if(str[0]=='r' && str[2]=='v');reverse(&head);
        else if(str[0]=='r'&& str[2]=='m');//remove
    }
    return 0;
}