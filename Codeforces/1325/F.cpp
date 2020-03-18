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

vector <ll> adj[L];
ll dp[L];
bool visited[L];
ll sq = 0;
vector <ll> ind_set;
bool cannot_take[L];
vector <ll> cycle;

// DFS Tree
void dfs(ll src)
{
    visited[src] = true;

    dp[src] = sz(cycle);
    cycle.pb(src);

    for(auto i: adj[src])
    {
        if(!visited[i])
        {
            dfs(i);
        }

        else if(dp[src] - dp[i] + 1 >= sq)
        {
            cout << 2 << endl;
            cout << dp[src] - dp[i] + 1 << endl;

            for(ll j = dp[i]; j <= dp[src]; j++)
            {
                cout << cycle[j] + 1 << " ";
            }
            cout << endl;

            exit(0);
        }
    }

    cycle.pop_back();

    if(!cannot_take[src])
    {
        ind_set.pb(src);

        for(auto i: adj[src])
        {
            cannot_take[i] = true;
        }
    }
}

void solve()
{
    ll n = nxt(), m = nxt();

    for(ll i=0; i<m; i++)
    {
        ll u = nxt() - 1, v = nxt() - 1;
        
        adj[u].pb(v);
        adj[v].pb(u);
    }

    sq = sqrt(n);

    if(sq*sq < n)
    {
        sq++;
    }

    dfs(0);

    cout << 1 << endl;

    for(ll i=0; i<sq; i++)
    {
        cout << ind_set[i] + 1 << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    // cin >> T;

    while(T--)
    {
        solve();
    }

    return 0;
}