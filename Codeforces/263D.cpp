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

vector <ll> adj[L];
ll visited[L];

vector <ll> store;
vector <ll> ans;

set <ll> sett;

void dfs(ll s)
{
    // cout << "yay " << s << endl;
    store.pb(s);

    visited[s] = true;

    ll f = 0;

    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            f = 1;
            dfs(i);
        }
    }

    if(f==0)
    {
        if(sett.empty())
        {
            for(auto i: adj[s])
            {
                // cout << i << " ";
                sett.insert(i);
            }
            // cout << endl;

            ll done = 0;
            for(auto v: store)
            {
                // cout << v << endl;
                if(!done)
                {
                    if(sett.find(v)!=sett.end())
                    {
                        done = 1;
                    }
                }

                if(done)
                {
                    ans.pb(v);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m, k;
    cin >> n >> m >> k;

    for(ll i=0; i<m; i++)
    {
        ll u, v;
        cin >> u >> v;

        u--;
        v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0);

    cout << sz(ans) << endl;

    for(auto i: ans)
    {
        cout << i+1 << " ";
    }
    cout << endl;

    return 0;
}