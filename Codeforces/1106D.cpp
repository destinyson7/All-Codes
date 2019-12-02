#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

vector <ll> adj[100005];
vector <ll> visited(100005);
set <ll> ans;

void dfs(ll s)
{
	// cout << "here" << endl;
	visited[s]=1;

	for(ll i=0; i<(ll)adj[s].size(); i++)
	{
		if(!visited[adj[s][i]])
		{
			// cout << adj[s][i]+1 << " ";
			ans.insert(adj[s][i]);
			// dfs(adj[s][i]);
		}
	}

	if(ans.size()==0)
	{
		return;
	}

	ll next = *ans.begin();
	cout << next+1 << " ";
	ans.erase(ans.begin());
	dfs(next);
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL); cout.tie(NULL);
	
	ll n, m;
	cin >> n >> m;

	for(ll i=0; i<m; i++)
	{
		ll u, v;
		cin >> u >> v;

		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}

	for(ll i=0; i<n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}

	cout << "1 ";
	dfs(0);
	cout << endl;

	return 0;
}