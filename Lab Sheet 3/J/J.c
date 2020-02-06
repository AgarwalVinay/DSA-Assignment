#include<stdio.h>
#include<stdlib.h>

int mat[501][501] , n , m , p1 ,q1 ,p2 ,q2 , visited[501][501] , flag=0;

int check(int x , int y){
    if(x>=0 && y>=0 && x<n && y<m) return 1;
    return 0;
}

void dfs(int x ,int y){
    visited[x][y] =1;
    if(x == p2 && y == q2){
        flag =1;
        return;
    }
    int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    for(int i =0;i<4;i++){
        int newx = x + dir[i][0];
        int newy = y + dir[i][1];
        if(check(newx, newy) && !visited[newx][newy] && mat[newx][newy]){
            dfs(newx, newy);
        }
        if(flag) return ;
    }

}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) for(int j = 0 ;j<m;j++) scanf("%d",&mat[i][j]);
    scanf("%d %d",&p1,&q1);
    scanf("%d %d",&p2,&q2);

    dfs(p1,q1);
    if(flag) printf("YES");
    else printf("NO");
    return 0;
}