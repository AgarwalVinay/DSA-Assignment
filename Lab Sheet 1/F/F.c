#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void push(struct Node ** head_ref ,  int value){
    struct Node* node = (struct Node * )malloc(sizeof(struct Node));
    node->data = value;
    node->next = *head_ref;
    *head_ref = node;
}

void printlist(struct Node ** head_ref){
    struct Node* node = *head_ref;
    while(node!=NULL){
        printf("%d",node->data);
        node= node->next;
    }
    printf("\n");
}

void add(struct Node ** head1 , struct Node ** head2  , struct Node ** res){
    int carry = 0;
    struct Node *a=*head1 , *b=*head2 ;
    while(a!=NULL || b!=NULL){
        struct Node *c = (struct Node *) malloc(sizeof(struct Node));
        c->data  = (a!=NULL?a->data:0) + (b!=NULL?b->data:0) + carry;
        carry =  (c->data>=2)?1:0;
        c->data -=carry*2;
        c->next = *res;
        *res = c;
        if(a!=NULL) a=a->next;
        if(b!=NULL) b=b->next;
    }
    if(carry){
        // struct Node* node = (struct Node * )malloc(sizeof(struct Node));
        // node->data = 1;
        // node->next = *res;
        // *res = node;
        push(res , 1);//both formats will work
    }
}

int i;
char str1[1000001],str2[1000001];
int main(){
    gets(str1);
    gets(str2);
    struct Node * head1 = NULL ,*head2  = NULL , * res = NULL;
    for(i=0;i<strlen(str1);i++) push(&head1 , str1[i]-48);
    for(i=0;i<strlen(str2);i++) push(&head2 , str2[i]-48);
    add(&head1 , &head2 , &res);
    printlist(&res);
    return 0;
}
