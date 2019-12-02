#include<stdio.h>

typedef long long int ll;

char s[1000005];
ll ones[1000005];

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

ll modexp(ll a,ll b,ll c)
{
	ll ans=1;

	a%=c;

	while(b)
	{
		if(b&1)
		{
			ans=((ans*a)%c);
		}

		b >>= 1;
		a=(a*a)%c;
	}

	return ans;
}

int main()
{
	ll n, q, mod=1000000007;
	scanf("%lld %lld", &n, &q);

	scanf("%s", s);

	ll cnt=0;

	for(ll i=0; i<n; i++)
	{
		if(s[i]=='1')
			cnt++;

		ones[i]=cnt;
	}

	while(q--)
	{
		// printf("1\n");
		ll l, r;
		scanf("%lld %lld", &l, &r);
		l--;
		r--;

		ll k=0;

		if(l-1>=0)
			k = ones[r]-ones[l-1];
		
		else
			k= ones[r];

		// printf("k %lld\n", k);
		// printf("2\n");
		ll j = r-l+1 - k;
		// printf("j %lld\n", j);

		ll ans;
		ans = modexp(2, k, mod);
		ans--;

		// printf("3\n");

		ll ans2=1;

		if(j==0)
			ans2=1;

		else
			ans2 = modexp(2, j, mod);
		
		// printf("4\n");
		ans = modmul(ans, ans2, mod);

		printf("%lld\n", ans);
	}	

	return 0;
}