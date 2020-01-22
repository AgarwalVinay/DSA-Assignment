#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int nn,a,b,c,d,e,f,l,m,n,x;
int result[1000001];

int main(){
    scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&nn);
    for(int i=1;i<=1000000;i++) result[i] = -1;//start it form 1 onwards
    for(int i=1;i<=1000000;i++){//start it form 1 onwards
        l=INT_MAX,m=INT_MAX,n=INT_MAX;
        if(a!=0 && (i-b)%a==0 && result[(i-b)/a]!=-1 && (i-b)/a>=0 ) l = result[(i-b)/a]+1;
        if(c!=0 && (i-d)%c==0 && result[(i-d)/c]!=-1 && (i-d)/c>=0 ) m = result[(i-d)/c]+1;
        if(e!=0 && (i-f)%e==0 && result[(i-f)/e]!=-1 && (i-f)/e>=0 ) n = result[(i-f)/e]+1;
        int min= (l>m?(m>n?n:m):(l>n?n:l));//dont type a ,  b,  c here :p
        if(min==INT_MAX) continue;
        result[i]=min;
    }
    while(nn--){
        scanf("%d",&x);
        printf("%d\n",result[x]);
    }
    return 0;
}