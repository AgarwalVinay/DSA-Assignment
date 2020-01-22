#include<stdio.h>
#include<conio.h>


int main(){
    int n , m  , x, y ;
    scanf("%d%d",&n,&m);
    long long int p[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%lld",&p[i][j]);
    scanf("%d%d",&x,&y);
    long long int q[x][y];
    for(int i=0;i<x;i++) for(int j=0;j<y;j++) scanf("%lld",&q[i][j]);
    //inputs complete
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int total = 0;
            for(int k = i;k<x+i;k++){
                if(k>=n) break;
                int flag=  0;
                for(int l = j;l<y+j;l++){
                    if(l>=m) break;
                    if(p[k][l]==q[k-i][l-j]) total++;
                    else {
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(total==x*y) {
                printf("YES\n%d %d",i,j);
                return 0;
            }

        }
    }
    printf("NO");
    return 0;
}