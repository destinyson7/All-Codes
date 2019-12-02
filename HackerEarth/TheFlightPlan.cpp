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

const ll L = 1e3+5;

vector <ll> adj[L];
bool visited[L];
ll par[L];
ll dis[L];

void bfs(ll s)
{
    assert(!visited[s]);
    visited[s] = true;
    par[s] = -1;
    dis[s] = 0;

    queue <ll> q;
    q.push(s);

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        for(auto i: adj[top])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
                par[i] = top;
                dis[i] = dis[top] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, M, T, C;
    cin >> N >> M >> T >> C;

    for(ll i=0; i<M; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(ll i=1; i<=N; i++)
    {
        sort(all(adj[i]));
    }

    ll X, Y;
    cin >> X >> Y;

    bfs(X);

    cout << dis[Y] + 1 << endl;

    vector <ll> path;

    while(Y != -1)
    {
        path.pb(Y);
        Y = par[Y];
    }

    reverse(all(path));
    for(auto i: path)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}