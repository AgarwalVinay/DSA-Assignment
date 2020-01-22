#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<limits.h>

int node, edge , adj[501][501] ,visited[501],a,b,c;

void dfs(int n){
    visited[n]=1;
    for(int i=1;i<=node;i++){
        if(adj[n][i]==1 && !visited[i]) dfs(i);
    }
}

int main(){
    scanf("%d%d",&node,&edge);
    for(int i =0;i<edge;i++) {//be careful in i and j here
        scanf("%d%d",&a,&b);
        adj[a][b]=1;
    }
    for(int i=1;i<=node;i++){
        for(int j=1;j<=node;j++) visited[j] = 0;
        dfs(i);//i will come here
        int count=0;
        for(int j=1;j<=node;j++) {
            count+=visited[j];
        }
        if(count==node){
            printf("%d",i);
            return 0;
        }
    }
    printf("BAD LUCK");
    return 0;
}