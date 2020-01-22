#include<stdio.h>
#include<conio.h>
#include<string.h>

char str[1000001] , ind[26];

int main(){
    gets(str);
    int l=0 , r=0 , max =0 , index;
    while(r<strlen(str)){
        if(ind[str[r]-'a']>l){
            if(r-l>max){
                max = r-l;
                index = l;
            }
            l = ind[str[r]-'a'];
        }
        ind[str[r]-'a']=r+1;
        r++;
    }
    if(r-l>max){
        max = r-l;
        index = l;
    }
    printf("%d\n",max);
    for(int i=index ;i<max+index;i++) printf("%c",str[i]);
    return 0;
}