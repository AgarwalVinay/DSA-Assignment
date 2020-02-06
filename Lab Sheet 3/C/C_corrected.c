#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef long long int ll;

ll res1, res2, m = 998244353 , dp[6001][6001] ; 

ll modexp(ll a ,ll b ){
    ll r =0;
    a= a%m;
    while(b!=0){
        if(b&1) r=(r+a)%m;
        a = (a*2)%m;
        b/=2;  
    }
    return r;
}

int main(){
    ll xs,xe,ys,ye,zs,ze , x, y , z ,total;
    scanf("%d %d %d %d %d %d",&xs,&ys,&zs,&xe,&ye,&ze);
    x = (ll)abs(xs-xe);
    y = (ll)abs(ys-ye);
    z = (ll)abs(zs-ze);
    
    total = z+x+y;
    for(int i=0;i<=total;i++){
        for(int j = 0;j<=i ;j++){
            if(i==0 || j==0 || i==j ){ dp[i][j] = 1;continue;}
            if(j==1 || j==i-1) {dp[i][j] = i;continue;}
            dp[i][j] = (dp[i-1][j-1] %m+ dp[i-1][j] %m)%m;
        }

    }
    res1 = dp[x+y+z][x];
    res2 = dp[y+z][y];
    printf("%lld ",modexp(res1, res2));
    return 0; 
}