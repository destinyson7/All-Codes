#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 1e4+5;

vector <ll> a(L);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	for(ll i=1; i<=n; i++)
	{
		cin >> a[i];
	}

	ll cnt = 0;

	for(ll i=1; i<=n; i++)
	{
		while(1)
		{
			if(a[i] > i)
			{
				ll maxi = a[i];
				for(ll j=i+1; j<=maxi; j++)
				{
					maxi = max(maxi, a[j]);
				}

				i = maxi;				
			}

			else
			{
				break;
			}
		}

		// cout << i << endl;

		cnt++;
	}

	cout << cnt << endl;

	return 0;
}