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

const ll L = 8e5 + 5;
const ll LOG = 22;

vector <ll> adj[L];
ll f[L];

ll up[LOG][L];
ll level[L];

// ll cnt = 0;

void dfs(ll s, ll par)
{
    // cout << "source and par are: " << s << " " << par << " " << cnt++ << endl;
    up[0][s] = par;

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
    for(ll j = 1; j < LOG; j++)
    {
        for(ll i = 1; i <= n; i++)
        {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }
}

ll get_kth_ancestor(ll a, ll k)
{
    for(ll j = 0; j < LOG; j++)
    {
        if(k & (1LL << j))
        {
            a = up[j][a];
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
        if(up[j][a] != up[j][b])
        {
            a = up[j][a];
            b = up[j][b];
        }
    }

    assert(up[0][a] == up[0][b]);
    return up[0][a];
}


void solve()
{
    ll n = nxt();

    // cout << "n done" << endl;


    for(ll i = 1; i <= n; i++)
    {
        adj[i].clear();
        f[i] = 0;
        level[i] = 0;

        for(ll j = 0; j < LOG; j++)
        {
            up[j][i] = 0;
        }
    }

    // cout << "clear" << endl;

    map <pll, ll> blocked;

    for(ll i = 1; i < n; i++)
    {
        ll a = nxt(), b = nxt();
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(ll i = 1; i <= n; i++)
    {
        cin >> f[i];
    }

    // cout << "scan done" << endl;

    dfs(1, 1);

    // cout << "dfs done" << endl;

    binary_lifting(n);

    // cout << "LCA done" << endl;

    vector <ll> cur(n + 1, -1);

    for(ll i = 1; i <= n; i++)
    {
        if(cur[f[i]] == -1)
        {
            cur[f[i]] = i;
        }

        else
        {
            ll u = cur[f[i]];
            ll v = i;

            ll x = lca(u, v);

            cur[f[i]] = x;

            while(u != x)
            {
                ll p = up[0][u];

                if(blocked[mp(p, u)] == 1)
                {
                    break;
                }

                blocked[mp(p, u)] = 1;
                blocked[mp(u, p)] = 1;

                u = p;
            }

            while(v != x)
            {
                ll p = up[0][v];

                if(blocked[mp(p, v)] == 1)
                {
                    break;
                }

                blocked[mp(p, v)] = 1;
                blocked[mp(v, p)] = 1;

                v = p;
            }
        }
    }

    ll total = 0;

    for(auto i: blocked)
    {
        if(i.ff.ff != i.ff.ss)
        {
            total += i.ss;
        }

        cout << i << endl;
    }

    assert(total % 2 == 0);
    total /= 2;

    ll ans = (n - 1) - total;

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    T = nxt();

    for(ll i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
