using namespace std;

#include <bits/stdc++.h>

typedef long long int ll;

vector <ll> adj[1000005];
vector <ll> adjlist[1000005];
ll store[1000005];
ll flag[1000005];
ll loop[1000005];
ll lengthtemp[1000005];
bool visited[1000005];
vector <ll> ans;

void deleteEdges(vector <ll> adjlist[], ll value)
{
	ll len = adjlist[value].size();

	for(ll i=0; i<len; i++)
	{
		lengthtemp[adjlist[value][i]]--;
	}
}

void dfsVisit(ll x)
{
	visited[x]=true;

	ll len = adj[x].size();

	for(ll j=0; j<len; j++)
	{
		if(visited[adj[x][j]]==false)
		{
			dfsVisit(adj[x][j]);
		}
	}

	ans.push_back(x);
}

void dfs(ll n)
{
	for(ll i=1; i<=n; i++)
	{
		visited[i]=false;
	}

	for(ll i=n; i>0; i--)
	{
		if(visited[i]==false)
		{
			dfsVisit(i);
		}
	}
}

void printAdjList(ll n)
{
	for(ll i=1; i<=n; i++)
	{
		cout << "for " << i << ": ";
		ll len = adjlist[i].size();
		
		for(ll j=0; j<len; j++)
		{
			cout << adjlist[i][j] << " ";
		}
		cout << endl;
	}
}

void printAdj(vector <ll> ans, ll n)
{
	for(ll i=1; i<=n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main()
{
	// visited[0]=true;
	ll n, m;
	cin >> n >> m;

	for(ll i=0; i<m; i++)
	{
		ll a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adjlist[b].push_back(a);

		// indeg[b]++;
	}

	// printAdjList(n);

	for(ll s=1; s<=n; s++)
	{
		lengthtemp[s] = adj[s].size();
	}

	ans.push_back(-5);
	dfs(n);

	// printAdj(ans, n);

	ll cnt=0, cntSteps=0;

	for(ll j=1; j<=n; j++)
	{
		// cout << ans[j] << " " << j << endl;
		ll len1 = lengthtemp[ans[j]];

		ll len2 = 0;
		if(j!=n)
		{
			len2 = lengthtemp[ans[j+1]];
		}

		ll it=0;
		for(ll k=j+1; k<=n; k++)
		{
			if(lengthtemp[ans[k]]==0 && flag[ans[k]]==0)
			{
				it = k;
				break;
			}
		}

		// cout << len1 << " " << len2 << endl;
		if(j!=n && len1==0 && flag[ans[j]]==0 && it!=0)
		{
			deleteEdges(adjlist, ans[j]);
			store[cnt++]=ans[j];
			flag[ans[j]]=1;

			deleteEdges(adjlist, ans[it]);
			store[cnt++]=ans[it];
			flag[ans[it]]=1;
			
			// j++;
			loop[cntSteps++]=2;
		}

		else if(len1==0 && flag[ans[j]]==0)
		{
			deleteEdges(adjlist, ans[j]);
			store[cnt++]=ans[j];
			flag[ans[j]]=1;

			loop[cntSteps++]=1;
		}

		if(cnt==n)
		{
			break;
		}
			
		// if(j==n)
		// {
		// 	j=0;
		// }
	}

	cout << cntSteps << endl;

	ll go=0;
	for(ll k=0; k<cntSteps; k++)
	{
		if(loop[k]==1)
		{
			cout << "1 " << store[go++] << endl;
		}

		else if(loop[k]==2)
		{
			ll a = store[go++];
			ll b = store[go++];
			cout << "2 " << a << " " << b << endl;
		}
	}

	return 0;
}