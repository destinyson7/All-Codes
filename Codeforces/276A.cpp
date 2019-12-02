#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll n, k;
	cin >> n >> k;

	ll a, b;
	ll ans = -(1e17);

	for(ll i=0; i<n; i++)
	{
		cin >> a >> b;

		if(b>k)
		{
			ans = max(ans, a-b+k);
		}

		else
		{
			ans = max(ans, a);
		}
	}

	cout << ans << endl;

	return 0;
}