#include<stdio.h>
#include<stdlib.h>

int arr[3000005] , n , s ,  c ,flag;

int search_middle(int low , int high ){
    if(high<low) return 0;
    if(high==low) return low;
    int mid = low +(high-low)/2;
    if(mid<high && arr[mid]>arr[mid+1]) return mid+1;
    if(mid>low && arr[mid-1]> arr[mid]) return mid;
    if(arr[high] > arr[mid]) return search_middle(low , mid-1);
    return search_middle(mid+1 , high);
}

int binary_search(int low , int high){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==s) return mid;
        else if(arr[mid] > s) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&s);

    int c = search_middle(0 , n-1);
    int a = binary_search(0 , c-1);
    int b = binary_search(c , n-1);

    if(a==-1 && b==-1) printf("NO");
    else if(a==-1)  printf("YES\n%d",c+b);
    else if(b==-1)  printf("YES\n%d",a);
    return 0;
}
