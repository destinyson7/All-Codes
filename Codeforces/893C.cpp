using namespace std;

#include <iostream>
#include <vector>

typedef long long int ll;

ll cost[100005];
vector<ll> adj[100005];
ll x[100005];
ll y[100005];
bool visited[100005];

ll dfs(ll x)
{
	visited[x]=true;

	ll mini = cost[x];

	ll len = adj[x].size();

	for(ll i=0; i<len; i++)
	{
		if(visited[adj[x][i]]==false)
		{
			mini = min(mini, dfs(adj[x][i]));
		}
	}

	return mini;
}

int main()
{
	ll n, m;
	cin >> n >> m;

	for(ll i=1; i<=n; i++)
	{
		cin >> cost[i];
	}

	for(ll j=1; j<=m; j++)
	{
		cin >> x[j] >> y[j];

		adj[x[j]].push_back(y[j]);
		adj[y[j]].push_back(x[j]);
	}

	ll ans=0;

	for(ll k=1; k<=n; k++)
	{
		if(visited[k]==false)
		{
			ans+=dfs(k);
		}
	}
	cout << ans << endl;

	return 0;
}