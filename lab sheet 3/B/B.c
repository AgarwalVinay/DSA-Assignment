#include<stdio.h>
#include<stdlib.h>
// brute force approach
int arr[1000001] , n;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++){
        long long int a = i , count=1;
        while(a!=1){
            if(a&1) a = 3*a+1;
            else a/=2;
            count++;
        }
        arr[i] = count;
    }
    int max=0 ,index =0;
    for(int i=1;i<=n;i++) {
        if(max<=arr[i]){
            max = arr[i];
            index=  i;
        }
    }
    printf("%d %d",index, max);
}