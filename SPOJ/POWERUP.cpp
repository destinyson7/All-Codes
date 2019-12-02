#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

ll mod = 1e9+7;

ll modexp(ll a, ll b, ll mod)
{
	ll ans = 1;

	a%=mod;

	while(b)
	{
		if(b&1)
		{
			ans = (ans*a)%mod;
		}

		b/=2;
		a = (a*a)%mod;
	}

	return ans;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		ll a, b, c;
		cin >> a >> b >> c;

		if(a==-1 && b==-1 && c==-1)
		{
			return 0;
		}

		// c%=(mod-2);

		ll temp = modexp(b, c, mod-1);

		ll ans = modexp(a, temp, mod);

		if(c==0)
		{
			ans = a%mod;			
		}

		else if(b==0)
		{
			ans = 1;			
		}

		else if(a%mod==0)
		{
			ans = 0;
		}	

		cout << ans << endl;
	}

	return 0;
}