#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) 
{
    os << "{ ";
    for(auto& y : x) 
    {
        os << y << " ";
    }
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) 
{
    return os << "[" << p.ff << ", " << p.ss << "]";
}

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

ll modexp(ll a, ll b, ll c)
{   
    a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b >>= 1;
    }

    return ans;
}

const ll L = 1e5+5;

vector <ll> adj[L];
ll sz[L];
ll parent[L];

void dfs(ll src, ll par)
{
    sz[src] = 1;
    parent[src] = par;
    
    for(auto i: adj[src])
    {
        if(i == par)
        {
            continue;
        }

        dfs(i, src);

        sz[src] += sz[i];
    }
}

void solve()
{
    ll n;
    cin >> n;

    for(ll i=0; i<=n; i++)
    {
        adj[i].clear();
        sz[i] = 0;
        parent[i] = 0;
    }

    for(ll i=0; i<n-1; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    if(n & 1)
    {
        for(ll i=0; i<n; i++)
        {
            cout << 0;
        }
        cout << endl;

        return;
    }

    dfs(1, 1);

    for(ll i=1; i<=n; i++)
    {
        vector <ll> check;

        check.pb(n-sz[i]);

        for(auto j: adj[i])
        {
            if(j != parent[i])
            {
                check.pb(sz[j]);
            }
        }

        sort(all(check));        
            
        ll nodes = 0;

        for(ll j=0; j<sz(check)-1; j++)
        {
            nodes += check[j];
        }

        nodes++;

        if(nodes >= n/2)
        {
            cout << 1;
        }

        else
        {
            cout << 0;
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        solve();
    }

    return 0;
}