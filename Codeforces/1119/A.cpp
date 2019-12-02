#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 3e5+5;

vector <ll> c(L);
vector <ll> arr[L];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	for(ll i=0; i<n; i++)
	{
		cin >> c[i];

		arr[c[i]].pb(i);
	}

	ll mini = 1e17, maxi = -1e17;
	ll tm, pm;

	for(ll i=1; i<=n; i++)
	{
		if(arr[i].size())
		{
			sort(arr[i].begin(), arr[i].end());

			ll len = arr[i].size();

			if(mini>=arr[i][0])
			{
				tm = mini;
				mini = arr[i][0];
			}

			else if(tm>=arr[i][0])
			{
				tm = arr[i][0];
			}

			if(maxi<=arr[i][len-1])
			{
				pm = maxi;
				maxi = arr[i][len-1];
			}

			else if(pm<=arr[i][len-1])
			{
				pm = arr[i][len-1];
			}
		}
	}

	ll ans = -1e17;

	for(ll j=1; j<=n; j++)
	{
		if(arr[j].size())
		{
			ll len = arr[j].size();

			ll s = arr[j][0];
			ll e = maxi;

			if(arr[j][len-1]==maxi)
			{
				e = pm;
			}

			ans = max(ans, e-s);

			if(arr[j][0]==mini)
			{
				s = tm;
				e = arr[j][len-1];
			}

			ans = max(ans, e-s);

		}
	}

	cout << ans << endl;

	return 0;
}