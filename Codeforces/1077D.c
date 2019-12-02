#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

ll s[200005];
ll flag[200005];
ll flag2[200005];
ll cnt2[200005];
ll ans[200005];

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
	scanf("%lld %lld", &n, &k);

	for(ll i=0; i<n; i++)
	{
		scanf("%lld", &s[i]);
		flag[s[i]]++;
		flag2[s[i]]++;
	}

	MergeSort(flag, n);

	ll a;
	a = flag[n-1];
	// printf("a %lld\n", a);

	// printf("flag2[7] %lld %lld\n", flag2[7], flag2[1]);

	ll cnt=0, l;
	while(cnt<k)
	{
		ll cnt6=0;
		for(ll m=0; cnt<k && m<n; m++)
		{

		if(flag2[s[m]] >= a)
		{
			if((cnt2[s[m]]+1)*a <= flag2[s[m]])
			{
				cnt2[s[m]]++;
				cnt++;
				l = s[m];

				ans[cnt6++]= s[m];
				// printf("%lld ", s[m]);
			}
		}
		}

	// printf("cnt6 %lld\n", cnt6);

if(cnt6==k)
	{
		for(ll d=0; d<cnt6; d++)
		{
			printf("%lld ", ans[d]);
		}
		break;
	}
	for(ll c=0; c<200005; c++)
	{
		cnt2[c]=0;
		ans[c]=0;
		// printf("cnt %lld a%lld\n", cnt, a);
	}

	

	// printf("cnt %lld a%lld\n", cnt, a);
	cnt = 0;
	a--;
	cnt6=0;

	// printf("cnt2 %lld a2%lld\n", cnt, a);
}

	// while(cnt < k)
	// {
	// 	cnt++;
	// 	printf("%lld ", l);
	// }


	return 0;
}