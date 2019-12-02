#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

vector <ll> adj[200005];
vector <bool> visited(200005);
vector <ll> deg(200005);
vector < pair <ll, ll> > ans;

void bfs(ll s)
{
	visited[s] = true;

	queue <ll> q;

	q.push(s);

	while(!q.empty())
	{
		ll c = q.front();
		q.pop();

		for(ll i=0; i<(ll)adj[c].size(); i++)
		{
			if(!visited[adj[c][i]])
			{
				visited[adj[c][i]]=true;
				q.push(adj[c][i]);
				ans.pb(mp(c, adj[c][i]));
			}
		}
	}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, m;
	cin >> n >> m;

	for(ll i=0; i<m; i++)
	{
		ll u, v;
		cin >> u >> v;

		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);

		deg[u-1]++;
		deg[v-1]++;
	}

	ll start = 0;
	ll max = -1;

	for(ll i=0; i<n; i++)
	{
		if(deg[i] > max)
		{
			start = i;
			max = deg[i];
		}
	}

	bfs(start);

	for(ll i=0; i<(ll)ans.size(); i++)
	{
		cout << ans[i].ff+1 << " " << ans[i].ss+1 << endl;
	}

	return 0;
}