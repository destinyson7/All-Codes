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

const ll L = 30+5;

map <string, string> parent;
map <string, ll> unionSize;

string find(string x)
{
    if(parent[x] == x)
    {
        return x;
    }

    return parent[x] = find(parent[x]);
}

void unionSet(string u, string v)
{
    string a = find(u);
    string b = find(v);

    if(unionSize[a] > unionSize[b])
    {
        swap(a, b);
    }

    parent[a] = b;

    unionSize[b] += unionSize[a];
}

void solve(ll tc, ll T)
{
    ll M, N;
    cin >> M;
    cin >> N;

    vector <pair<ll, pair<string, string>>> adj;

    for(ll i=0; i<N; i++)
    {
        string u, v;
        ll w;
        cin >> u >> v >> w;

        parent[u] = u;
        parent[v] = v;
        unionSize[u] = 1;
        unionSize[v] = 1;
        adj.pb(mp(w, mp(u, v)));
    }

    sort(all(adj));

    ll len = sz(adj);

    ll ans = 0;

    for(ll i=0; i<len; i++)
    {
        string u = adj[i].ss.ff;
        string v = adj[i].ss.ss;

        if(find(u) != find(v))
        {
            ans += adj[i].ff;

            unionSet(u, v);
        }
    }

    cout << ans << endl;

    if(tc != T)
    {
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    for(ll i=1; i<=T; i++)
    {
        solve(i, T);
    }

    return 0;
}