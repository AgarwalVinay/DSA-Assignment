#include<stdio.h>
#include<stdio.h>

int stack[3000006] ,top =-1 , max_area ,currarea , hist[3000006] ,n;

int main() 
{   scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&hist[i]);
    int i =0;
    while(i<n){
        if(top == -1 || hist[stack[top]] <=hist[i]){
            stack[++top] =i++;
        }
        else {
            int tp = stack[top];
            top--;
            currarea =  hist[tp] * (top==-1 ? i: i-stack[top]-1);
            if(max_area <currarea) max_area =currarea;
        }
    }
    while (top != -1) 
	{ 
		int tp = stack[top];
        top--;
        currarea =  hist[tp] * (top==-1 ? i: i-stack[top]-1);
        if(max_area <currarea) max_area =currarea;
	}
    printf("%d",max_area);
	return 0; 
}