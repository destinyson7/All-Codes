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

const ll L = 4e3+5;

vector < pair <ll, pll>> adj[L];

pll dis[L];

void dijkstras(ll s, ll check)
{
    for(ll i=0; i<L; i++)
    {
        dis[i].ff = 1e15;
        dis[i].ss = 1e15;
    }

    dis[s] = mp(0, 0);

    priority_queue < pair <pll, ll>, vector < pair <pll, ll> >, greater < pair <pll, ll > > > pq;

    pq.push(mp(mp(0, 0), s));

    while(!pq.empty())
    {
        ll next = pq.top().ss;

        pq.pop();

        for(auto i: adj[next])
        {
            pll weights = i.ss;

            if(dis[next].ss + weights.ss < dis[i.ff].ss)
            {
                dis[i.ff].ss = dis[next].ss + weights.ss;
                dis[i.ff].ff = dis[next].ff + weights.ff;

                pq.push(mp(mp(dis[i.ff].ff, dis[i.ff].ss), i.ff));
            }
        }
    }

    if(dis[check].ss == 1e15)
    {
        cout << "IMPOSSIBLE" << endl;
    }

    else
    {
        cout << dis[check].ff << " " << dis[check].ss << endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m, p;
    cin >> n >> m >> p;

    for(ll i=0; i<m; i++)
    {
        ll u, v, w;
        char c;

        cin >> u >> v >> w >> c;

        if(c == 'I')
        {
            adj[u].pb(mp(v, mp(w, w)));
        }

        else
        {
            adj[u].pb(mp(v, mp(0, w)));
        }
    }

    while(p--)
    {
        ll u, v;
        cin >> u >> v;

        dijkstras(u, v);
    }

    return 0;
}