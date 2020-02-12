#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef long long int ll;

ll arr[300005] , sum = 0 , mod = 1000000007 , count[33];

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=0;i<n;i++) scanf("%lld",&arr[i]);
    for(int i=0;i<n;i++){
        for(int  j=0;j<32;j++){
            if(arr[i] & (1<<j)) count[j]++;
        }
    }
    for(int i= 0;i<32;i++) sum =(sum+ count[i] * (n-count[i])*2 )%mod;
    printf("%lld",sum);
    return 0;
}