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

const ll L = 2e4 + 5;
const ll LOG = 20;

vector <ll> adj[L];

ll level[L][2];
ll up[LOG][L][2];

void dfs(ll s, ll par, ll ind)
{
    up[0][s][ind] = par;

    if(par != s)
    {
        level[s][ind] = level[par][ind] + 1;
    }

    for(auto i: adj[s])
    {
        if(i != par)
        {
            dfs(i, s, ind);
        }
    }
}

void binary_lifting(ll n)
{
    for(ll j = 1; j < LOG; j++)
    {
        for(ll i = 1; i <= n; i++)
        {
            up[j][i][0] = up[j - 1][up[j - 1][i][0]][0];
            up[j][i][1] = up[j - 1][up[j - 1][i][1]][1];
        }
    }
}

ll get_kth_ancestor(ll a, ll k, ll ind)
{
    for(ll j = 0; j < LOG; j++)
    {
        if(k & (1LL << j))
        {
            a = up[j][a][ind];
        }
    }

    return a;
}

ll far[L][2];

void find_farthest(ll src, ll par, ll ind)
{
    if(src != par)
    {
        far[src][ind] = far[par][ind] + 1;
    }

    for(auto i: adj[src])
    {
        if(i != par)
        {
            find_farthest(i, src, ind);
        }
    }
}

void solve()
{
    ll n = nxt(), q = nxt();

    // cout << "** " << n << " " << q << endl;

    for(ll i = 1; i < n; i++)
    {
        ll u = nxt(), v = nxt();
        adj[u].pb(v);
        adj[v].pb(u);
    }

    find_farthest(1, 1, 0);

    ll farthest1 = 1;

    for(ll i = 1; i <= n; i++)
    {
        if(far[i][0] > far[farthest1][0])
        {
            farthest1 = i;
        }
    }

    find_farthest(farthest1, farthest1, 1);

    ll farthest2 = 1;

    for(ll i = 1; i <= n; i++)
    {
        if(far[i][1] > far[farthest2][1])
        {
            farthest2 = i;
        }
    }

    dfs(farthest1, farthest1, 0);
    dfs(farthest2, farthest2, 1);

    binary_lifting(n);

    // cout << "** " <<  farthest1 << " " << farthest2 << endl;

    while(q--)
    {
        ll v = nxt(), d = nxt();

        if(level[v][0] >= d)
        {
            cout << get_kth_ancestor(v, d, 0) << endl;
        }

        else if(level[v][1] >= d)
        {
            cout << get_kth_ancestor(v, d, 1) << endl;
        }

        else
        {
            cout << 0 << endl;
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
