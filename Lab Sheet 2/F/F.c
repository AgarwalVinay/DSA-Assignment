#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>

struct Node{
    int data;
    struct Node *next , *prev;
};

void append(struct Node ** headref ,int value){
	struct Node *node = (struct Node* ) malloc(sizeof(struct Node)) , *last = *headref ;
    node->data =value;
    node->next = NULL;
    if(*headref ==NULL){
    	node->prev= NULL;
    	*headref = node;
    	return;
	}
	while(last->next!=NULL){
		last = last->next;
	}
	last->next = node;
	node->prev= last;
}

void printlist(struct Node** headref){
    struct Node * node = *headref;
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}

void merge(struct Node ** first , struct Node ** second){
    if((*first)==NULL){
        printlist(second);
        return ;
    }
    if((*second)==NULL) {
        printlist(first);
        return ;
    }
    struct Node *p1 =*first , *p2 = *second,*result =NULL;

    while(p1!=NULL || p2!=NULL){
        int a=INT_MAX ,b=INT_MAX;
        if(p1!=NULL) a=p1->data;
        if(p2!=NULL) b=p2->data;
        if(a>b){ 
            append(&result , b);
            if(p2!=NULL) p2=p2->next; //just move p2 here
        }
        else {
            append(&result,a);
            if(p1!=NULL) p1=p1->next;//just move p1 here
        }
    }
    printlist(&result);
}

int main(){
    struct Node * head1 = NULL , *head2 = NULL;
    int no,k;
    char c;
    scanf("%d%c",&no,&c);
    while(c==' '){
        append(&head1,no);
        scanf("%d%c",&no,&c);    
    }
    append(&head1,no);

    scanf("%d%c",&no,&c);
    while(c==' '){
        append(&head2,no);
        scanf("%d%c",&no,&c);   
    }
    append(&head2,no);
    merge(&head1 , &head2);
    return 0;
}