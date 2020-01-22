#include<stdio.h>
#include<conio.h>
#include<math.h>

long long isPrime[1000001] ,  num[1000001] , count[10];

int main(){
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    isPrime[0] = 0; isPrime[1] = 0;
    for(long long int i=2;i<=1000000;i++) isPrime[i]= 1;
    
    for(long long int i=2;i<=1000000;i++){
        if(isPrime[i]){
            for(long long int j = i*i;j<=1000000;j+=i) isPrime[j] = 0;
        }
    }
    long long len = b-a+1;
    for(long long int i= 0;i<len;i++) num[i] = 1;

    for(long long int i=2;i<=1000000;i++){
        if(isPrime[i]){
            for(long long int j = ((a-1)/i+1)*i ; j<=b;j+=i){
                if(j!=i) num[j-a] = 0;
            }
        }
    }
    for(long long int i=0;i<len;i++){
        if(num[i]){
            long long int c = a+i;
            while(c){
                count[c%10]++;
                c/=10;
            }
        }
    }
    long long int max = count[0], no=0;
    for(int i=1;i<=9;i++){
        if(max<count[i]){ max = count[i]; no = i;}
    }
    printf("%lld %lld",no , max);
    return 0;
}