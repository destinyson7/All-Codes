#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 1e5+5;

vector <ll> adj[L];
vector <ll> visited(L);

ll mod = 1e9+7;
ll cnt = 0;
ll k;

ll modexp(ll a, ll b, ll mod)
{
	ll ans = 1;

	while(b)
	{
		if(b&1)
		{
			ans = (ans*a)%mod;
		}

		b/=2;
		a = (a*a)%mod;
	}

	return ans;
}

void dfs(ll s)
{
	visited[s] = 1;

	for(ll i=0; i<adj[s].size(); i++)
	{
		if(!visited[adj[s][i]])
		{
			cnt++;
			dfs(adj[s][i]);
		}
	}
}

ll dfsVisit(ll n)
{
	ll ans = 0;
	for(ll i=0; i<n; i++)
	{
		if(!visited[i])
		{
			cnt = 1;
			dfs(i);
			ans+=modexp(cnt, k, mod);
			ans%=mod;

			// cout << ans << endl;
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n >> k;

	for(ll i=0; i<n-1; i++)
	{
		ll u, v, x;
		cin >> u >> v >> x;

		if(!x)
		{
			adj[u-1].pb(v-1);
			adj[v-1].pb(u-1);
		}
	}

	ll ans = modexp(n, k, mod);

	ans -= dfsVisit(n);

	ans%=mod;

	while(ans<0)
	{
		ans+=mod;
	}

	cout << ans << endl;

	return 0;
}