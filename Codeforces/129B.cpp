using namespace std;

#include <iostream>
#include <vector>

typedef long long int ll;

vector<ll> adj[105];

bool visited[105];
ll deg[105];
ll deg2[105];
ll flag=0;

void dfs(ll x)
{
	visited[x]=true;

	ll len = adj[x].size();

	for(ll i=0; i<len; i++)
	{
		if(deg[x]==1)
		{
			deg2[x]=0;
			deg2[adj[x][i]]--;
			flag=1;
		}

		if(visited[adj[x][i]]==false)
		{
			dfs(adj[x][i]);
		}
	}
}

int main()
{
	ll n, m;
	cin >> n >> m;

	for(ll i=1; i<=m; i++)
	{
		ll a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(ll j=1; j<=n; j++)
	{
		deg[j] = adj[j].size();
		deg2[j] = deg[j];
	}

	ll ans = 0;

	ll temp=n;
	while(temp--)	
	{
		if(flag==1)
		{
			ans++;
			flag=0;
		}

		for(ll k=1; k<=n; k++)
		{
			deg[k]=deg2[k];
			visited[k]=0;
		}

		for(ll o=1; o<=n; o++)
		{
			if(visited[o]==false)
			{
				dfs(o);
			}
		}
	}

	cout << ans << endl;

	return 0;
}