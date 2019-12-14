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

const ll L = 1e2+5;

vector <ll> adj[L];
ll color[L];

ll n, k;
ll ans = 0;
vector <ll> store;

void backtrack(ll node)
{
    if(node == n+1)
    {
        ll blacks = 0;

        for(ll i=1; i<=n; i++)
        {
            if(color[i] == 1)
            {
                blacks++;
            }
        }

        if(blacks > ans)
        {
            ans = blacks;
            store.clear();

            for(ll i=1; i<=n; i++)
            {
                if(color[i] == 1)
                {
                    store.pb(i);
                }
            }
        }

        return;
    }

    bool possible = true;

    for(auto i: adj[node])
    {
        if(color[i] == 1)
        {
            possible = false;
            break;
        }
    }

    if(possible)
    {
        color[node] = 1;
        backtrack(node + 1);

        color[node] = 0;
        backtrack(node + 1);
    }

    else
    {
        color[node] = 0;
        backtrack(node + 1);
    }
}

void solve()
{
    // ll n, k;
    cin >> n >> k;

    for(ll i=0; i<L; i++)
    {
        adj[i].clear();
    }

    for(ll i=0; i<k; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    backtrack(1);

    cout << ans << endl;
    for(ll i=0; i<sz(store)-1; i++)
    {
        cout << store[i] << " ";
    }
    cout << store[ans-1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        for(ll i=0; i<L; i++)
        {
            color[i] = 0;
        }

        ans = 0;
        store.clear();
        solve();
    }

    return 0;
}