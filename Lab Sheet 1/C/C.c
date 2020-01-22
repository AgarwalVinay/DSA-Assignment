#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<string.h>

void smallestWindow(char str[] , char  pat[] , int len1 , int len2){
    if(len1<len2){
        printf("NO WINDOW");
        return ;
    }

    int hash_pat[256]={0};
    int hash_str[256]={0};

    for(int i=0;i<len2;i++) hash_pat[pat[i]]++;
    int start = 0 , start_index=-1 , min_len=INT_MAX, count = 0;

    for(int j=0;j<len1;j++){
        hash_str[str[j]]++;
        
        if(hash_pat[str[j]]!=0 && hash_str[str[j]]<=hash_pat[str[j]]) count++;

        if(count==len2){
            while(hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]]==0){
                if(hash_str[str[start]] > hash_pat[str[start]]) hash_str[str[start]]--;
                start++;
            }

            int len_window = j-start+1;
            if(min_len>len_window){
                min_len = len_window;
                start_index = start;
            }
        }
    }

    if(start_index ==-1){
        printf("NO WINDOW");
        return ;
    }

    printf("%d %d\n",start_index , start_index+min_len-1);
    for(int i=start_index;i<start_index+min_len;i++)printf("%c",str[i]);
}

int main(){
    char str[1000000] , pat[1000000];
    scanf("%[^\n]%*c",str);
    scanf("%[^\n]%*c",pat);
    int len1=strlen(str) , len2=strlen(pat) ;
    smallestWindow(str ,pat,len1,len2);
    return 0;
}