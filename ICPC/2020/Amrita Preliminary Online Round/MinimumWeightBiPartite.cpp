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

const ll L = 1e5 + 5;

ll a[L];
vector <ll> adj[L];
bool visited[L];
ll comp[L];
ll par[L];
ll union_siz[L];
vector <ll> comp_list[L];

void dfs(ll s, ll num)
{
    visited[s] = true;
    comp[s] = num;

    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            dfs(i, num);
        }
    }
}

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

    for(ll i = 1; i <= n; i++)
    {
        // a[i] = 0;
        adj[i].clear();
        comp_list[i].clear();
        visited[i] = false;
        comp[i] = 0;
        cin >> a[i];
    }

    for(ll i = 0; i < m; i++)
    {
        ll u = nxt(), v = nxt();
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll cnt = 1;

    for(ll i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i, cnt);
            cnt++;
        }
    }

    vector <pair<ll, pll>> v;

    for(ll i = 1; i <= n; i++)
    {
        v.pb(mp(a[i], mp(comp[i], i)));
        comp_list[comp[i]].pb(i);
    }

    sort(all(v));

    // cout << v << endl;

    ll num_components = cnt - 1;

    // cout << "num_components: " << num_components << endl;

    for(ll i = 0; i <= num_components; i++)
    {
        par[i] = i;
        union_siz[i] = 1;
    }

    ll siz = v.size();

    vector <pair<ll, pair<pll, pll>>> edges;
    // vector <pll> comp_edges;

    for(ll i = 1; i < siz; i++)
    {
        if(v[i].ss.ff != v[i - 1].ss.ff)
        {
            ll weight = abs(v[i].ff - v[i - 1].ff);

            ll ff = v[i - 1].ss.ss;
            ll ss = v[i].ss.ss;
            pll nodes = mp(ff, ss);

            ll comp_ff = v[i - 1].ss.ff;
            ll comp_ss = v[i].ss.ff;
            pll comp_nodes = mp(comp_ff, comp_ss);

            edges.pb(mp(weight, mp(comp_nodes, nodes)));
        }
    }

    sort(all(edges));

    // cout << edges << endl;

    ll num_edges = sz(edges);

    vector <pll> final_ans;
    ll final_weight = 0;

    for(ll i = 0; i < num_edges; i++)
    {
        ll first_n = edges[i].ss.ff.ff;
        ll second_n = edges[i].ss.ff.ss;

        if(find(first_n) != find(second_n))
        {
            final_weight += edges[i].ff;
            final_ans.pb(edges[i].ss.ss);
            merge_set(first_n, second_n);
        }
    }

    ll final_k = sz(final_ans);

    for(ll i = 1; i <= num_components; i++)
    {
        final_k += max(0LL, (sz(comp_list[i]) - 1));
    }

    cout << final_weight << " " << final_k << endl;

    for(ll i = 0; i < sz(final_ans); i++)
    {
        cout << final_ans[i].ff << " " << final_ans[i].ss << endl;
        // cout << final_ans[i].ss << " " << final_ans[i].ff << endl;
    }

    for(ll i = 1; i <= num_components; i++)
    {
        if(sz(comp_list[i]) > 1)
        {
            for(ll j = 1; j < sz(comp_list[i]); j++)
            {
                cout << comp_list[i][j - 1] << " " << comp_list[i][j] << endl;
            }
        }
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
