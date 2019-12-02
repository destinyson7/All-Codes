#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

ll arr[100005];
ll arr2[100005];
ll prefix[100005];

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
	ll n, m;
	scanf("%lld %lld", &n, &m);
	ll sum=0;
	ll max = -1, min = m+1;
	for(ll i=0; i<n; i++)
	{
		scanf("%lld", &arr[i]);
		// arr2[i]=arr[i];

		// hash[arr[i]]++;

		// for(ll b=1; b<=arr[i]; b++)
		// {
		// 	hash[b]++;
		// }	

		prefix[1]++; 
		prefix[arr[i]+1]--;

		// printf("hash[%lld] %lld\n", arr[i], hash[arr[i]]);

		sum+=arr[i];
		if(arr[i]>max)
		{
			max=arr[i];
		}

		if(arr[i]<min)
		{
			min=arr[i];
		}
	}


	// printf("%lld ", prefix[1]);
	for(ll e=2; e<=max; e++)
	{
		prefix[e]+=prefix[e-1];
		// printf("%lld ", prefix[e]);
	}
	// printf("\n");

	// printf("max %lld\n", max);

	MergeSort(arr, n);

	// for(ll b=max; b>=1; b--)
	// {

	// }

	ll ans=0, flag=0;

	ll c =0, d=0;
	for(ll j=max; j>1; j--)
	{
		// printf("prefix %lld\n", prefix[j]);
		// printf("hash[%lld] = %lld\n", j, hash[j]);
		ans+= (prefix[j]-1);
		// printf("ans %lld\n", ans);

		// printf("arr[j]%lld arr[j-1] %lld\n", arr[j], arr[j-1]);
		// c+=(arr[d]-arr[d++]);
		// printf("c %lld\n", c);
	}

	// ans+= (max-1);

	printf("%lld\n", ans);

	return 0;
}