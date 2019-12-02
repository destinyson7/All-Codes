using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long int ll;

ll permute[2005][2005];

long long int C(long long int n, long long int r, long long int mod)
{
// 	printf("%lld %lld %lld  debug \n",n,r,mod);
	
	if(n==r)
	{
	    return 1;
	}
	
	else if(n<r)
	{
	    return 0;
	}

	if(r==1)
	{
		return permute[n][1];
	}

	if(permute[n][r]!=(-1))
	{
		return permute[n][r];
	}

	permute[n][r] = (C(n-1, r-1, mod) + C(n-1, r, mod))%mod;
	return (permute[n][r]);

}

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
		a=(a*2)%c;
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

int main()
{
	ll n, m, k;
	cin >> n >> m >> k;

	for(long long int a=0; a<2005; a++)
	{
		for(long long int b=0; b<2005; b++)
		{
			permute[a][b]=-1;
		}
	}

	for(long long int d=0; d<2005; d++)
	{
		permute[d][0]=1;
		permute[d][1]=d;
	}

	ll mod = 998244353;

	ll res = modmul(m, modexp(m-1, k, mod), mod);
	// cout << res << endl;

	res=modmul(res, C(n-1, k, mod), mod);
	res%=mod;

	cout << res << endl;

	return 0;
}