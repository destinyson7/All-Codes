#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll arr[200005];
ll dupl[200005];
ll ans[200005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, m, k;
	cin >> n >> m >> k;

	for(ll i=0; i<n; i++)
	{
		cin >> arr[i];
		dupl[i] = arr[i];
	}

	sort(arr, arr+n);

	ll cnt = 0, var = 0, cur = 0;

	for(ll j=0; j<n; j++)
	{
		if(dupl[j]>=arr[n- k*m + var])
		{
			cnt++;
			
			if(dupl[j]==arr[n- k*m + var])
			{
				var++;
			}
		}

		if(cnt==m)
		{
			ans[cur] = j+1;
			cnt = 0;
			cur++;
		}
	}

	ll res = 0;

	for(ll a = n- k*m; a<n; a++)
	{
		res+=arr[a];
	}

	cout << res << endl;
	for(ll b=0; b<cur-1; b++)
	{
		cout << ans[b] << " ";
	}
	cout << endl;

	return 0;
}