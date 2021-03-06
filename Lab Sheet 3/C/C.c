#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long int res= 1 , m = 998244353;

long long int gcd(long long int a , long long int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int modexp(long long int a ,long long int b , long long int m){
    long long int r =0;
    a= a%m;
    while(b!=0){
        if(b&1) r=(r+a)%m;
        a = (a*2)%m;
        b/=2;  
    }
    return r;
}

void comb(long long int n ,long long int r){
    if(r<n-r) r = n-r;
    long long int p=1 , k=1;
    if(r){
        while(r){
            p *= n;
            k *= r;
            long long g=  gcd(p,k);
            p/=g;
            k/=g;
            n--;
            r--;
        }
    }
    res = modexp(res , p , m);
}

int main(){
    long long int xs,xe,ys,ye,zs,ze , x, y , z ,total;
    scanf("%d %d %d %d %d %d",&xs,&ys,&zs,&xe,&ye,&ze);
    x = (long long int)abs(xs-xe);
    y = (long long int)abs(ys-ye);
    z = (long long int) abs(zs-ze);
    total = z+x+y;
    if(total-x) comb(total,x);
    total-=x;
    if(total-y) comb(total,y);
    printf("%d ",res);
    return 0; 
}