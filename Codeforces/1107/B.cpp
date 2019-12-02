#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	for(ll i=0; i<n; i++)
	{
		ll k, x;
		cin >> k >> x;

		cout  << x + 9*(k-1) << endl;
	}

	return 0;
}