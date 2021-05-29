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

vector <ll> adj[L];
ll arr[L];
ll dep[L];
double seg[4 * L];
double a[L];

ll timer = 1;

double merge(double aa, double bb)
{
    return aa + bb;
}

void build(ll pos, ll tl, ll tr)
{
    // cout << pos << " " << tl << " "  << tr << " " << f << endl;
    if(tl == tr)
    {
        seg[pos] = a[tl];
        return;
    }

    ll mid = tl + (tr-tl)/2;

    build(2*pos, tl, mid);
    build(2*pos+1, mid+1, tr);

    seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
}

void update(ll pos, ll tl, ll tr, ll idx, double val)
{
    if(tl == tr)
    {
        seg[pos] = val;
        return;
    }

    ll mid = tl + (tr-tl)/2;

    if(tl <= idx && idx <= mid)
    {
        update(2*pos, tl, mid, idx, val);
    }

    else
    {
        update(2*pos+1, mid+1, tr, idx, val);
    }

    seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
}

double query(ll pos, ll tl, ll tr, ll l, ll r)
{
    if(tl > r || tr < l)
    {
        return 0;
    }

    if(tl >= l && tr <= r)
    {
        return seg[pos];
    }

    ll mid = tl + (tr-tl)/2;

    return merge(query(2*pos, tl, mid, l, r), query(2*pos+1, mid+1, tr, l, r));
}

void dfs(ll s, ll par)
{
    arr[s] = timer;

    for(auto i: adj[s])
    {
        if(i != par)
        {
            timer++;
            dfs(i, s);
        }
    }

    dep[s] = timer;
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
    build(1, 1, n);

    ll q = nxt();

    double logma = log(1e9);

    while(q--)
    {
        ll t = nxt(), x = nxt(), y = nxt();

        if(t == 1)
        {
            update(1, 1, n, arr[x], (double)log(y));
        }

        else
        {
            double ff = query(1, 1, n, arr[x], dep[x]);
            double ss = query(1, 1, n, arr[y], dep[y]);

            // cout << ff << " "  << ss << endl;

            if(ff - ss > logma)
            {
                cout << fixed << setprecision(10) << 1e9 << endl;
            }

            else
            {
                cout << fixed << setprecision(10) << exp(ff - ss) << endl;
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
