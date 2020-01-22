#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    long  long int n, res = 0;
    scanf("%lld",&n);
    int flag=0;
    while(!(n%2)){
        n/=2;
        if(!flag){
            flag= 1;
            res = res^2;
        }
    }
    for(int i=3;i<=sqrt(n);i++){
        flag= 0;
        while(!(n%i)){//dont forget to put brakets after !
            n/=i;
            if(!flag){
                flag= 1;
                res = res^i;
            }
        }
    }
    if(n>2){
        res= res^n;
    }
    printf("%lld ",res);
    return 0;
}