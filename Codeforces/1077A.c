#include<stdio.h>

typedef long long int ll;

int main()
{
	ll t;
	scanf("%lld", &t);

	while(t--)
	{
		ll a, b, k;
		scanf("%lld %lld %lld", &a, &b, &k);

		if(k&1)
		{
			printf("%lld\n", (k/2)*(a-b)+a);
		}

		else
		{
			printf("%lld\n", (k/2)*(a-b));
		}
	}

	return 0;
}