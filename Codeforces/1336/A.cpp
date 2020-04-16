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

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

const ll L = 2e5+5;
vector <ll> adj[L];
ll depth[L];
ll siz[L];

void dfs(ll src, ll par)
{
    for(auto i: adj[src])
    {
        if(i == par)
        {
            continue;
        }

        depth[i] = depth[src] + 1;
        dfs(i, src);
        siz[src] += siz[i];
    }
}

void solve()
{
    ll n = nxt(), k = nxt();

    for(ll i=0; i<=n; i++)
    {
        siz[i] = 1;
    }

    for(ll i=0; i<n-1; i++)
    {
        ll u = nxt() - 1, v = nxt() - 1;
        
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0, -1);

    basic_string <ll> vals;

    for(ll i=0; i<n; i++)
    {
        vals += (depth[i] - siz[i] + 1);
    }

    sort(all(vals));
    reverse(all(vals));

    ll ans = 0;

    for(ll i=0; i<k; i++)
    {
        ans += vals[i];
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    // T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}