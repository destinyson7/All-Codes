#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector < pair <ll, ll> > x;
vector < pair <ll, ll> > a;
map < pair <ll, ll>, ll> mapp;

int main()
{
	ll n;
	cin >> n;
	
	ll x1, y1;
	for(ll i=0; i<n; i++)
	{
		cin >> x1 >> y1;
		x.push_back(make_pair(x1, y1));
	}

	ll a1, b1;
	for(ll j=0; j<n; j++)
	{
		cin >> a1 >> b1;
		a.push_back(make_pair(a1, b1));
	}

	ll flag = 0;	
	for(ll k=0; k<n; k++)
	{
		for(ll p=0; p<n; p++)
		{
			pair <ll, ll> temp = make_pair(x[k].first + a[p].first, x[k].second + a[p].second);
		
			if(mapp.find(temp)==mapp.end())
			{
				mapp[temp] = 1;
			}

			else
			{
				mapp[temp]+=1;
			}

			if(mapp[temp]==n)
			{
				cout << temp.first << " " << temp.second << endl;
				flag = 1;
				break;
			}
		}

		if(flag)
		{
			break;
		}
	}

	return 0;
}