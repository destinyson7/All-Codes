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
vector <ll> adj[L];
bool visited[L];
vector <pll> edges;

void dfs(ll s, ll j)
{
    assert(!visited[s]);
    visited[s] = true;

    for(auto i: adj[s])
    {
        if(mp(s, i) == edges[j])
        {
            continue;
        }

        if(!visited[i])
        {
            dfs(i, j);
        }
    }
}

void solve(ll n, ll m)
{
    // ll n = nxt(), m = nxt();

    for(ll i=0; i<=n; i++)
    {
        adj[i].clear();
        visited[i] = false;
        edges.clear();
    }

    for(ll i = 0; i < m; i++)
    {
        ll a = nxt(), b = nxt();
        adj[a].pb(b);
        adj[b].pb(a);

        // edges.pb(mp(min(a, b), max(a, b)));
        edges.pb(mp(a, b));
        edges.pb(mp(b, a));
    }


    for(ll j = 0; j < 2 * m; j++)
    {
        ll cc = 0;

        for(ll i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        for(ll i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i, j);
                cc++;
            }
        }

        if(cc > 1)
        {
            // cout << "Edge: " << j << endl;
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // T = nxt();

    while(true)
    {
        ll p = nxt(), c = nxt();

        if(p + c == 0)
        {
            break;
        }

        solve(p, c);
    }

    return 0;
}
