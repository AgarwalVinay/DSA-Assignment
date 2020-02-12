#include<stdio.h>
#include<stdlib.h>

int arr[1000][1000];

int main(){
    int n , m , flag =0 , x;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ 
            scanf("%d",&arr[i][j]);
        }
    }
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==x){
                n = i;
                m =j;
                flag =1;
                break;
            }
        }
    }
    if(flag) printf("YES\n%d %d",n,m);
    else printf("MISSING");
    return 0;
}