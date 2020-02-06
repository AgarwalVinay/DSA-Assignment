//Maximal Disjoint Intervals
#include<stdio.h>
#include<stdlib.h>

int a[1000000] , b[1000000];


void merge(int a[] , int b[] , int l , int m , int r){
    int  i , j , k;
    int n1= m-l+1 , n2 =r-m;
    int Lb[n1] , Rb[n2] , La[n1] , Ra[n2];
    for(i=0;i<n1;i++) {Lb[i] = b[i+l];     La[i] = a[i+l];}
    for( i=0;i<n2;i++) {Rb[i] = b[m+i+1];   Ra[i] = a[m+i+1];}

    i=0;
    j=0;
    k = l;
    while(i<n1 && j<n2){
        if(Lb[i]<=Rb[j]){
            b[k]=Lb[i];
            a[k++] = La[i++];
        }
        else{
            b[k]=Rb[j];
            a[k++] = Ra[j++];
        }
    }
    while(i<n1){
        b[k]=Lb[i];
        a[k++] = La[i++];
    }
    while(j<n2){
        b[k]=Rb[j];
        a[k++] = Ra[j++];
    }
}

void mergeSort(int a[] , int b[] , int l ,int  r){
    if(l<r){
        int m  = l + (r-l)/2;
        mergeSort(a ,b ,l , m);
        mergeSort(a, b ,m+1,r);
        merge(a ,b ,l , m , r);
    }
}

int main(){
    int n ;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    
    mergeSort(a ,b , 0 , n-1);
    int count =1;
    int r1=b[0],l2,r2;
    for(int i=1;i<n;i++){
        l2 =a[i];
        r2= b[i];
        if(l2>r1){
            count++;
            r1=r2;
        }
    }
    printf("%d\n",count);
    return 0;
}