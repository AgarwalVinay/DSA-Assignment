#include<stdio.h>
int p[100000][3];
int que[10000][4];
int removed[10000];
int start,end,n,t,sum;
int path[100000],l;
int pushall(int currtime)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(currtime>=p[i][1]&&removed[i]!=1)
        {
            printf("pushing %d time %d\n",p[i][0],p[i][2]);
            que[end][0]=p[i][0];
            que[end][1]=p[i][1];
            que[end][2]=p[i][2];
            que[end][3]=p[i][2];
            removed[i]=1;
            sum++;
            end++;
            ans++;
        }
    }
    return ans;
}
void push(int queindex)
{
    int i = queindex;
    printf("pp pushing %d time %d\n",que[i][0],que[i][2]);
    que[end][0]=que[i][0];
    que[end][1]=que[i][1];
    que[end][2]=que[i][2];
    que[end][3]=que[i][3];
    end++;
}
void pop()
{
    printf("popping %d\n",que[start][0]);
    start++;
}
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void insertion(int i)
{
    while(i>0&&p[i][1]<p[i-1][1])
    {
        swap(&p[i][0],&p[i-1][0]);
        swap(&p[i][1],&p[i-1][1]);
        swap(&p[i][2],&p[i-1][2]);
        i--;
    }
}
int main()
{
    int totalwaitingtime=0;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&p[i][j]);
        }
        insertion(i);
    }
    int currtime=p[0][1],index;
    pushall(currtime);
    while(sum<n)
    {
        if(start<end)
        {
            path[l++]=que[start][0];
            if(que[start][2]>t)
            {
                que[start][2]=que[start][2]-t;
               // printf("pid %d time %d\n",que[start][0],que[start][2]);
                currtime+=t;
                pushall(currtime);
                push(start);pop();
            }
            else
            {
                currtime+=que[start][2];
                totalwaitingtime += currtime - que[start][1]-que[start][3];
                 printf("waiting time of %d is %d\n",que[start][0],currtime - que[start][1]-que[start][3]);
                pop();
                pushall(currtime);
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(removed[i]!=1)
                {
                    currtime= p[i][1];
                    pushall(currtime);
                    break;
                }
            }
        }
    }

   // printf("here l=%d\n",l);
    while(start<end)
    {
            path[l++]=que[start][0];
           // printf("start = %d end=%d\n",start,end);
          //  printf("pid =%d time left =%d\n",que[start][0],que[start][2]);
            if(que[start][2]>t)
            {
                que[start][2]=que[start][2]-t;
                currtime+=t;
                push(start);
                pop();
            }
            else
            {
                currtime+=que[start][2];
                totalwaitingtime += currtime - que[start][1]-que[start][3];
                printf("waiting time of %d is %d\n",que[start][0],currtime - que[start][1]-que[start][3]);
                pop();
            }
    }
   // printf("here= %d\n",l);
    printf("%d\n",totalwaitingtime);
    for(int i=0;i<l;i++)
    {
        printf("%d ",path[i]);
    }
    printf("\n");
}