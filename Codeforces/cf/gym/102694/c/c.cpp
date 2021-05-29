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

const ll L = 3e5+5;
const ll LOG = 20;

vector <ll> adj[L];
ll level[L];
ll parent[L];
ll up[L][LOG];

void dfs(ll s, ll par)
{
    parent[s] = par;

    if(par != s)
    {
        level[s] = level[par] + 1;
    }

    for(auto i: adj[s])
    {
        if(i != par)
        {
            dfs(i, s);
        }
    }
}

void binary_lifting(ll n)
{
    for(ll i = 1; i <= n; i++)
    {
        up[i][0] = parent[i];
    }

    for(ll j = 1; j < LOG; j++)
    {
        for(ll i = 1; i <= n; i++)
        {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

ll get_kth_ancestor(ll a, ll k)
{
    for(ll j = 0; j < LOG; j++)
    {
        if(k & (1LL << j))
        {
            a = up[a][j];
        }
    }

    return a;
}

ll lca(ll a, ll b)
{
    if(level[a] > level[b])
    {
        swap(a, b);
    }

    ll k = level[b] - level[a];
    b = get_kth_ancestor(b, k);

    if(a == b)
    {
        return a;
    }

    for(ll j = LOG - 1; j >= 0; j--)
    {
        if(up[a][j] != up[b][j])
        {
            a = up[a][j];
            b = up[b][j];
        }
    }

    assert(up[a][0] == up[b][0]);
    return up[a][0];
}

void solve()
{
    ll n = nxt();
    ll m = n - 1;

    for(ll i = 0; i < m; i++)
    {
        ll u = nxt(), v = nxt();
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 1);
    binary_lifting(n);

    ll q = nxt();

    while(q--)
    {
        ll a = nxt(), b = nxt(), c = nxt();

        ll lcaq = lca(a, b);

        if(c <= (level[a] - level[lcaq]))
        {
            cout << get_kth_ancestor(a, c) << endl;
        }

        else
        {
            c -= (level[a] - level[lcaq]);

            if(c <= (level[b] - level[lcaq]))
            {
                cout << get_kth_ancestor(b, level[b] - level[lcaq] - c) << endl;
            }

            else
            {
                cout << b << endl;
            }
        }
    }
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
