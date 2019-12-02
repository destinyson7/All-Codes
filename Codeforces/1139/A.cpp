#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

ll modexp(ll x, ll y, ll mod)
{
    ll ans = 1;

    x%=mod;

    while(y)
    {
        if(y&1)
        {
            ans = (ans*x)%mod;
        }

        x = (x*x)%mod;
        y>>=1;
    }

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;

	string s;
	cin >> s;

	ll ans = 0;

	for(ll i=0; i<n; i++)
	{
		if((s[i]-48)%2==0)
		{
			ans+=(i+1);
		}
	}

	cout << ans << endl;

	return 0;
}