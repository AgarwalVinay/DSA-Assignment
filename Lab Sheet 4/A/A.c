#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int x[100005] ,y[100005] , label[100005]  , xam, yam, labelam ,n;
double cosx[100005] , distance[100005];

void swap(int * a ,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapd(double * a ,double * b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low  , int high , int choose){
    if(choose==1){//to sort according to the value of y
        int pivot = y[high] ;
        int i = low-1;
        for(int j=low;j<high;j++){
            if(y[j]<pivot){
            i++;
            swap(&y[i] , &y[j]);
            swap(&x[i] , &x[j]);
            swap(&label[i] , &label[j]);
            }
        }
        swap(&y[i+1] , &y[high]);
        swap(&x[i+1] , &x[high]);
        swap(&label[i+1] , &label[high]);
        return i+1;
    }
    else if(choose==2){//to sort according to the value of y
        double pivot = cosx[high] ;
        int i = low-1;
        for(int j=low;j<high;j++){
            if(cosx[j]<pivot){
                i++;
                swapd(&cosx[i] , &cosx[j]);
                swapd(&distance[i] , &distance[j]);
                swap(&y[i] , &y[j]);
                swap(&x[i] , &x[j]);
                swap(&label[i] , &label[j]);
            }
        }
        swapd(&cosx[i+1] , &cosx[high]);
        swapd(&distance[i+1] , &distance[high]);
        swap(&y[i+1] , &y[high]);
        swap(&x[i+1] , &x[high]);
        swap(&label[i+1] , &label[high]);
        return i+1;
    }
}

void quicksort(int low , int high, int choose){
    if(low<high){
        int pi = partition(low ,high ,choose );
        quicksort(low , pi-1  , choose);
        quicksort(pi+1 , high , choose);
    }
}

void find_angle(int no){
    cosx[no] = ((double)(x[no] -xam))/sqrt(pow( abs(x[no] -xam), 2) + pow( abs(y[no] - yam), 2));
}

void find_distance(int no){
    distance[no] = sqrt( pow( abs(x[no] -xam), 2) + pow( abs(y[no] - yam), 2));
}

void sort(int start ,int len){
    for(int i=start;i<=start+len;i++){
        int max = i;
        for(int j=start+1;j<=start+len;j++){
            
            if(distance[max]<distance[j]) max=j;
        }
        if(i==max) break;
        swapd(&distance[i] , &distance[max]);
        swap(&y[i] , &y[max]);
        swap(&x[i] , &x[max]);
        swap(&label[i] , &label[max]);
    }
}

int main(){
    scanf("%d ",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&label[i] , &x[i] ,&y[i]);
    }
    //sort according to y and get position of all might 
    quicksort(0 , n-1 , 1);
    xam = x[0];
    yam = y[0];
    labelam = label[0];
    // sort according to cosx and get angle positions  and then sort it according to distance as well in same cos value
    
    cosx[0]=55;
    for(int i=1;i<n;i++) { find_angle(i);find_distance(i);}
    quicksort(0 , n-1 , 2);

    for(int i=0;i<n;i++){
        int k =0;
        for(int j=i+1;j<n;j++){
            if(cosx[i]==cosx[j]) k++;
        }
        if(k) sort(i , k);
    }

    for(int i=n-2;i>=0;i--) printf("%d ",label[i]);

    return 0;
}