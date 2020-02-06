#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void printlist(struct Node ** headref){
    struct Node * node= *headref;
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void append(struct Node ** headref , int value){
    struct Node * node = (struct Node *) malloc(sizeof(struct Node)) , *last =*headref;
    node->data  = value;
    node->next = NULL;
    if(*headref == NULL){
        *headref = node;
        return ;
    }
    while(last->next !=NULL) last = last->next;
    last->next = node;
}

struct Node* SortedMerge(struct Node **heada , struct Node **headb){
    struct Node * result = NULL , *a = *heada,*b = *headb;
    if(a==NULL) return b;
    if(b==NULL) return a;
    
    if(a->data <=b->data){
        result = a;
        result ->next = SortedMerge(&(a->next) , &b);
    }
    else {
        result = b;
        result->next = SortedMerge(&a , &(b->next));
    }
    return result;
}

void FrontBackSplit(struct Node *source , struct Node ** frontref , struct Node ** backref){
    struct Node *fast =source->next , *slow = source;
    
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontref =source;
    *backref =slow->next;
    slow->next =NULL;
}

void MergeSort(struct Node ** headref){
    struct Node *a , *b;
    if((*headref==NULL)|| ((*headref)->next ==NULL)) return ;

    FrontBackSplit(*headref , &a ,&b);
    MergeSort(&a);
    MergeSort(&b);
    *headref  = SortedMerge(&a,&b);
}

int main(){
    struct Node * head = NULL;
    int no ;
    char c;
    scanf("%d%c",&no,&c);
    while(c==' '){
        append(&head , no);
        scanf("%d%c",&no,&c);
    }
    append(&head , no);
    MergeSort(&head);
    printlist(&head);
    return 0;
}