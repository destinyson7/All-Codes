using namespace std;

#include <iostream>

typedef long long int ll;

string s[100005];
ll cost[100005];

typedef struct minicost{
	ll o;
	string s;
}	dtype;

dtype mincost[100005];

int main()
{
	ll n, k, m;
	cin >> n >> k >> m;

	for(ll i=1; i<=n; i++)
	{
		cin >> s[i];

	}

	for(ll j=1; j<=n; j++)
	{
		cin >> cost[j];
	}

	for(ll a=0; a<k; a++)
	{
		ll x;
		cin >> x;

		ll temp[x];

		cin >> temp[0];
		ll min = cost[temp[0]];
		for(ll b=1; b<x; b++)
		{
			cin >> temp[b];	

			if(cost[temp[b]]<min)
			{
				min = cost[temp[b]];
			}
		}

		for(ll c=0; c<x; c++)
		{
			cost[temp[c]]=min;
		}		
	}

	for(ll e=1; e<=n; e++)
	{
		mincost[s[e]]=cost[e];
	}

	ll ans = 0;
	for(ll d=0; d<m; d++)
	{
		string s2;
		cin >> s2;

		ans+=mincost[s2];
	}

	cout << ans << endl;

	return 0;
}