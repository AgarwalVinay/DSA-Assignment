#include<stdio.h>
#include<stdlib.h>

int merge(int arr[] , int l , int  m , int r){
    int i , j , k , inv_count =0;
    int n1 = m-l+1;
    int n2 = r-m;
    
    int L[n1] , R[n2];
    for(i=0;i<n1;i++) L[i] = arr[i+l];
    for(j=0;j<n2;j++) R[j] = arr[j+m+1];

    i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 

    while(i<n1 && j<n2){
        if(L[i] <=R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
            inv_count +=(m-i-l+1);//this part is important
        }
    }

    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++]  = R[j++];
    return inv_count;
}

int  mergesort(int arr[] , int l , int r){
    int inv_count =0;
    if(l<r){
        int m = l+(r-l)/2;
        inv_count+=mergesort(arr , l , m );
        inv_count+=mergesort(arr , m+1, r);
        inv_count+=merge(arr , l  , m  , r);
    }
    return inv_count;
}

int main(){
    int  n ,arr[200005] ,i;//dont make it global
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("%d\n",mergesort(arr , 0 , n-1));
    // for(i=0;i<n;i++) printf("%d ",arr[i]);
    return  0;
}