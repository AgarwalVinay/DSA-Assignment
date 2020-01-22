#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int node ,a , l , distance[1001] , adj[1001][1001] ,visited[1001];

void dfs(int n , int level){
    visited[n]=1;
    distance[n]=level;
    for(int i=0;i<node;i++){
        if(adj[n][i] && !visited[i] ){
            dfs(i , level+1);
        }
    }
}

int main(){
    scanf("%d",&node);
    for(int i=1;i<=node-1;i++){
        scanf("%d",&a);
        adj[i][a]=1;
        adj[a][i]=1;
    }
    scanf("%d",&l);
    dfs(0,0);
    int count =0;
    for(int i=0;i<node;i++) if(distance[i]==l) count++;
    
    if(!count) printf("-1");
    else{
        printf("%d\n",count);
        for(int i=0;i<node;i++) if(distance[i]==l) printf("%d ",i);}
    return 0;
}