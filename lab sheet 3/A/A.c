#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int arr[1000001] , n;

int find_Candidate(){
    int maxindex =0 , count =1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[maxindex]) count++;
        else count--;
        if(!count){
            maxindex = i;
            count=1;
        }
    }
    return maxindex;
}

void find_Majority(){
    int check = find_Candidate() , count=0;
    for(int i=0;i<n;i++) if(arr[i]==arr[check]) count++;

    //extra condition to check if 2 majority elements are there
    if(!(n&1)  && count == n/2){
        int check2 , j=0 , count2=0;
        while(arr[j]==arr[check]) j++;
        check2= j;
        for(int i=0;i<n;i++) if(arr[i]==arr[check2]) count2++;
        if(count2==count){
            int max = arr[check]>arr[check2]?arr[check]:arr[check2];
            printf("%d",max);
        } 
    }
    else if(count >= (int)ceil(n/2)) printf("%d",arr[check]);
    else printf("NO MAJORITY ELEMENT");
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    find_Majority(); 
    return 0;
}