#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 1e3+5;

vector <ll> a(L);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, h;
	cin >> n >> h;

	for(ll i=0; i<n; i++)
	{
		cin >> a[i];
	}

	// sort(a.begin(), a.end());

	ll cnt = 0;
	for(ll i=0; i<n; i+=2)
	{
		h-=max(a[i], a[i+1]);

		if(h<0)
		{
			h+=max(a[i], a[i+1]);
			h-=min(a[i], a[i+1]);

			if(h>=0)
			{
				cnt++;
			}

			cout << cnt << endl;
			return 0;
		}

		cnt+=2;
	}

	cout << min(n, cnt) << endl;

	return 0;
}