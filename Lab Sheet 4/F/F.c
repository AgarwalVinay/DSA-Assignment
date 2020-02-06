#include<stdio.h>
#include<stdlib.h>
int n , l , arr[1000001] , p, ans[1000001] ,f1 , f2;


void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition ( int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j < high; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		}
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]); 
    scanf("%d",&l);

    for(int i=0;i<n;i++) if(arr[i] == l ) p=i;
    for(int i=0;i<=p;i++){
        if(arr[i]>l){
            f1=1;
            break;
        }
    }
    for(int i=p+1;i<n;i++){
        if(arr[i]<=l){
            f2=1;
            break;
        }
    }
    if(!f1 && !f2){
        printf("ALL SET");
        return 0;
    }
    swap(&arr[p] , &arr[n-1]);//to set the pivot
    partition( 0 , n-1);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}