#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int str[1000001] ;

int sortdsc(const void *p1, const void *p2)
{
	return(*(int*)p2 - *(int*)p1);
}

int sortinc(const void *p1 , const void *p2){
    return(*(int *)p1-*(int *)p2);
}


int main(){
    int len=0,i,j;
    char c='0';

    while(c!='\n'){
        scanf("%c",&c);
        str[len]=c-'0';
        len++;
    }
    int largest[len-1] , smallest[len-1];
    qsort (str,len-1, sizeof(int),sortdsc );
    for(i=0;i<len-1;i++){largest[i]=str[i];}

    qsort (str,len-1, sizeof(int),sortinc );
    for(i=0;i<len-1;i++){smallest[i] =str[i];}
    if(smallest[0]==0){
        int i=0;
        while(smallest[i]==0 && i<len-1) i++;
        if(i!=len-1){
        smallest[0]^=smallest[i];
        smallest[i]^=smallest[0];
        smallest[0]^=smallest[i];
        }
    }

    int carry=0;
    for( i=len-2;i>=0;i--){
        int temp = largest[i]+carry-smallest[i];
        if(temp<0){
            temp+=10;
            carry=-1;
        }
        else carry=0;
        smallest[i] = temp;
    }
    int count=0 , flag=0;
    for( i=0;i<len-1;i++) {if(smallest[i]==0) count++;}
    if(count==len-1) printf("0");//if all are zero
    else {
        for( i=0;i<len-1;i++){
            if(flag ) printf("%d",smallest[i]);
            else if (!flag && smallest[i]!=0){
                printf("%d",smallest[i]);
                flag=1;
            }
        }
    }
    return 0;
}
