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

const ll L = 5e3+5;

vector <pll> adj[L];
ll weights[L];
vector <pll> edges;
ll a[L], b[L], g[L];

bool dfs(ll src, ll tar, ll weight, ll par)
{
    if(src == tar)
    {
        return true;
    }

    for(auto i: adj[src])
    {
        if(i.ff == par)
        {
            continue;
        }

        if(dfs(i.ff, tar, weight, src))
        {
            weights[i.ss] = max(weights[i.ss], weight);
            return true;
        }
    }

    return false;
}

ll dfs2(ll src, ll tar, ll par)
{
    if(src == tar)
    {
        return 1e15;
    }

    for(auto i: adj[src])
    {
        if(i.ff == par)
        {
            continue;
        }

        ll temp = dfs2(i.ff, tar, src);

        if(temp != -1)
        {
            return min(temp, weights[i.ss]);
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    for(ll i=0; i<L; i++)
    {
        weights[i] = 1;
    }

    for(ll i=0; i<n-1; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].pb(mp(v, i));
        adj[v].pb(mp(u, i));
        edges.pb(mp(u, v));
    }

    ll m;
    cin >> m;

    for(ll i=0; i<m; i++)
    {
        cin >> a[i] >> b[i] >> g[i];

        dfs(a[i], b[i], g[i], -1);
    }

    for(ll i=0; i<m; i++)
    {
        ll mi = dfs2(a[i], b[i], -1);

        if(mi != g[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }

    for(ll i=0; i<n-1; i++)
    {
        cout << weights[i] << " ";
    }
    cout << endl;

    return 0;
}