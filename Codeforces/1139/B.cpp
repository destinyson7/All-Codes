#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L=2e5+5;

ll a[L];

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

	ll ans = a[n-1];

	ll temp = a[n-1];

	for(ll i=n-2; i>=0; i--)
	{
		temp = max((ll)0, min(a[i], temp-1));
		ans+=temp;
		// cout << ans << endl;
	}

	cout << ans << endl;


	return 0;	
}