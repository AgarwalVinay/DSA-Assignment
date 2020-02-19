#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack[5000006], top =-1 ;
char expr[5000006];

int main(){
    scanf("%s",expr);
    for(int i=0;i<strlen(expr);i++){
        int p=-5;
        switch(expr[i]){
            case '[': p=-3;break;
            case '(': p=-2;break;
            case '{': p=-1;break;
            case ']': p=3;break;
            case ')': p=2;break;
            case '}': p=1;break;
        }
        if(p<0) stack[++top] =p;
        else {
            if((p+stack[top]) || top==-1){
                printf("NO");
                return 0;
            } 
            top--;
        }
    }
    int total = 0;
    for(int i=0;i<=top;i++) total+=stack[i];
    if(total) printf("NO");
    else printf("YES");
    return 0;
}