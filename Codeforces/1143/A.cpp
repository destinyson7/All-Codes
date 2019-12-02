#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 2e5+5;

vector <ll> a(L);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	for(ll i=0; i<n; i++)
	{
		cin >> a[i];
	}

	ll left = 1e9;
	ll right = 1e9;

	for(ll i=0; i<n; i++)
	{
		if(a[i]==1)
		{
			left = i;
		}

		else
		{
			right = i;
		}
	}

	cout << min(left, right)+1 << endl;

	return 0;
}