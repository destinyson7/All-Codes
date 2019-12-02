#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 1e5+5;

vector <ll> par(L);
vector <ll> adj[L];
vector <ll> res(L);
vector <ll> flag(L);
vector <ll> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	for(ll i=1; i<=n; i++)
	{
		ll p, c;
		cin >> p >> c;

		par[i] = p;
		adj[p].pb(i);
		res[i] = c;
	}

	for(ll i=1; i<=n; i++)
	{
		if(res[i]==1 && par[i]!=-1)
		{
			if(adj[i].size()==0)
			{
				ans.pb(i);
			}

			for(ll j=0; j<(ll)adj[i].size(); j++)
			{
				if(flag[adj[i][j]]==0 && res[adj[i][j]]==0)
				{
					// cout << i << " " << j << endl;
					break;
				}

				if(j==(ll)adj[i].size()-1)
				{
					flag[i] = 1;
					// res[i] = 0;
					ans.pb(i);
					// i=0;

					for(ll k=0; k<(ll)adj[i].size(); k++)
					{
						par[adj[i][k]] = par[i];
					}
				}
			}
		}
	}
	
	if(ans.size()==0)
	{
		cout << "-1" << endl;
	}

	else
	{
		for(ll i=0; i<(ll)ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	return 0;
}