#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef long long int ll;

int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        char s[2];
        scanf("%s",s);
        if(s[0]=='G'){
            ll n;
            scanf("%lld",&n);
            int k = n^(n>>1);
            if(!k) printf("0");
            else{
                ll bin[32]={0} ,pos = 0;
                while(k){
                    bin[pos] = k%2;
                    pos++;
                    k/=2;
                }
                for(int i=pos-1;i>=0;i--) printf("%lld",bin[i]);
            }
        }
        else{
            char bin[32] , dec[32];
            scanf("%s",bin);
            ll len = strlen(bin) , n=0;
            dec[0] = bin[0];
            for(int i=1;i<len;i++){
                if(dec[i-1]==bin[i]) dec[i] = '0';
                else dec[i] = '1';
            }
            for(int i=0;i<len;i++){
                if(dec[i]=='1') n+= 1<<(len-i-1);
            }
            printf("%lld",n);
        }
        printf("\n");
    }
}