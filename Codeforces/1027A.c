#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

int main()
{
	ll T;
	scanf("%lld", &T);

	while(T--)
	{
		ll n;
		char s[105];
		scanf("%lld", &n);
		scanf("%s", s);

		ll flag=0;
		for(ll i=0; i<n/2; i++)
		{
			if(abs(s[i]-s[n-1-i])!=2)
			{
				if(s[i]!=s[n-1-i])
				{
					flag=1;
				}
			}
		}

		if(flag)
		{
			printf("NO\n");
		}

		else
		{
			printf("YES\n");
		}

	}

	return 0;
}