#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

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

		a = (a*a)%mod;
		b>>=1;
	}

	return ans;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL); cout.tie(NULL);
	
	ll n;

	ll p = 31;
	ll mod = 100000007;

	while(scanf("%lld", &n)!=EOF)
	{
		ll hash = 0;
		
		string needle, hay;
		cin >> needle;
		cin >> hay;

		ll lenh = hay.length();
		ll lenn = needle.length();

		for(ll i=0; i<lenn; i++)
		{
			hash*=p;
			hash+=needle[i];
			hash%=mod;
		}

		ll temphash = 0;
		for(ll i=0; i<lenn; i++)
		{
			temphash*=p;
			temphash+=hay[i];
			temphash%=mod;
		}	

		// ll cnt = 0;

		ll flag = 0;
		if(temphash==hash)
		{
			cout << 1 << endl;
			flag = 1;
		}

		ll temp = modexp(p, lenn, mod);

		for(ll j=lenn; j<lenh; j++)
		{
			temphash*=p;
			temphash+=hay[j];
			temphash%=mod;
			temphash-=temp*hay[j-lenn];

			while(temphash<0)
			{
				temphash+=mod;
			}

			if(hash==temphash)
			{
				cout << j-lenn+1 << endl;
				flag = 1;
			}
		}

		if(flag==0)
		{
			cout << endl;
		}

		// cout << cnt << endl;	
	}

	
	return 0;
}