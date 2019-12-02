using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long int ll;

vector <ll> store[100005];
ll arr[100005];
ll print[100005];

int main()
{
	ll n;
	cin >> n;

	for(ll i=0; i<n; i++)
	{
		cin >> arr[i];
		store[n-arr[i]].push_back(i);
	}

	ll flag=0, val=1;

	for(ll j=1; j<=n; j++)
	{
		ll len = store[j].size();

		if(len%j)
		{
			flag=1;
			break;
		}

		ll cnt = 0;

		vector <ll> check;

		for(ll k=0; k<len; k++)
		{
			check.push_back(store[j][k]);

			if(!((k+1)%j))
			{
				cnt = check.size();

				for(ll p=0; p<cnt; p++)
				{
					print[check[p]] = val;
				}

				check.clear();
				val++;
			}
		}
	}

	if(flag)
	{
		cout <<	"Impossible" << endl;
	}

	else
	{
		cout << "Possible" << endl;
		for(ll q=0; q<n; q++)
		{
			cout << print[q] << " ";
		}
		cout << endl;
	}

	return 0;
}