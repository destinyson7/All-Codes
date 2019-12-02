#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll t;
	cin >> t;

	while(t--)
	{
		vector <ll> v;
		ll n;
		cin >> n;

		for(ll i=0; i<n; i++)
		{
			ll temp;
			cin >> temp;
			v.push_back(temp);
		}

		if(next_permutation(v.begin(), v.end()))
		{
			for(ll j=0; j<n; j++)
			{
				cout << v[j];
			}
			cout << endl;
		}

		else
		{
			cout << "-1" << endl;
		}
	}

	return 0;
}