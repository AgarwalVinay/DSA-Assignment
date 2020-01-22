#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
    char str[501],strmod[1002];
    gets(str);
    int len1=strlen(str) , len2 ;
    strmod[0]='#';
    for(int i=0;i<len1;i++){
        strmod[2*i+1] =str[i];
        strmod[2*(i+1)]='#';
        if(i==len1-1){
            strmod[2*i+3]='$';
            strmod[2*i+4]='\0';
        }
    }
    len2 =strlen(strmod);//modified string has been created
    int p[1002]={0};
    
    int c=0 , r=0;//center and boundary
    for(int i=1;i<len2-1;i++){
        int  i_mirror = c - (i-c);//pos of mirror value
        if(r>i) {p[i] = (r-i>p[i_mirror] ?p[i_mirror] : r-i );}
        else p[i]=0;

        while( strmod[i+1+p[i]] == strmod[i-1-p[i]] ) { p[i]++; }
        if(i+p[i]>r){
            c = i ;
            r = i+p[i];
        } 
    }
    int max =0 , index= 0;
    for(int i=1;i<len2-1;i++){
        if(max<p[i]){
            max = p[i];
            index = i;
        }
    }
    printf("%d\n",max);
    for(int i=(index-max);i<max+index;i++){ if(strmod[i]!='#')printf("%c",strmod[i]);}
    return 0;
}