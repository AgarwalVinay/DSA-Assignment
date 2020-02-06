#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int count =0 , adj[1001][1001] , visited[1001] , connects[1001] , n , m , a, b, r;

void dfs(int b , int z){
    visited[z] = 1;
    for(int i=0;i<n;i++){
        if(adj[z][i] && !visited[i] && i!=b) dfs(b , i);
    }
    count++;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        adj[a][b]=1;
        adj[b][a]=1;
    }
    scanf("%d",&r);

    for(int i=0;i<n;i++){
        for(int i=0;i<n;i++) visited[i] =0;
        count=0;
        dfs(i , r);
        connects[i] = count;
    }
    int min =INT_MAX , index = 0;
    for(int i=0;i<n;i++){
        if(connects[i] <min && i!=r){
            min = connects[i];
            index =i;
        }
    }
    if(min==n-1)printf("BLACK OUT");
    else printf("%d",index);
    return 0;
}