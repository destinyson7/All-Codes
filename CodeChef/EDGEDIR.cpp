#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

vector <pll> adj[L];
vector <pll> edges;
bool visited[L];
ll level[L];
ll ans[L];

ll dfs(ll s, ll par, ll lev)
{
	level[s] = lev;
	visited[s] = true;

	ll t = 0;
	ll indeg = 0;

	for(auto i: adj[s])
	{
		if(!visited[i.ff])
		{
			indeg+=dfs(i.ff, s, lev+1);
		}
		
		else if(i.ff == par)
		{
			t = i.ss;
		}

		else
		{
			if(level[i.ff] < level[s])
			{
				indeg++;

				if(edges[i.ss].ff == s)
				{
					ans[i.ss] = 1;
				}

				else
				{
					ans[i.ss] = 0;
				}
			}
		}
	}

	if(indeg&1)
	{
		if(edges[t].ff == s)
		{
			ans[t] = 1;
		}

		else
		{
			ans[t] = 0;
		}

		return 0;
	}

	else
	{
		if(edges[t].ff == s)
		{
			ans[t] = 0;
		}

		else
		{
			ans[t] = 1;
		}

		return 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll T;
	cin >> T;

	while(T--)
	{
		for(ll i=0; i<L; i++)
		{
			level[i] = 0;
			visited[i] = false;
			adj[i].clear();

			ans[i] = 0;
			// edges[i] = mp(0, 0);
		}
		edges.clear();

		ll N, M;
		cin >> N >> M;

		edges.pb(mp(-1, -1));

		for(ll i=1; i<=M; i++)
		{
			ll u, v;
			cin >> u >> v;

			u--;
			v--;

			adj[u].pb(mp(v, i));
			adj[v].pb(mp(u, i));

			edges.pb(mp(u, v));
		}

		if(M&1)
		{
			cout << -1 << endl;
		}

		else
		{
			dfs(0, 0, 1);

			for(ll i=1; i<=M; i++)
			{
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}