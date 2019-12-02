#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 1e5+5;

ll a[L];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll T;
	cin >> T;

	for(ll j=1; j<=T; j++)
	{
		ll N, P;
		cin >> N >> P;

		for(ll i=0; i<N; i++)
		{
			cin >> a[i];
		}

		sort(a, a+N);

		ll sum = 0;
		for(ll i=0; i<P; i++)
		{
			sum+=a[i];
		}

		ll ans = P*a[P-1] - sum;

		// cout << ans << endl;

		for(ll i=P; i<N; i++)
		{
			sum-=a[i-P];
			sum+=a[i];

			ll temp = P*a[i] - sum;

			ans = min(ans, temp);
		
			// cout << "s: " << sum << "   t: " << temp << "    a: " << ans << endl;
		}

		cout << "Case #" << j << ": " << ans << endl;
	}

	return 0;
}