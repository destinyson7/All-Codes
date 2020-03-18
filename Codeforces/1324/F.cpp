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

const ll L = 2e5+5;

vector <ll> adj[L];
ll a[L];
ll cur[L];
ll res[L];

void dfs(ll src, ll par)
{
    // cout << src << "**" << endl;
    if(a[src])
    {
        cur[src] = 1;
    }

    else
    {
        cur[src] = -1;
    }

    for(auto i: adj[src])
    {
        if(i != par)
        {
            dfs(i, src);
            
            if(cur[i] > 0)
            {
                cur[src] += cur[i];
            }

            // cout << src << " " << cur[src] << endl;
        }
    }
}

void dfsAns(ll src, ll par)
{
    res[src] = cur[src];
    
    if(src != 1)
    {
        if(cur[src] <= 0)
        {
            res[src] += max(0LL, res[par]);
        }

        else
        {
            res[src] += max(0LL, res[par] - cur[src]);
        }
    }

    for(auto i: adj[src])
    {
        if(i != par)
        {
            dfsAns(i, src);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    for(ll i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    for(ll i=0; i<n-1; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);
    dfsAns(1, 0);

    for(ll i=1; i<=n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}