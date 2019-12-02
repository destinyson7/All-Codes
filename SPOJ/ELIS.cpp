#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll arr[15];
ll maxi[15];

ll dp(ll n)
{
	for(ll i=0; i<n; i++)
	{
		maxi[i]=1;
		for(ll j=0; j<i; j++)
		{
			if(arr[i]>arr[j] && maxi[j]+1 > maxi[i])
			{
				maxi[i] = maxi[j]+1;
			}
		}
	}

	ll res = maxi[0];

	for(ll j=0; j<n; j++)
	{
		res = max(res, maxi[j]);
	}

	return res;
}

int main()
{
	ll N;
	cin >> N;

	for(ll i=0; i<N; i++)
	{
		cin >> arr[i];
	}

	ll ans = dp(N);

	cout << ans << endl;

	return 0;
}