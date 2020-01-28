#include<stdio.h>
#include<stdlib.h>

int adj[1001][1001] , visited[1001] , isGym[1001] , n , distance[1001];

void dfs(int no , int pos){
    visited[no]= 1;
    distance[no]=pos;
    int count=0;
    for(int i=0;i<n;i++){
        if(adj[no][i]){
            count++;
            if(!visited[i]) dfs(i,pos+1);
        } 
    }
    if(count==1) isGym[no]=1;
    // printf("hello %d\n",no);
}

int main(){
    int a,b;
    scanf("%d",&n);

    if(n==1){//to meet extreme case condition
        printf("1\n0");
        return 0;
    }

    for(int i=0;i<n-1;i++){
        scanf("%d %d", &a,&b);
        adj[a][b]=1;
        adj[b][a]=1;
    }
    dfs(0,0);
    int min = INT_MAX , index =0 , count=0;
    for(int i=0;i<n;i++){
        if(isGym[i]){
            if(distance[i]< min){
                min = distance[i];
                index = i;
            }
            if(distance[i]==min && index>i) index =i;
        }
    }

    for(int i=0;i<n;i++) if(isGym[i] && distance[i]==min) count++;
    printf("%d\n%d",count,index);
    return 0;
}