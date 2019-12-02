#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

void Merge(ll *arr, ll l, ll mid, ll r)
{
	ll i, j, k=l;

	ll n1 = mid - l + 1;
	ll n2 = r - mid;

	ll Left[n1], Right[n2];

	for(i=0; i<n1; i++)
		Left[i]=arr[l+i];

	for(j=0; j<n2; j++)
		Right[j]=arr[mid+1+j];

	i=0, j=0;

	while(i<n1 && j<n2)
	{
		if(Left[i]<=Right[j])
			arr[k++]=Left[i++];

		else
			arr[k++]=Right[j++];
	}

	while(i<n1)
		arr[k++]=Left[i++];

	while(j<n2)
		arr[k++]=Right[j++];

}

void MergeSort(ll *arr, ll l, ll r)
{
	if(l<r)
	{
		ll mid = l + (r-l)/2;

		MergeSort(arr, l, mid);
		MergeSort(arr, mid+1, r);
		Merge(arr, l, mid, r);
	}
}

int main()
{
	ll arr[]= {1, 2, 9, 6, 0, -4};
	ll len = sizeof(arr)/sizeof(arr[0]);

	MergeSort(arr, 2, len-1);

	for(ll i=0; i<len; i++)
		printf("%lld ", arr[i]);

	return 0;
}