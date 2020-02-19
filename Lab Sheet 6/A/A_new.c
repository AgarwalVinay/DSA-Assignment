#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[3000005] , prev ='^' , stack[3000005] ,top=-1;

int main(){
    gets(str);
    for(int i=0;i<strlen(str);i++){
        char temp = str[i];
        if(temp == prev) continue;
        else if(temp!=stack[top] || top==-1){
            stack[++top] = temp;
            prev = '^';
        }
        else if(temp==stack[top]) prev = stack[top--];
    }
    if(top==-1) printf("VANISHED");
    else {
        for(int i=0;i<=top;i++) printf("%c",stack[i]);
    }
    return 0;
}