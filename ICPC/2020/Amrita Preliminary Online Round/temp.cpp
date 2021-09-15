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

ll par[L];
ll union_siz[L];
ll a[L];
vector <ll> adj[L];

ll find(ll x)
{
    if(par[x] == x)
    {
        return x;
    }

    return par[x] = find(par[x]);
}

void merge_set(ll a, ll b)
{
    a = find(a);
    b = find(b);

    if(union_siz[a] > union_siz[b])
    {
        swap(a, b);
    }

    par[a] = b;
    union_siz[b] += union_siz[a];
}

void solve()
{
    ll n = nxt(), m = nxt();

    vector <pll> v;

    vector <pair<ll, pll>> edge_list;

    for(ll i = 1; i <= n; i++)
    {
        // a[i] = 0;
        adj[i].clear();
        cin >> a[i];
        v.pb(mp(a[i], i));
    }

    sort(all(v));

    for(ll i = 1; i < n; i++)
    {
        adj[v[i].ss].pb(v[i - 1].ss);
        adj[v[i - 1].ss].pb(v[i].ss);
        ll cur_weight = abs(v[i].ff - v[i - 1].ff);
        edge_list.pb(mp(cur_weight, mp(v[i].ss, v[i-1].ss)));
        // edge_list.pb(mp(cur_weight, mp(v[i - 1].ss, v[i].ss)));
    }

    for(ll i = 0; i < m; i++)
    {
        ll u = nxt(), v = nxt();
        adj[u].pb(v);
        adj[v].pb(u);
        edge_list.pb(mp(0LL, mp(u, v)));
    }

    for(ll i = 0; i <= n; i++)
    {
        par[i] = i;
        union_siz[i] = 1;
    }

    sort(all(edge_list));

    ll ans = 0;
    ll k = 0;

    vector <pll> final_ans;

    for(ll i = 0; i < sz(edge_list); i++)
    {
        if(find(edge_list[i].ss.ff) != find(edge_list[i].ss.ss))
        {
            ans += edge_list[i].ff;
            merge_set(edge_list[i].ss.ff, edge_list[i].ss.ss);

            final_ans.pb(edge_list[i].ss);
            k++;
        }
    }

    cout << ans << " " << k << endl;

    for(ll i = 0; i < k; i++)
    {
        cout << final_ans[i].ff << " " << final_ans[i].ss << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}
