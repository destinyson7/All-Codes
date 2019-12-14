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

const ll L = 2e5+5;

vector <ll> adj[L];
bool visited[L];

ll a, b;

set <ll> s1, s2;

void dfs1(ll s)
{
    assert(!visited[s]);
    visited[s] = true;

    s1.insert(s);

    for(auto i: adj[s])
    {
        if(!visited[i] && i != b)
        {
            dfs1(i);
        }
    }
}

void dfs2(ll s)
{
    assert(!visited[s]);
    visited[s] = true;

    s2.insert(s);

    for(auto i: adj[s])
    {
        if(!visited[i] && i != a)
        {
            dfs2(i);
        }
    }
}


void solve()
{
    ll n, m;
    cin >> n >> m >> a >> b;

    s1.clear();
    s2.clear();

    for(ll i=0; i<=n; i++)
    {
        adj[i].clear();
        visited[i] = false;
    }

    for(ll i=0; i<m; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs1(a);

    for(ll i=0; i<=n; i++)
    {
        visited[i] = false;
    }

    dfs2(b);
    
    vector <ll> remove1, remove2;

    for(auto i: s1)
    {
        if(s2.find(i) != s2.end())
        {
            remove1.pb(i);
            // s1.erase(i);
            s2.erase(i);
        }
    }

    for(auto i: s2)
    {
        if(s1.find(i) != s1.end())
        {
            remove2.pb(i);
            // s2.erase(i);
            s1.erase(i);
        }
    }
    
    for(auto i: remove1)
    {
        s1.erase(i);
    }
    
    for(auto i: remove2)
    {
        s2.erase(i);
    }

    ll cnt1 = sz(s1) - 1;
    ll cnt2 = sz(s2) - 1;
    
    cout << cnt1*cnt2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}