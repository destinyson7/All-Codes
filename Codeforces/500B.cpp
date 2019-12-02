#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

vector <ll> p(305);
vector <ll> adj[305];
vector <ll> visited(305);
vector <ll> ans[305];
vector <ll> c(305);
vector <ll> k(305);

ll cnt = 0;

void dfs(ll s, ll cnt)
{
	visited[s]=1;

	for(ll i=0; i<(ll)adj[s].size(); i++)
	{
		if(!visited[adj[s][i]])
		{
			ans[cnt].pb(adj[s][i]);
			c[adj[s][i]]=cnt;
			dfs(adj[s][i], cnt);
		}
	}

}

void dfsVisit(ll n)
{
	for(ll i=0; i<n; i++)
	{
		if(visited[i]==0)
		{
			ans[cnt].pb(i);
			c[i] = cnt;
			dfs(i, cnt);
			cnt++;
		}
	}
}

void printAdjList(vector <ll> adj[], ll n)
{
	for(ll i=0; i<n; i++)
	{
		cout << "For " << i+1 << ": ";
		for(ll j=0; j<(ll)adj[i].size(); j++)
		{
			cout << adj[i][j]+1 << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	for(ll i=0; i<n; i++)
	{
		cin >> p[i];
	}

	for(ll i=0; i<n; i++)
	{
		string t;
		cin >> t;
		for(ll j=0; j<(ll)t.size(); j++)
		{
			// ll t;
			// cin >> t;

			if(t[j]=='1')
			{
				adj[p[i]-1].pb(p[j]-1);
				// adj[p[j]-1].pb(p[i]-1);
			}
		}
	}

	// printAdjList(adj, n);

	dfsVisit(n);

	for(ll i=0; i<cnt; i++)
	{
		sort(ans[i].begin(), ans[i].end());
	}

	// printAdjList(ans, cnt);

	for(ll i=0; i<n; i++)
	{
		// cout << c[p[i]-1] << " ";
		cout << ans[c[p[i]-1]][k[c[p[i]-1]]++]+1 << " ";
	}
	cout << endl;

	return 0;
}