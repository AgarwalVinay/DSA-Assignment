#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[35] , rev[35];
char comm[35];

void toGray(long long int n){
    int pos=0;
    if(n==0) printf("0");
    while(n){
        arr[pos]=n%2;
        n/=2;
        pos++;
    }
    for(int i=pos-1;i>=0;i--)  rev[pos-i-1] = arr[i];
    int flag =0 , p = 0 , v=0; 
    for(int i=0;i<pos;i++){
        v = rev[i];
        if(!flag){
            printf("%d",v);
            p=v;
            flag=1;
        }
        else{
            printf("%d",p^v);
            p=v;
        }
    }
    printf("\n");
}

void toDecimal(int s){
    long long int res = 0, flag =0 , p = 0 , v=0;
    for(int i=0;i<s;i++){
        v = arr[i];
        res<<=1;
        if(!flag){
            res +=v;
            p=v;
            flag=1;
        }
        else{
            res +=(p^v);
            p=p^v;
        }
    }
    printf("%d\n",res);
}

int main(){
    long long int t , n ,c;  
    scanf("%lld ",&t);
    while(t--){
        gets(comm);
        if(comm[0]=='G'){
            n =0;
            for(int i=2;i<strlen(comm);i++) n = n*10+comm[i]-'0';
            toGray(n);
        }
        else{
            c=0;
            for(int i=2;i<strlen(comm);i++) {arr[i-2]=comm[i]-'0'; c++;}
            toDecimal(c);
        }
    }
    return 0;
}