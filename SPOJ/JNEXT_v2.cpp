#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll t;
	cin >> t;

	while(t--)
	{
		ll n;
		cin >> n;

		vector <ll> v;

		for(ll i=0; i<n; i++)
		{
			ll temp;
			cin >> temp;

			v.push_back(temp);
		}

		ll j;
		for(j=n-2; j>=0; j--)
		{
			if(v[j] < v[j+1])
			{
				break;
			}
		}

		if(j<0)
		{
			cout << "-1" << endl;
		}

		else
		{
			ll min = j+1;

			// cout << j << " " << v[j] << " " << v[min];

			for(ll m=j+1; m<n; m++)
			{
				if(v[m] > v[j])
				{
					if(v[m] < v[min])
					{
						min = m;
					}
				}
			}

			swap(v[j], v[min]);

			sort(v.begin()+j+1, v.end());

			for(ll k=0; k<n; k++)
			{
				cout << v[k];
			}
			cout << endl;
		}
	}

	return 0;
}