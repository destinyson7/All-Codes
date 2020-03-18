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

const ll L = 2e5+5;

vector <ll> adj[L];
vector <ll> adj_rev[L];
ll p[L];
ll s[L];
ll visited[L];

priority_queue <pll, vector <pll>, greater <pll>> v;

void relax(ll vv, ll u)
{
    if(s[vv] > s[u] + 1)
    {
        s[vv] = s[u] + 1;
        v.push(mp(s[vv], vv));

        // cout << vv << " " << u << " " << s[vv] << endl;
    }
}

void dijkstras(ll last)
{
    s[last] = 0;
    v.push(mp(0LL, last));

    while(!v.empty())
    {
        pll top = v.top();
        v.pop();

        ll next = top.ss;

        if(!visited[next])
        {
            visited[next] = true;

            for(auto i: adj_rev[next])
            {
                if(!visited[i])
                {
                    relax(i, next);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<L; i++)
    {
        s[i] = 1e17;
    }

    for(ll i=0; i<m; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj_rev[v].pb(u);
    }

    ll k;
    cin >> k;

    for(ll i=1; i<=k; i++)
    {
        cin >> p[i];
    }

    ll last = p[k];

    dijkstras(last);

    ll mi = 0, ma = 0;

    for(ll i=1; i<k; i++)
    {
        ll cur = 1e17;
        for(auto j: adj[p[i]])
        {
            cur = min(s[j], cur);
        }

        ll ss = 0;
        bool f = false;

        for(auto j: adj[p[i]])
        {
            if(cur == s[j])
            {
                if(p[i+1] == j)
                {
                    f = true;
                }

                ss++;
            }
        }

        if(!f)
        {
            mi++;
            ma++;
        }

        else if(ss > 1)
        {
            ma++;
        }
    }

    cout << mi << " " << ma << endl;

    return 0;
}