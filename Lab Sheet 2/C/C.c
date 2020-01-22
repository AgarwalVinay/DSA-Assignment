#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node * next;
};

void append(struct Node ** headref , int value){
    struct Node * node = (struct Node *)malloc(sizeof(struct Node)) , *last = *headref;
    node->data =value;
    node->next =NULL;
    if(*headref==NULL){
        *headref = node;
        return;
    }
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = node;
    return ;
}


void reverse(struct Node ** headref){
    struct Node *prev =NULL , * curr = *headref , *succ = NULL;
    while(curr!=NULL){
        succ =curr->next;
        curr->next = prev;
        prev = curr;
        curr=succ;
    }
    *headref=prev;
}

void printlist(struct Node ** headref){
    struct Node * node=  * headref;
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void fetch(struct Node ** headref , int value){
    int count =1;
    struct Node * node =*headref;
    while(count<value){
        node=node->next;
        count++;
    }
    printf("%d\n",node->data);
}

void insert(struct Node ** headref ,int value , int pos){
    struct Node * prev =NULL  , *curr =  *headref , *node = (struct Node *)malloc(sizeof(struct Node));
    node->data  = value;
    if(pos==1){
        node->next = *headref;
        *headref = node;
    }
    else{
        int count = 1;
        while(count<pos){
            prev = curr;
            curr=curr->next;
            count++;
            
        }
        prev->next = node;
        node->next=curr;
    }
}

void removing(struct Node ** headref  , int value){
    struct Node * fp=NULL , *fc=*headref, *lc=*headref, *lp=NULL,*succ=NULL, *sp=NULL;
    while(fc!=NULL){
        if(fc->data==value){
            break;
        }
        fp=fc;
        fc=fc->next;
    }
    if(fc==NULL){
        printf("Element not found\n");
        return ;
    }
    succ = fc;
    lc=fc;
    lp = fp;
    sp=fp;
    while(succ!=NULL){
        if(succ->data ==value){
            lc=succ;
            lp=sp;
        }
        sp=succ;
        succ = succ->next;
    }
    
    if(lp==fp){
        fp->next = fc->next;
        fp=fc;
        fc=fc->next; 
        fp->next = NULL;
    }
    else {
        fp->next = fc->next;
        fp=fc;
        fc=fc->next; 
        fp->next = NULL;
        lp->next = lc->next;
        lp=lc;
        lc=lc->next; 
        lp->next = NULL;
    }
    printlist(headref);
}


int main(){
    int n,no;
    struct Node *head= NULL;
    scanf("%d",&n);
    while(n--){
        char str[10];
        scanf("%s",str);
        if(str[0]=='a') {
            scanf("%d",&no);
            append(&head , no);
            printlist(&head);
        }
        else if(str[0]=='i'){
            int pos;
            scanf("%d %d",&no,&pos);
            insert(&head ,no  ,pos);
            printlist(&head);
        }
        else if(str[0]=='f'){
            scanf("%d",&no); 
            fetch(&head,no);
        }
        else if(str[0]=='r' && str[2]=='v'){
            reverse(&head);
            printlist(&head);
        }
        else if(str[0]=='r'&& str[2]=='m'){
            scanf("%d",&no);
            removing(&head , no);
        }
    }
    return 0;
}
