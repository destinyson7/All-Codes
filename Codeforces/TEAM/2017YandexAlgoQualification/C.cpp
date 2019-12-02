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

const ll L = 50+5;

ll a[L];
vector <ll> adj[L];
bool visited[L];;
ll dep[L];

ll ans1 = 0, ans2 = 0;

void dfs(ll s, ll par)
{
    assert(!visited[s]);
    dep[s] = dep[par]+1;
    visited[s] = true;

    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            dfs(i, s);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];

        ans1+=a[i];
    }

    for(ll i=0; i<n; i++)
    {
        ll k;
        cin >> k;

        while(k--)
        {
            ll b;
            cin >> b;
            b--;

            adj[i].pb(b);
        }
    }

    dep[0] = -1;
    dfs(0, 0);

    for(ll i=0; i<n; i++)
    {
        ans2+=(a[i]*(1LL << dep[i]));
    }

    cout << ans1 << " " << ans2 << endl;

    return 0;
}