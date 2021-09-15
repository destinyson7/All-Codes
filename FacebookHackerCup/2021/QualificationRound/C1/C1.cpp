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

const ll L = 50 + 5;

ll c[L];
vector <ll> adj[L];
ll cur_ans = 0;

void dfs(ll s, ll p, ll cur_score)
{
    cur_ans = max(cur_ans, cur_score + c[s]);

    for(auto i: adj[s])
    {
        if(i != p)
        {
            dfs(i, s, cur_score + c[s]);
        }
    }
}

void solve()
{
    ll n = nxt();

    for(ll i = 1; i <= n; i++)
    {
        cin >> c[i];
        adj[i].clear();
    }

    vector <ll> roots;

    for(ll i = 0; i < n - 1; i++)
    {
        ll u = nxt(), v = nxt();

        if(u == 1)
        {
            roots.pb(v);
        }

        else if(v == 1)
        {
            roots.pb(u);
        }

        else
        {
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }

    vector <ll> scores;

    scores.pb(0);
    scores.pb(0);

    for(auto i: roots)
    {
        cur_ans = 0,
        dfs(i, 1, 0);
        scores.pb(cur_ans);
    }

    sort(all(scores));
    reverse(all(scores));

    cout << c[1] + scores[0] + scores[1] << endl;
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
