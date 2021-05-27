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
vector <ll> adj_r[L];
bool visited[L];
bool visited_r[L];

void dfs(ll s)
{
    assert(!visited[s]);
    visited[s] = true;

    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}

void dfs_r(ll s)
{
    assert(!visited_r[s]);
    visited_r[s] = true;

    for(auto i: adj_r[s])
    {
        if(!visited_r[i])
        {
            dfs_r(i);
        }
    }
}

void solve()
{
    ll n = nxt(), m = nxt();

    for(ll i = 0; i < m; i++)
    {
        ll a = nxt(), b = nxt();
        adj[a].pb(b);
        adj_r[b].pb(a);
    }

    ll cc = 0;
    ll cc_r = 0;

    basic_string <ll> res;
    basic_string <ll> res_r;

    for(ll i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            cc++;

            res += i;
        }
    }

    for(ll i = 1; i <= n; i++)
    {
        if(!visited_r[i])
        {
            dfs_r(i);
            cc_r++;

            res_r += i;
        }
    }

    if(cc == 1 && cc_r == 1)
    {
        cout << "YES" << endl;
    }

    else
    {
        cout << "NO" << endl;

        if(cc > 1)
        {
            cout << res[0] << " " << res[1] << endl;
        }

        else
        {
            cout << res_r[1] << " " << res_r[0] << endl;
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
