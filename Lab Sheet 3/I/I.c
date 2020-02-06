#include<stdio.h>
#include<stdlib.h>

int a[10005] , b[10005] , n;

int decr(const void *p1 , const void * p2){
    return (*(int *) p2 - *(int *)p1);
}

int main(){
    scanf("%d",&n);
    int sum = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum +=a[i];
    }
    qsort(a ,n , sizeof(int)  , decr);

    if(a[n-1] !=0){printf("NO NUMBER");return 0;}
    else {
        if(sum%3==0){ for(int i=0;i<n;i++) printf("%d",a[i]); return 0;}
        else{
            for(int i=0;i<n;i++){
                b[i] = a[i]%3;
            }
            int k = sum%3 , f2 = 0 , f1 = 0;
            if(k==2){
                //for 2
                for(int i=n-1;i>=0;i--){
                    if(b[i]==2){
                        f2=  1;
                        a[i] = -1;
                        break;
                    }
                }
                if(!f2){
                    int count =2;
                    for(int i=n-1;i>=0;i--){
                        if(b[i]==1 && count!=0){
                            a[i] = -1;
                            count--;
                        }
                    }
                    if(count) {
                        printf("NO NUMBER");
                        return 0;
                    }
                }
            }
            else{
                for(int i=n-1;i>=0;i--){
                    if(b[i]==1){
                        a[i]= -1;
                        f1=1;
                        break;
                    }
                }

                if(!f1){
                    int count = 2;
                    for(int i=n-1;i>=0;i--){
                        if(b[i]== 2 && count){
                            a[i]=-1;
                            count--;
                        }
                    }
                    if(count) {
                        printf("NO NUMBER");
                        return 0;
                    
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++) if(a[i]!=-1) printf("%d",a[i]);
    return 0;
}