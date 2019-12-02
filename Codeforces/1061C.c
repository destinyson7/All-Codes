#include<stdio.h>

typedef long long int ll;

ll arr[100005];
ll hash[100005];

ll modmul(ll a,ll b,ll c)
{
	ll ans=0;

	a%=c;

	while(b)
	{
		if(b&1)
		{
			ans=((ans+a)%c);
		}
		b >>= 1;
		a=(a*2)%c;
	}

	return ans;
}

int main()
{
	ll n, mod = 1000000007;
	scanf("%lld", &n);

	for(ll i=0; i<n; i++)
	{
		scanf("%lld", &arr[i]);

		for(ll j=1; j<=arr[i]; j++)
		{
			if(arr[i]%j==0)
				hash[j]++;

			// printf("hash[%lld] = %lld\n", j, hash[j]);
		}
	}

	ll ans =0, pr=1;

	for(ll k=1; k<=n; k++)
	{
		// printf("pr1 %lld\n", pr);
		for(ll a=1; a<=k; a++)
		{
			pr= modmul(pr, hash[a], mod);
		}
			printf("pr2 %lld\n", pr);

		ans=(ans+pr)%mod;
		printf("ans %lld\n", ans);
		pr=1;
	}

	printf("%lld\n", ans);
	return 0;
}