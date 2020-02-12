#include<stdio.h>
#include<stdlib.h>

int  n ,a,b , adj[1501][1501] , visited[1500] ,distance0[1501], distance[1501] , u , v , leaf[1501] , vf=INT_MIN, uf =INT_MAX ,maxf =INT_MIN;

void dfs(int x , int count  , int p){
    visited[x] =1;
    int k=0;
    if(!p) distance0[x] = count;
    else distance[x] = count;
    for(int i=0;i<n;i++){
        if(adj[x][i]){ k++; if(!visited[i]) dfs(i ,count+1 ,p);}
    }
    if(k==1) leaf[x] =1;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adj[a][b] =1;
        adj[b][a] =1;
    }
    dfs(0 , 0 , 0);
    for(int j=0;j<n;j++){
        if(leaf[j]){
            for(int i=0;i<n;i++) visited[i] =0;
            u = j;
            dfs(u , 0 , 1);
            int max =INT_MIN;
            for(int i=0;i<n;i++){
                if(max<=distance[i]) {
                    max =distance[i];
                    v = i;
                }
            }
            if((u <uf) || ((u==uf) && (v>vf)) || (max>maxf) ){
                maxf= max;
                uf = u;
                vf= v;
            }
    }}
    printf("%d\n%d %d",maxf,uf,vf);
    return 0;
}
