#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll x[200005];
ll y[200005];

int main()
{
	ll N;
	cin >> N;

	for(ll i=0; i<N; i++)
	{
		cin >> x[i] >> y[i];
	}

	ll Q;
	cin >> Q;

	while(Q--)
	{
		ll f, t;
		cin >> f >> t;

		ll ans = 0;

		for(ll i=f; i<=t; i++)	
		{
			for(ll j=f; j<=t; j++)
			{
				ll dist;
				dist = (((x[j]-x[i])*(x[j]-x[i])) + ((y[j]-y[i])*(y[j]-y[i])));
				ans = max(ans, dist);
			}
		}

		cout << ans << endl;
	}

	return 0;
}	