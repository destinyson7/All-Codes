#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	ll ans = 0;

	for(ll i=3; i<=n; i++)
	{
		ans+=(i*(i-1));
	}

	cout << ans << endl;

	return 0;
}