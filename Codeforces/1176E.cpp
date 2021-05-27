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

vector <ll> adj[L];
// ll deg[L];
bool visited[L];
ll group[L];

void dfs(ll s, ll grp)
{
    visited[s] = true;
    group[s] = grp;

    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            dfs(i, grp^1);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        ll n, m;
        cin >> n >> m;

        for(ll i=0; i<=n; i++)
        {
            visited[i] = false;
            group[i] = 0;
            adj[i].clear();
        }
        // first.clear();
        // second.clear();

        for(ll i=0; i<m; i++)
        {
            ll u, v;
            cin >> u >> v;

            // deg[u]++;
            // deg[v]++;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        // sort(deg+1, deg+n+1);

        dfs(1, 1);

        vector <ll> first;
        vector <ll> second;

        for(ll i=1; i<=n; i++)
        {
            if(group[i]==1)
            {
                first.pb(i);
            }

            else
            {
                second.pb(i);
            }
        }

        cout << min(sz(first), sz(second)) << endl;

        if(sz(first) <= sz(second))
        {
            for(auto i: first)
            {
                cout << i << " ";
            }
            cout << endl;
        }

        else
        {
            for(auto i: second)
            {
                cout << i << " ";
            }
            cout << endl;
        }

    }



    return 0;
}
