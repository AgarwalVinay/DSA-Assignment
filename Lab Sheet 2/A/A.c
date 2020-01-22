#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int count = 1;
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
	count++;
}

void print(struct Node **headref , struct Node *node , int pos)
{
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
    node= *headref;
    while(pos--){
        printf("%d ",node->data);
        node=node->next;
    }
}

void shiftright(struct Node ** headref , int k){
    struct Node * node = *headref;
    int pos =1;
    while(pos != count-k){
        node=node->next;
        pos++;
    }
    node=node->next;
    print(headref , node , pos);
}

void shiftleft(struct Node ** headref , int k){
    struct Node * node = *headref;
    int pos =1;
    while(pos != k){
        node=node->next;
        pos++;
    }
    node=node->next;//from here code is same
    print(headref , node , pos);
}

int main(){
    struct Node * head = NULL;
    int no,k;
    char dir,c;
    scanf("%d%c",&no,&c);
    while(c==' '){
        append(&head,no);
        scanf("%d%c",&no,&c);
        
    }
    append(&head,no);
    scanf("%d %c",&k,&dir);//space is important here
    
    k=k%count;
    if(dir=='R') shiftright(&head,k);
    else shiftleft(&head , k);
    return 0;
}