#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<limits.h>

int adj[501][501] , visited[501] , count[501] , pos[501];
int node ,edges,a,b,c;

void dfs(int n , int c){
    count[c]++;
    pos[n] = c;
    visited[n] =1;
    for(int i=1;i<=node;i++){
        if(adj[n][i]==1 && !visited[i]) dfs(i,c);
    }
}

int main(){
    c=1;
    scanf("%d%d",&node,&edges);
    for(int i=0;i<edges;i++){
        scanf("%d%d",&a,&b);
        adj[a][b]=1;
        adj[b][a]=1;
    }
    for(int i=1;i<=node;i++){
        if(!visited[i]) {dfs(i,c);c++;}
    }
    int max_no =1 ,max = count[1];
    for(int i=2;i<=node;i++){
        if(max<count[i]){
            max = count[i];
            max_no = i;
        }
    }
    int flag=0;
    if(node-max) printf("%d\n",node-max);
    for(int i=1;i<=node;i++){
        if(pos[i]!=max_no){ printf("%d ",i);flag=1;}
    }
    if(!flag) printf("-1");//important , dont forget this part
    return 0;
}