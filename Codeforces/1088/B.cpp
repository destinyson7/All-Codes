using namespace std;

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

ll arr[100005];

void Merge(long long int *arr, long long int *left, long long int l1, long long int *right, long long int l2)
{
	long long int i=0, j=0, k=0;

	while(i<l1 && j<l2)
	{
		if(left[i]<=right[j])
		{
			arr[k++]=left[i++];
		}

		else
		{
			arr[k++]=right[j++];
		}
	}

	while(i<l1)
	{
		arr[k++]=left[i++];
	}

	while(j<l2)
	{
		arr[k++]=right[j++];
	}

}

void MergeSort(long long int *arr, long long int n)
{
	long long int mid, *left, *right;

	if(n<2)
	{
		return;
	}

	mid=n/2;

	left=(long long int*)malloc(mid*sizeof(long long int));
	right=(long long int*)malloc((n-mid)*sizeof(long long int));

	for(long long int i=0; i<mid; i++)
	{
		left[i]=arr[i];
	}

	for(long long int j=mid; j<n; j++)
	{
		right[j-mid]=arr[j];
	}

	MergeSort(left, mid);
	MergeSort(right, n-mid);
	Merge(arr, left, mid, right, n-mid);
	
	free(left);
	free(right);
}
int main()
{
	ll n, k;
	cin >> n >> k;

	for(ll i=0; i<n; i++)
	{
		cin >> arr[i];
	}

	MergeSort(arr, n);

	// for(ll m=0; m<n; m++)
	// {
	// 	cout << arr[m] << " ";
	// }

	ll cnt=0, cntk=0;
	for(ll j=0; j<n; j++)
	{
		// cout << arr[j] << " arr[j]    ";
		if(cntk==k)
		{
			break;
		}
	
		// cout << arr[j]-cnt << "    blah   " << endl;
	
		if((arr[j]-cnt)==0)
		{
			continue;
		}

		else
		{	
			cntk++;
			// cout << arr[j] << "arr[j]      ";
			cout << arr[j]-cnt << " ";
			cnt+=(arr[j]-cnt);
			// cout << " cnt is " << cnt << endl;
		}
	}

	while(k-cntk > 0)
	{
		k--;
		cout << "0 ";
	}

	cout << endl;
	
	return 0;
}