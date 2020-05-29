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

const ll L = 1e5+5;

vector <pll> adj[L];
ll dis[L];
vector<pair<pll, ll>> edges;

void dijkstras(ll src)
{
    dis[src] = 0;

    priority_queue <pll, vector<pll>, greater<pll>> pq;
    pq.push(mp(0, src));

    while(!pq.empty())
    {
        pll top = pq.top();
        ll w = top.ff;
        ll v = top.ss;
        pq.pop();

        if(dis[v] < w)
        {
            continue;
        }

        for(auto i: adj[v])
        {
            if(dis[i.ff] > i.ss + w)
            {
                dis[i.ff] = i.ss + w;
                pq.push(mp(dis[i.ff], i.ff));
            }
        }   
    }
}

void solve()
{
    ll n = nxt(), m = nxt(), s = nxt() - 1;

    for(ll i=0; i<=n; i++)
    {
        dis[i] = 1e18;
    }

    for(ll i=0; i<m; i++)
    {
        ll u = nxt() - 1, v = nxt() - 1, w = nxt();

        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));

        edges.pb(mp(mp(u, v), w));
    }

    ll l = nxt();

    dijkstras(s);

    ll ans = 0;

    for(ll i=0; i<n; i++)
    {
        if(dis[i] == l)
        {
            ans++;
        }
    }

    // cout << ans << endl;

    for(ll i=0; i<m; i++)
    {
        if(l - dis[edges[i].ff.ff] > 0 && l - dis[edges[i].ff.ff] < edges[i].ss && edges[i].ss + dis[edges[i].ff.ff] + dis[edges[i].ff.ss] >= 2*l)
        {
            ans++;
        }

        if(l - dis[edges[i].ff.ss] > 0 && l - dis[edges[i].ff.ss] < edges[i].ss && edges[i].ss + dis[edges[i].ff.ff] + dis[edges[i].ff.ss] > 2*l)
        {
            ans++;
        }

        // cout << ans << endl;
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