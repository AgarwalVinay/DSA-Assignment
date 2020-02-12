#include<stdio.h>
#include<stdlib.h>

int adj[1001][1001] , n , m  , a, b , visited[1001] , pos ,postorder[1001] , recurrsionstack[1001];

void dfs(int x){
    visited[x]=1;
    for(int i=1;i<=n;i++){
        if(!visited[i] && adj[x][i]) dfs(i);
    }
    postorder[pos++] = x; 
}

int cycle_check(int x){
    visited[x] = 1;
    recurrsionstack[x] = 1;
    for(int i=1;i<=n;i++){
        if(adj[x][i]){
            if(!visited[i] && cycle_check(i)) return 1;
            else if(recurrsionstack[i] && visited[i]) return 1;
        }
    }
    recurrsionstack[x] = 0;
    return 0;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d %d",&a, &b);
        adj[b][a] =1;
    }

    //check cycles as well
    for(int i=1;i<=n;i++){
        if(!visited[i]) {
            if(cycle_check(i)){
                printf("NOT POSSIBLE");
                return 0;
            }       
        }
    }
    for(int i=1;i<=n;i++) visited[i] =0;
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs(i);
    }

    for(int i=pos-1;i>=0;i--) printf("%d ",postorder[i]);
    return 0;
}