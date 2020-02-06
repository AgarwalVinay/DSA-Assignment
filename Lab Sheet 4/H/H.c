#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;

ll arr[1000005] , sum[1000005] ,n ,m  , l , r , x ;

int main(){
    scanf("%lld %lld",&n,&m);
    for(ll i=0;i<m;i++){
        scanf("%lld %lld %lld",&l,&r,&x);
        sum[l] += x;
        sum[r+1]+= (-x);
    }
    ll p = 0;
    for(ll i=0;i<n;i++){
        p+=sum[i];
        printf("%lld ",p);
    }
    return 0;
}