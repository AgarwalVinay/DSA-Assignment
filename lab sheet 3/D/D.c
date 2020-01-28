#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[10000] , pat[1000] , newstr[10000];
int p[10000];

int main(){
    gets(str);
    gets(pat);
    int len1 = strlen(str) , len2 = strlen(pat);
    int count =0;
    for(int i=0;i<len1-len2+1;i++){
        int p = 0;
        for(int j=0;j<len2;j++) if(pat[j] == str[j+i]) p++;
        if(p>=len2-1) count++;
    }
    printf("%d",count);
    return 0;   
}