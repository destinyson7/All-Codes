using namespace std;

#include <bits/stdc++.h>

typedef long long int ll;

vector <ll> adj[1000005];
ll u[1000005];
ll v[1000005];
ll store[1000005];
ll flag[1000005];
ll loop[1000005];
vector <pair <ll, ll> > length(1000005);

void deleteEdges(vector <ll> adj[], ll adjsize, ll element)
{
	for(ll i=1; i<=adjsize; i++)
	{
		ll len = adj[i].size();
		for(ll j=0; j<len; j++)
		{
			if(adj[i][j]==element)
			{
				adj[i].erase(adj[i].begin()+j);
				j--;
				len--;
			}
		}
	}
}

int main()
{
	ll n, m;
	cin >> n >> m;

	for(ll i=0; i<m; i++)
	{
		cin >> u[i] >> v[i];
		
		adj[u[i]].push_back(v[i]);
	}

	for(ll s=1; s<=n; s++)
	{
		length[s] = make_pair(adj[s].size(), s);
	}

	sort(length.begin()+1, length.begin()+n+1);

	ll cnt=0, cntSteps=0;

	for(ll j=1; j<=n; j++)
	{
		ll len1 = adj[length[j].second].size();

		ll len2=0;
		if(j!=n)
		{
			len2 = adj[length[j+1].second].size();
		}

		if(j!=n && len1==0 && flag[length[j].second]==0 && len2==0 && flag[length[j+1].second]==0)
		{
			deleteEdges(adj, n, length[j].second);
			store[cnt++]=length[j].second;
			flag[length[j].second]=1;

			deleteEdges(adj, n, length[j+1].second);
			store[cnt++]=length[j+1].second;
			flag[length[j+1].second]=1;
			j++;
			loop[cntSteps++]=2;
		}

		else if(len1==0 && flag[length[j].second]==0)
		{
			deleteEdges(adj, n, length[j].second);
			store[cnt++]=length[j].second;
			flag[length[j].second]=1;

			loop[cntSteps++]=1;
		}

		if(cnt==n)
		{
			break;
		}
			
		if(j==n)
		{
			j=0;
		}

		// if(length[j+1].first==0 && flag[j+2]==0)
		// {
		// 	deleteedges(adj, n, length[j+1].second);

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