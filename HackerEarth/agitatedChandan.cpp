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

const ll L = 1e5+5;

vector <pll> adj[L];
ll dis[L];

ll ans = 0;
ll where = 1;

void dfs(ll s)
{
    // visited[s] = true;

    for(auto i: adj[s])
    {
        if(dis[i.ff] == -1)
        {
            // cout << i.ff << " " << s << endl;
            dis[i.ff] = dis[s] + i.ss;
            // cout << dis[i.ff] << endl;

            if(ans < dis[i.ff])
            {
                // cout << "****" << endl;
                ans = dis[i.ff];
                where = i.ff;
            }

            dfs(i.ff);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        ll n;
        cin >> n;

        for(ll i=0; i<=n; i++)
        {
            adj[i].clear();
            dis[i] = -1;
        }

        for(ll i=0; i<n-1; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;

            adj[u].pb(mp(v, w));
            adj[v].pb(mp(u, w));
        }

        ans = 0, where = 1;

        dis[1] = 0;
        dfs(1);

        for(ll i=0; i<=n; i++)
        {
            dis[i] = -1;
        }

        // cout << where << " ** " << ans << endl;

        ans = 0;

        dis[where] = 0;
        dfs(where);

        if(ans < 100)
        {
            cout << 0 << " ";
        }

        else if(ans <= 1000)
        {
            cout << 100 << " ";
        }

        else if(ans <= 10000)
        {
            cout << 1000 << " ";
        }

        else
        {
            cout << 10000 << " ";
        }

        cout << ans << endl;
    }

    return 0;
}