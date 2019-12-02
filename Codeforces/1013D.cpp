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

const ll L = 2e5+5;

vector <ll> adj[2*L];
bool visited[2*L];

void dfs(ll s)
{
    visited[s] = true;

    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m, q;
    cin >> n >> m >> q;

    for(ll i=0; i<q; i++)
    {
        ll r, c;
        cin >> r >> c;

        c+=L;

        adj[r].pb(c);
        adj[c].pb(r);
    }

    ll ans = -1;

    for(ll i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            ans++;

            dfs(i);
        }
    }

    for(ll i=1; i<=m; i++)
    {
        if(!visited[i+L])
        {
            ans++;

            dfs(i+L);
        }
    }

    cout << ans << endl;

    return 0;
}