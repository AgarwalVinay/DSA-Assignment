#include<stdio.h>
#include<stdlib.h>

int n , m  , arr[100000] , t ,x;

void swap(int *a  ,int *b){
    int temp = *a;
    *a =*b;
    *b= temp;
}

int partition(int arr[] , int low , int high){
    int pivot =arr[high];
    int i= (low-1);
    for(int j =low ;j<high;j++){
        if(arr[j] <pivot){
            i++;
            swap(&arr[i] , &arr[j]);
        }
    }
    swap(&arr[i+1] , &arr[high]);
    return i+1;
}

void quicksort(int arr[] , int low , int high){
    if(low<high){
        int pi = partition(arr ,low , high);
        quicksort(arr ,low , pi-1);
        quicksort(arr , pi+1 , high);
    }
}

int binarysearch(int x){
    int low = 0 , high = m-1 , ans = 0;
    while(low<=high){
        int mid= low + (high-low)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid]>x) high = mid-1;
        else{
            low =mid+1;
            ans =mid;
        }
    }
    return ans;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d",&arr[i]);
    quicksort(arr , 0 , m-1);
    arr[m]=INT_MAX;
    printf("\n");
    scanf("%d",&t);
    while(t--){
       scanf("%d",&x); 
       int q= binarysearch(x);
       if(arr[q]==x) printf("0\n");
       else {
           int a = x-arr[q];
           int b= arr[q+1] -x;
           int min = a<b?a:b;
           printf("%d\n",min);
       }
    }
    return 0;
}