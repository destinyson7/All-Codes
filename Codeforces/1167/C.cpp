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

const ll L = 5e5+5;

ll n;

ll k[L];
ll visited[L];
ll ans[L];

vector <ll> adj[L];
ll cnt = 0;

vector <ll> store[L];

void dfs(ll s)
{
    store[cnt].pb(s);
    visited[s] = true;

    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}

void dfsVisit()
{
    for(ll i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll m;
    cin >> n >> m;

    for(ll i=0; i<m; i++)
    {
        cin >> k[i];
        
        vector <ll> v;

        for(ll j=0; j<k[i]; j++)
        {
            ll a;
            cin >> a;
            
            v.pb(a);
        }

        // for(ll j=0; j<k[i]; j++)
        // {
        //     cout << v[j] << " ";
        // }
        // cout << endl;
        // cout << "size " << v.size() << endl;

        for(ll j=0; j<k[i]-1; j++)
        {
            // cout << "vector: " << v[j] << " " << v[j+1] << endl;
            adj[v[j]].pb(v[j+1]);
            adj[v[j+1]].pb(v[j]);

            // cout << "check:" << adj[2][0] << endl;
        }
    }

    // cout << "Adj List" << endl;
    // for(ll i=1; i<=n; i++)
    // {
    //     cout << i << ": ";
    //     for(ll j=0; j<sz(adj[i]); j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;

    // }

    dfsVisit();

    for(ll i=0; i<cnt; i++)
    {
        ll cur = sz(store[i]);
        for(ll j=0; j<cur; j++)
        {
            ans[store[i][j]] = cur;
        }
    }

    for(ll i=1; i<=n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}