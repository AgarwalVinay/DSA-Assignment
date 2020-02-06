#include<stdio.h>
#include<stdlib.h>

int  n , e ,arr[100005] , ind[100005];

void swap(int * a , int * b){
    int temp = *a ;
    *a = *b;
    *b  = temp;
}

int partition(int low , int high){
    int pivot = arr[high];
    int i = low -1;
    for(int j = low ;j<high;j++){
        if(arr[j] <pivot){
            i++;
            swap(&arr[j] , &arr[i]);
            swap(&ind[j] , &ind[i]);
        }
    }
    swap(&arr[high] , &arr[i+1]);
    swap(&ind[high] , &ind[i+1]);
    return i+1;
}

void quicksort(int low  , int high){
    if(low<high){
        int pi = partition(low,  high);
        quicksort(low , pi-1);
        quicksort(pi+1,high);
    }
}

void sort(int start ,int len){
    for(int i=start;i<=start+len;i++){
        int min = i;
        for(int j=start+1;j<=start+len;j++){
            
            if(ind[min]>ind[j]) min =j;
        }
        if(i==min) break;
        swap(&ind[i] , &ind[min]);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&e);
    for(int i=0;i<n;i++) ind[i] = i+1;
    quicksort(0,n-1);

    //sorting equal terms according to their index
    for(int i=0;i<n;i++){
        int k =0;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]) k++;
        }
        if(k) sort(i , k);
    }
    //applying the main logic of the question
    int sum = 0;
    for(int i=0;i<n;i++){
        if(sum<e) sum+=arr[i];
        else break;
    }
    if(sum<e) printf("NO CHANCE");
    else {
        sum = 0;
        for(int i=0;i<n;i++){
            if(sum<e){
                sum+=arr[i];
                printf("%d ",ind[i]);
            }
            else break;
        }
    }
    
    return 0;
}