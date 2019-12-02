#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll fact[1000005];

ll modmul(ll a, ll b, ll c)
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
		a=(a+a)%c;
	}

	return ans;
}

ll modexp(ll a, ll b, ll c)
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

void factorial(ll n, ll mod)
{
	fact[0] = 1;

	for(ll i=1; i<=n; i++)
	{
		fact[i] = modmul(fact[i-1], i, mod);
	}
}

int main()
{
	ll n;
	cin >> n;

	ll mod = 998244353;
	// fact[0]=1;

	factorial(n, mod);	

	ll res = 0;
	for(ll i=1; i<n; i++)
	{
		ll cur = fact[n]%mod;
		cur = modmul(cur, fact[i]-1, mod);
		cur = modmul(cur, modexp(fact[i], mod-2, mod), mod);

		res = ((res+cur)%mod);
	}
	res = (res+fact[n])%mod;

	cout << res << endl;

	return 0;
}