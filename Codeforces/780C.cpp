using namespace std;

#include <iostream>
#include <vector>

typedef long long int ll;

vector<ll> adj[200005];

ll x[200005];
ll y[200005];
ll color[200005];
bool visited[200005];

void dfs(ll current, ll parent)
{	
	// cout << current << endl;
	ll len = adj[current].size();

	if(visited[current]==true)
	{
		return ;
	}

	visited[current]=true;
	ll iter=1;
	
	for(ll i=0; i<len; i++)
	{
		if(visited[adj[current][i]]==false)
		{	
			if(color[current]==iter)
			{
				iter++;
			}

			if(color[parent]==iter)
			{
				iter++;
			}

			if(color[current]==iter)
			{
				iter++;
			}

			color[adj[current][i]]=iter;
			dfs(adj[current][i], current);
			iter++;
		}
	}

}

int main()
{
	ll n;
	cin >> n;

	for(ll i=1; i<n; i++)
	{
		cin >> x[i] >> y[i];

		adj[x[i]].push_back(y[i]);
		adj[y[i]].push_back(x[i]);
	}	

	color[1]=1;
	dfs(1, 0);

	ll cnt=0;
	for(ll m=1; m<=n; m++)
	{
		cnt = max(cnt, color[m]);
	}

	cout << cnt << endl;
	for(ll k=1; k<=n; k++)
	{
		cout << color[k] << " ";
	}
	cout << endl;

	return 0;
}