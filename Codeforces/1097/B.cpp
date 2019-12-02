#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector <ll> arr;
int main()
{
	ll n;
	cin >> n;

	ll temp;
	for(ll i=0; i<n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	ll big = 1<<15;
	ll val = 0;

	for(ll j=0; j<big; j++)
	{
		ll cur = j;

		for(ll k=n-1; k>=0; k--)
		{
			if(cur&1)
			{
				val-=arr[k];
			}

			else
			{
				val+=arr[k];
			}

			if(val<=0)
			{
				val+=360;
				val%=360;
			}

			val%=360;

			cur>>=1;
		}

		if(!val)
		{
			cout << "YES" << endl;
			return 0;
		}

		val = 0;
	}

	cout << "NO" << endl;

	return 0;
}