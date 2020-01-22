#include<stdio.h>
#include<conio.h>
#include<string.h>

char str[1000001], rev[1000001];

int main(){
    scanf("%[^\n]%*c",str);
    int l = 0 , r = 0,pos=0,i;
    while(r<strlen(str)){
        if(str[r]==' '||str[r]=='\0'){
            for(i=r-1;i>=l;i--){ rev[pos] = str[i];pos++;}
            rev[pos]=' ';
            l = r+1;
            pos++;
        }
        r++;
    }
    for(i=r-1;i>=l;i--){ rev[pos] = str[i];pos++;}
    rev[pos]='\0';
    l = r+1;
    pos++;
    for(i=0;i<pos-1;i++) printf("%c",rev[i]);
    printf("\n");
    l=0 , r=0;
    int count = 0;
    while(r!=strlen(str)+1){
        if(str[r]==' '||str[r]=='\0'){
            int flag = 1;
            for( i = l;i<r;i++) if(str[i]!=rev[i]) flag = 0;
            if(flag){
                count++;
                for(int i=l;i<r;i++) printf("%c",str[i]);
                printf("\n");
            }
            l= r+1;
        }
        r++;
    }
    if(!count) printf("NO PALINDROMES");
    return 0;
}
