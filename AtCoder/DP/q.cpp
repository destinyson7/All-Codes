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

ll seg[4*L];
ll h[L], a[L];
ll dp[L];

ll merge(ll a, ll b)
{
    return max(a, b);
}

void update(ll pos, ll tl, ll tr, ll idx, ll val)
{
    if(tl == tr)
    {
        seg[pos] = val;        
        return;
    }

    ll mid = tl + (tr - tl)/2;

    if(tl <= idx && idx <= mid)
    {
        update(2*pos, tl, mid, idx, val);
    }

    else
    {
        update(2*pos+1, mid+1, tr, idx, val);
    }

    seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
}

ll query(ll pos, ll tl, ll tr, ll l, ll r)
{
    if(tl > r || tr < l)
    {
        return 0;
    }

    if(tl >= l && tr <= r)
    {
        return seg[pos];
    }

    ll mid = tl + (tr-tl)/2;

    return merge(query(2*pos, tl, mid, l, r), query(2*pos+1, mid+1, tr, l, r));
}

void solve()
{
    ll n = nxt();    

    for(ll i=0; i<n; i++)
    {
        cin >> h[i];
    }

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
    }

    // dp[i] represents the maximum value we can get if the last taken flower has height i

    for(ll i=0; i<n; i++)
    {
        ll best = query(1, 1, n+1, 1, h[i]);
        dp[h[i]] = best + a[i];

        update(1, 1, n+1, h[i]+1, dp[h[i]]);

        // cout << dp[h[i]] << endl;
    }

    cout << query(1, 1, n+1, 1, n+1) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    // T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}