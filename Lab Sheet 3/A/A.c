#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;

ll compare(const void *a,const void *b)
{
	return (*(ll*)a - *(ll*)b);
}

int main()
{
	ll n,n2,count=0,index;
	scanf("%lld",&n);
	index=n;
	ll a[n+1];
	a[n]=-1000000001;
	for(ll i=0;i<n;i++) scanf("%lld",&a[i]);
	qsort(a,n,sizeof(ll),compare);
	
	if(n%2==0) n2=n/2;
	else n2 = (n+1)/2;

	for(ll i=0;i<n-1;i++)
	{
		if(a[i]==a[i+1]) count++;

		if(count>=n2-1) index=i;			

		if(a[i]!=a[i+1]) count=0;
	}
	if(a[index]==-1000000001) printf("NO MAJORITY ELEMENT");
	else printf("%lld",a[index]);
}