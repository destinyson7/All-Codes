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

vector <pair<ll, pll>> adj;
ll par[L];
ll unionSize[L];

ll find(ll x)
{
    if(par[x] == x)
    {
        return x;
    }

    return par[x] = find(par[x]);
}

void unionSet(ll x, ll y)
{
    ll a = find(x);
    ll b = find(y);

    if(unionSize[a] > unionSize[b])
    {
        swap(a, b);
    }

    par[a] = b;
    unionSize[b] += unionSize[a];
}

void solve()
{
    ll N, M;
    cin >> N >> M;

    adj.clear();
    
    for(ll i=0; i<L; i++)
    {
        par[i] = i;
        unionSize[i] = 1;
    }

    for(ll i=0; i<M; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        adj.pb(mp(w, mp(u, v)));
    }

    sort(all(adj));

    ll ans = 0;

    vector <ll> mst;

    for(ll i=0; i<M; i++)
    {
        if(find(adj[i].ss.ff) != find(adj[i].ss.ss))
        {
            ans += adj[i].ff;
            unionSet(adj[i].ss.ff, adj[i].ss.ss);
            mst.pb(i);
        }
    }

    ll second_best = 1e15;

    for(auto i: mst)
    {
        for(ll j=0; j<L; j++)
        {
            par[j] = j;
            unionSize[j] = 1;
        }

        ll edges = 0, cur = 0;

        for(ll j=0; j<M; j++)
        {
            if(i != j && find(adj[j].ss.ff) != find(adj[j].ss.ss))
            {
                cur += adj[j].ff;
                unionSet(adj[j].ss.ff, adj[j].ss.ss);
                edges++;
            }
        }

        if(edges == N-1)
        {
            second_best = min(second_best, cur);
        }
    }

    cout << ans << " " << second_best << endl;
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