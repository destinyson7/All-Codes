#include<stdio.h>

typedef long long int ll;

ll arr[200005];
ll flag[2000005];
ll ans[2000005];

int main()
{
	ll n;
	scanf("%lld", &n);

	ll sum=0;
	for(ll i=0; i<n; i++)
	{
		scanf("%lld", &arr[i]);
		sum+=arr[i];
		flag[arr[i]]++;
	}
	// printf("sum %lld\n", sum);

	ll k=0;
	for(ll j=0; j<n; j++)
	{
		if(sum - arr[j] <=2000000)
		{
			if(flag[(sum - arr[j])/2]>0 && (sum-arr[j])%2==0)
		{
			if(sum!= 3*arr[j] || flag[(sum - arr[j])/2]>1)
			{
				// printf("%lld\n", sum - arr[j]);
				ans[k++]=j;
			}
		}
	}
	}

	printf("%lld\n", k);
	for(ll m = 0; m<k; m++)
	{
		printf("%lld ", ans[m]+1);
	}


	return 0;
}