#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const int L = 2e5+5;

vector <ll> c(L);
vector <ll> a(L);
vector <ll> visited(L);

ll ans = 0;

void dfs(ll s)
{
	visited[s] = 1;

	if(a[s]==s)
	{
		ans+=c[a[s]];
		return;
	}

	if(!visited[s])
	{
		dfs(a[s]);
	}

	else
	{
		ll toAdd = c[a[s]];
	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	for(ll i=1; i<=n; i++)
	{
		cin >> c[i];
	}

	// ll cnt = 0;

	for(ll i=1; i<=n; i++)
	{
		cin >> a[i];
	}





	return 0;
}