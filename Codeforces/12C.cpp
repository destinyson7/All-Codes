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
	
	ll n, m;
	cin >> n >> m;

	vector <ll> v;

	for(ll i=0; i<n; i++)
	{
		ll temp;
		cin >> temp;
		v.pb(temp);
	}

	for(ll i=0; i<m; i++)
	{
		string s;
		cin >> s;
	}

	sort(v.begin(), v.end());

	ll mini = 0, maxi = 0;

	for(ll i=0; i<m; i++)
	{
		mini+=v[i];
		maxi+=v[n-1-i];
	}
	
	cout << mini << " " << maxi << endl;

	return 0;
}