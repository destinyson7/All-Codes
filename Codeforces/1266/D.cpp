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

ll debt[L];
// vector <pll> adj[L];
// bool visited[L];

// vector <ll> scc[L];
// ll components = 0;
// ll which[L];
// // map <pll, ll> cnt;

// void dfs(ll src, ll total)
// {
//     assert(!visited[src]);
//     visited[src] = true;

//     which[src] = total;
//     scc[total].pb(src);

//     for(auto i: adj[src])
//     {
//         if(visited[i.ff])
//         {
//             dfs(i.ff, total);
//         }
//     }
// }

// vector <pair<pll,ll>> edges;

set <pll> positive;

vector <pair<pll,ll>> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<m; i++)
    {
        ll u, v, d;
        cin >> u >> v >> d;

        // adj[u].pb(mp(v, d));
        // rev[v].pb(mp(v, d));

        // cnt[mp(u, v)] += d;

        debt[u] -= d;
        debt[v] += d;
    }

    // for(auto i: cnt)
    // {
    //     ll u = i.ff.ff;
    //     ll v = i.ff.ss;
    //     ll d = i.ss;

    //     adj[u].pb(mp(v, d));
    //     edges.pb(mp(mp(u, v), d));
    //     // rev[v].pb(mp(u, d));
    // }

    // for(ll i=1; i<=n; i++)
    // {
    //     if(!visited[i])
    //     {
    //         dfs(i, components); 
    //         components++;
    //     }
    // }

    for(ll i=1; i<=n; i++)
    {
        if(debt[i] < 0)
        {
            positive.insert(mp(-debt[i], i));
        }
    }

    for(ll i=1; i<=n; i++)
    {
        while(debt[i] > 0)
        {
            pll owe = *positive.begin();

            if(owe.ff > debt[i])
            {
                ans.pb(mp(mp(owe.ss, i), debt[i]));
                positive.insert(mp(owe.ff-debt[i], owe.ss));
                positive.erase(owe);
                debt[i] = 0;
            }

            else
            {
                ans.pb(mp(mp(owe.ss, i), owe.ff));
                debt[i] -= owe.ff;
                positive.erase(owe);
            }
        }
    }

    ll how_many = sz(ans);

    cout << how_many << endl;

    for(auto i: ans)
    {
        cout << i.ff.ff << " " << i.ff.ss << " " << i.ss << endl;
    }


    return 0;
}