//sorting big numbers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int len;
    char str[52];
};

struct Node * arr[100005];

void swap(struct Node *a ,struct Node *b){
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

int compare( struct Node *a ,struct Node *b){
    int len1 , len2 , s1=0 , s2=0;
    
    if(a->str[0]=='-') {len1 = a->len -1;s1 =1;}
    else len1 = a->len;

    if(b->str[0]=='-') {len2 = b->len -1; s2 =1;}
    else len2 = b->len;

    if(s1==0 && s2==0){
        if(len1 <len2) return 1;
        if(len1 > len2) return 0; 
        for(int i=0;i<len1;i++){
            if((a->str[i]) < (b->str[i])) return 1;
            else if((a->str[i]) > (b->str[i])) return 0;
        }
        return 0;   
    }
    else if(s1 && !s2) return 1;
    else if(!s1 && s2) return 0;

    if(len1 <len2) return 0;
    if(len1 > len2) return 1;
    for(int i=0;i<len1;i++){
        if(a->str[1+i] > b->str[i+1]) return 1;
        else if((a->str[1+i]) < (b->str[1+i])) return 0;
    }
    return 0;
}

int partition(int low , int high){
    struct Node * pivot = arr[high];
    int i = low - 1;
    for(int j=low ; j<high;j++){
        if(compare(arr[j] , pivot)){ // equivalent arr[j]<pivot;
            i++;
            swap(arr[j] , arr[i]);
        }
    }
    swap(arr[high] , arr[i+1]);
    return i+1;
}

void quicksort(int low ,int high){
    if(low<high){
        int pi = partition(low , high);
        quicksort(low , pi-1);
        quicksort(pi+1 , high);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        arr[i] = (struct Node *) malloc(sizeof(struct Node));
        scanf("%s",(arr[i])->str);
        (arr[i])->len = strlen((arr[i])->str);
    }
    quicksort(0,n-1);
    for(int i=n-1;i>=0;i--){
        printf("%s\n",arr[i]->str);
    }
    return 0;
}