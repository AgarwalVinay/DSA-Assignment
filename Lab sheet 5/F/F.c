#include<stdio.h>
#include<stdlib.h>

int arr[1000000] , a , sum;

void swap(int * a ,int *b){
    int temp  =*a;
    *a = *b;
    *b = temp;
}

int partition(int low , int high){
    int pivot = arr[high] ;
    int i = low -1;
    for(int j=low ;j<high;j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i] , &arr[j]);
        }
    }
    swap(&arr[i+1] , &arr[high]);
    return i+1;
}

void quicksort(int low , int high){
    if(low<high){
        int pi = partition(low , high);
        quicksort(low , pi-1);
        quicksort(pi+1 , high);
    }
}

int main(){
    int n ;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    quicksort(0 , n-1);
    int p = arr[0]-1;
    for(int i=0;i<n;i++){
        if(p!=arr[i]){
            a++;
            p=arr[i];
        }
        sum+=a;
    }
    printf("%d",sum);
    return 0;
}