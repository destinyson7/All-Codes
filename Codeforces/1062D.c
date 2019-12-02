#include<stdio.h>

typedef long long int ll;

int main()
{
	ll n;
	scanf("%lld", &n);

	ll ans=0;

	for(ll i=2; i<=n; i++)
	{
		ll temp = n/i;

		ans += ((temp*(temp+1))/2 -1);
	}	

	printf("%lld\n", 4*ans);

	return 0;
}