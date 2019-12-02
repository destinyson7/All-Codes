using namespace std;

#include <iostream>
#include <algorithm>

typedef long long int ll;

ll arr[105];
ll flag[105];

int main()
{
	ll n, x;
	cin >> n >> x;

	ll cnt3=0;
	for(ll i=0; i<n; i++)
	{
		cin >> arr[i];

		flag[arr[i]]=1;
	}

	sort(arr, arr+n);

	// for(ll j=0; j<n; j++)
	// {
	// 	cout << arr[j] << " ";
	// }

	ll ans=0;

	for(ll j=0; j<x; j++)
	{
		if(flag[j]==0)
		{
			ans++;
		}
	}

	if(flag[x]==1)
	{
		ans++;
	}

	cout << ans << endl;

	return 0;
}