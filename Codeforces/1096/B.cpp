#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

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

long long int C2(ll n, ll mod)
{
	ll ans = 0;

	if(n%2==0)
	{
		ans = modmul(n/2, n+1, mod);
	}
	
	else
	{
	 	ans = modmul(n, n+1/2, mod);
	}

	return ans;
}

int main()
{
	ll n;
	cin >> n;

	ll mod = 998244353;

	string s;
	cin >> s;

	ll start = 1;
	for(ll i=0; i<n-1; i++)
	{
		if(s[i]==s[i+1])
		{
			start++;
		}

		else
		{
			break;
		}
	}

	ll end = 1;
	for(ll j=n-1; j>0; j--)
	{
		if(s[j]==s[j-1])
		{
			end++;
		}

		else
		{
			break;
		}
	}

	ll res = 0;

	if(s[0]==s[n-1])
	{
		if(start+end == 2*n)
		{
			res = C2(n, mod);
		}

		else
		{
			res = modmul(start+1, end+1, mod);
		}
	}

	else
	{
		res = (start+1 + end+1)%mod;

		res-=1;

		while(res<0)
		{
			res+=mod;
		}
	}

	cout << res%mod << endl;
	
	return 0;
}