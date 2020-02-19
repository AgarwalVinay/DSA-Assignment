#include<stdio.h>
#include<stdlib.h>

int adj[1000][1000] ,degree[1000] , w[1000][1000] , a,b,d,n ,ans[1005] ,stack[1005] , dog[1005] ,curr , ts=-1 ,ta=-1 , p , k , visited[1005] ,i;

int cmp (const void * p1 ,const void * p2){
    return (*(int *)p1 - *(int *)p2 );
}

int main(){
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d %d %d",&a,&b,&d);
        adj[a][b]=1;
        adj[b][a]=1;
        degree[a]++;
        degree[b]++;
        w[a][b]+=d;
        w[b][a]+=d;
    }
    scanf("%d %d",&p,&k);
    stack[++ts] =p;
    while(ts!=-1){
        curr = stack[ts--];
        visited[curr] =1;
        if(degree[curr]==1 && dog[curr]<k){
            ans[++ta] = curr;
        }
        for( i=0;i<n;i++){
            if(adj[curr][i] && !visited[i]){
                stack[++ts] = i;
                dog[i] = dog[curr] + w[curr][i];
            }
        }
    }
    qsort(ans , ta +1, sizeof(int) ,cmp);
    for(i =0;i<=ta;i++) printf("%d ",ans[i]);
    return 0;
}
