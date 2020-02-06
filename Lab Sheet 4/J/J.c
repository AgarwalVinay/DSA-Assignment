#include<stdio.h>
#include<stdlib.h>
typedef long long int ll ;
//O(T.log(n))
ll t ,n , arr[1001] , c;

ll floorroot(ll x){
    if(x==0 || x==1) return x;
    ll start = 1 , end = x , ans = 0;
    while(start<=end){
        ll mid = (start+end)/2;
        if(mid*mid == x){
            return mid;// we found the ans here
        }
        else if(mid*mid<x){
            start = mid+1;
            ans =mid;// start from mid +1 and ans must be atleast mid // note we have not updated mid here
        }
        else end =mid-1;//change ending to mid-1
    }
    return ans;
}

int main(){
    scanf("%lld ",&t);
    c=0;
    while(c<t){
        scanf("%lld ",&n);
        arr[c++] = floorroot(n);
    }
    for(int i=0;i<c;i++) printf("%lld\n",arr[i]);
}