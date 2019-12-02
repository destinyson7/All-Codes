#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

ll a[100005];
ll b[100005];
ll hash[100005];
ll min[100005];
ll rem[100005];

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

	for(ll i=1; i<=n; i++)
	{
		scanf("%lld", &a[i]);
	}

	for(ll j=1; j<=n; j++)
	{
		scanf("%lld", &b[j]);
	}

	for(ll c=0; c<100005; c++)
	{
		rem[c]=0;
	}

	ll ans=0, cnt=0;

	for(ll k=n; k>0; k--)
	{
		if(hash[a[k]]==0)
		{
			hash[a[k]]=1;
			min[a[k]]=b[k];
		}

		else
		{
			if(b[k]>min[a[k]])
			{
				rem[cnt++]=min[a[k]];
				min[a[k]]=b[k];
			}

			else
			{
				rem[cnt++]=b[k];
			}
		}
	}

	ll cnt2=0;
	for(ll d=1; d<100005; d++)
	{
		if(hash[d]==1)
			cnt2++;
	}

	MergeSort(rem, cnt);

	for(ll b=0; b<m-cnt2; b++)
	{
		ans+=rem[b];
		// printf("%lld ", ans);
	}

	printf("%lld\n", ans);
	
	return 0;
}