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

const ll L = 5e3+5;

vector <pll> adj[L];
vector < pair<ll, pll> > edge(L);

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

bool visited[L];
bool include[L];

void dfs(ll s)
{
    assert(!visited[s]);
    visited[s] = true;

    for(auto i: adj[s])
    {
        if(!visited[i.ff])
        {
            // cout << i.ff << " " << i.ss << endl;
            dfs(i.ff);
        }
    }
}

const ll inf = 1e15;

vector <ll> dis(L, inf);

bool bellmanFord(ll s, ll N, ll M)
{
    dis[s] = 0; 

    for(ll i=0; i<N; i++)
    {
        for(ll j=0; j<M; j++)
        {
            if(include[edge[j].ff] && include[edge[j].ss.ff])
            {
                // cout << j << " " << dis[edge[j].ss.ff] + edge[j].ss.ss << endl;
                dis[edge[j].ss.ff] = min(dis[edge[j].ss.ff], dis[edge[j].ff] + edge[j].ss.ss);
            }
        }
    }

    for(ll j=0; j<M; j++)
    {
        if(include[edge[j].ff] && include[edge[j].ss.ff] && dis[edge[j].ss.ff] > dis[edge[j].ff] + edge[j].ss.ss)
        {
            // cout << j << " " << edge[j].ff << " " << edge[j].ss.ff << endl;
            return false;
        }
    }

    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, M, P;
    cin >> N >> M >> P;

    for(ll i=0; i<M; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a-1].pb(mp(b-1, i));

        edge[i] = mp(a-1, mp(b-1, -c+P));
    }

    for(ll i=0; i<L; i++)
    {
        include[i] = true;
    }

    dfs(0);

    for(ll i=0; i<N-1; i++)
    {
        if(!visited[i])
        {
            // cout << "f " << i << endl;
            include[i] = false;
        }
    }

    for(ll i=1; i<N-1; i++)
    {
        for(ll i=0; i<N; i++)
        {
            visited[i] = false;
        }

        dfs(i);

        if(!visited[N-1])
        {
            // cout << "s " << i << endl;
            include[i] = false;
        }
    }

    // for(ll i=0; i<N; i++)
    // {
    //     cout << include[i] << endl;
    // }

    bool f = bellmanFord(0, N, M);

    // cout << f << endl;

    if(f && dis[N-1] != inf)
    {
        cout << max(0LL, -dis[N-1]) << endl;
    }
    
    else
    {   
        cout << -1 << endl;
    }

    return 0;
}