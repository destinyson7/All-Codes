#include<stdio.h>

typedef long long int ll;

int main()
{
	ll n, S;
	scanf("%lld %lld", &n, &S);

	ll ans=0;
	if(S%n==0)
		ans = S/n;

	else
		ans= S/n +1;

	printf("%lld\n", ans);

	return 0;
}	