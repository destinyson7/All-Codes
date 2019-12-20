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

const ll L = 1e4+5;
vector <pll> adj[L];

const ll M = 1e2+5;
ll dp[M][M];

ll dis(pll a, pll b)
{
    return (abs(a.ff-b.ff) + abs(a.ss-b.ss));
}

void solve()
{
    ll N, K;
    cin >> N >> K;

    for(ll i=0; i<=K; i++)
    {
        adj[i].clear();
    }

    for(ll i=0; i<N; i++)
    {
        for(ll j=0; j<N; j++)
        {
            ll h;
            cin >> h;

            dp[i+1][j+1] = 1e15;

            adj[h].pb(mp(i+1, j+1));
        }
    }

    for(auto i: adj[1])
    {
        // cout << "** " << i << endl;
        dp[i.ff][i.ss] = 0;
    }

    for(ll i=2; i<=K; i++)
    {
        for(auto j: adj[i])
        {
            for(auto k: adj[i-1])
            {
                // cout << j << " * " << k << " * " << dp[j.ff][j.ss] << " * " << dp[k.ff][k.ss] << endl;
                dp[j.ff][j.ss] = min(dp[j.ff][j.ss], dp[k.ff][k.ss] + dis(j, k));
                
            }
        }
    }

    ll ans = 1e15;

    for(auto i: adj[K])
    {
        ans = min(ans, dp[i.ff][i.ss]);
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        solve();
    }

    return 0;
}