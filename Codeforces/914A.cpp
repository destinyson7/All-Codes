#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll arr[2000005];

int main()
{
	ll n;
	cin >> n;

	for(ll i=0; i<n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr+n);

	ll ans = arr[n-1];
	for(ll j=n-1; j>=0; j--)
	{
		ll temp = (ll)sqrt(arr[j]);

		if((temp*temp)!=arr[j])
		{
			ans = arr[j];
			break;
		}
	}

	cout << ans << endl;

	return 0;
}