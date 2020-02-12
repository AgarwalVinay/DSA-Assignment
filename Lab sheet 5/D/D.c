#include<stdio.h>
#include<stdlib.h>
int n , k  ,arr[1000050];
int binary_lower(int value) //simple binary search
{ 
	int start = 0 , end = n - 1 , ans = -1 , mid; 
	while (start <= end) { 
		mid = (start + end) / 2; 
        if(arr[mid]==value) return mid;
		if (arr[mid] >= value) { 
			end = mid - 1; 
			ans = mid; 
		} 
		else { 
			start = mid + 1; 
		} 
	} 
	return ans; 
} 

int main() 
{ 
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	int count = 0; 
	for (int i = 2; i < n; i++) { 
		int cur = binary_lower(arr[i] - k); 
		if (cur <= i - 2) { 
			count += ((i - cur) * (i - cur - 1)) / 2; // nC2
		} 
	}
	printf("%d",count ); 
	return 0; 
} 
