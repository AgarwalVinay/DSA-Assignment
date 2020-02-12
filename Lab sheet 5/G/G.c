#include<stdio.h>
#include<stdlib.h>
int  k, n;//n is the length

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<(1<<n);i++){
        if( (i & k) == k){//here brakets are important
            int temp = i ,j=0;
            int arr[16]={0};
            while(temp){
                arr[j++]=temp%2;
                temp/=2;
            }
            for(int x=n-1;x>=0;x--) printf("%d",arr[x]);
            printf("\n");
        }
    }
    return 0;
}