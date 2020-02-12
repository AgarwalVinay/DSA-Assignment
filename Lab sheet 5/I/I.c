//https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
#include<stdio.h>
#include<stdlib.h>

int arr[1000000] , k;

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
    scanf("%d",&k);
    quicksort(0 , n-1);

    int l=0 , r = n-1 , p1=0, q1=0;
    while(l<r){
        if(arr[l]+arr[r]==k){
            p1= arr[l];
            q1 = arr[r];
            l++;
        }
        else if(arr[l] + arr[r]<k) l++;
        else r--; 
    }
    if(!p1 && !q1) printf("NO");
    else {
        printf("YES\n%d %d",p1, q1);
    }
    return 0;
}