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

const ll L = 2e5+5;
const ll mod = 1e9+7;

vector <ll> adj[L];

ll fact[L];
ll invfact[L];

void factorial()
{
    fact[0] = 1;
    invfact[0] = 1;

    for(ll i=1; i<L; i++)
    {
        fact[i] = (fact[i-1] * i)%mod;
        invfact[i] = modexp(fact[i], mod-2, mod);
    }
}

ll C(ll n, ll r)
{
    ll ans = fact[n];
    ans *= invfact[r];
    ans %= mod;

    ans *= invfact[n-r];
    ans %= mod;

    return ans;
}

ll sz[L];
ll ans[L];
ll res[L];

void dfs(ll src, ll par)
{
    sz[src] = 1;

    for(auto i: adj[src])
    {
        if(i != par)
        {
            dfs(i, src);
            sz[src] += sz[i];
        }
    }

    ans[src] = 1;

    ll rem = sz[src] - 1;

    for(auto i: adj[src])
    {
        if(i != par)
        {
            ans[src] *= ans[i];
            ans[src] %= mod;

            ans[src] *= C(rem, sz[i]);
            ans[src] %= mod;

            rem -= sz[i];
        }
    }
}

void dfs2(ll src, ll par, ll n)
{
    if(par == -1)
    {
        res[src] = ans[src];
    }

    else
    {
        ll d = C(n-1, sz[src]) * ans[src];
        d %= mod;

        d = modexp(d, mod-2, mod);

        d *= res[par];
        d %= mod;

        res[src] = d;

        ll rem = n-1;

        res[src] *= C(rem, n-sz[src]);
        res[src] %= mod;

        rem -= (n - sz[src]);

        for(auto i: adj[src])
        {
            if(i != par)
            {
                res[src] *= ans[i];
                res[src] %= mod;

                res[src] *= C(rem, sz[i]);
                res[src] %= mod;

                rem -= sz[i];
            }
        }
    }

    for(auto i: adj[src])
    {
        if(i != par)
        {
            dfs2(i, src, n);
        }
    }
}

void solve()
{
    ll n = nxt();

    factorial();

    for(ll i=0; i<n-1; i++)
    {
        ll a = nxt() - 1, b = nxt() - 1;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, -1);
    dfs2(0, -1, n);

    for(ll i=0; i<n; i++)
    {
        cout << res[i] << endl;
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