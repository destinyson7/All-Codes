using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

typedef long long int ll;

vector <ll> adj[300005];
bool visited[300005];
ll temp[300005];
ll u[300005];
ll v[300005];

ll odd = 0, even = 0;

ll modmul(ll a, ll b, ll c)
{
	ll ans=0;

	a%=c;

	while(b)
	{
		if(b&1)
		{
			ans=((ans+a)%c);
		}

		b >>= 1;
		a=(a*2)%c;
	}

	return ans;
}

ll dfs(ll x, ll v)
{
	temp[x] = v;
	visited[x]=true;

	if(v==0)
	{
		odd++;
	}

	else
	{
		even++;
	}

	ll ans = 1;

	ll len = adj[x].size();

	for(ll i=0; i<len; i++)
	{
		if(visited[adj[x][i]]==true)
		{
			if(temp[adj[x][i]]!=(v+1)%2)
			{
				ans = 0;
			}
		}

		else
		{
			ans = dfs(adj[x][i], (v+1)%2);
		}

		if(ans==0)
		{
			break;
		}		
	}

	return ans;
}

int main()
{
	ll t;
	cin >> t;

	ll mod = 998244353;

	while(t--)
	{
		ll n, m;
		cin >> n >> m;

		for(ll i=0; i<m; i++)
		{
			cin >> u[i] >> v[i];

			adj[v[i]].push_back(u[i]);
			adj[u[i]].push_back(v[i]);
		}

		ll flag = 1;
		ll final = 0;

		for(ll j=1; j<=n; j++)
		{
			odd=0;
			even=0;

			if(visited[j]==false)
			{				
				flag = dfs(j, 0);

				if(flag==0)
				{
					break;
				}

				ll res = 0;
				ll pr = 1;

				for(ll k=0; k<even; k++)
				{
					pr = modmul(pr, 2, mod);
				}

				res = (res+pr)%mod;

				ll pr2=1;

				for(ll p=0; p<odd; p++)
				{
					pr2 = modmul(pr2, 2, mod);
				}

				res = (res+pr2)%mod;

				if(final==0)
				{
					final = res;
				}

				else
				{
					final = modmul(final, res, mod);
				}
			}
		}

		if(flag==0)
		{
			cout << "0" << endl;
		}

		else
		{
			cout << final << endl;
		}

		for(ll o=1; o<=n; o++)
		{
			visited[o]=false;
			temp[o]=0;

			adj[o].clear();			
		}
	}	

	return 0;
}