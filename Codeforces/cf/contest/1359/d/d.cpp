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

const ll L = 1e5+5;
ll a[L];
ll pref[L];
ll suff[L];
ll seg[4*L][2];
ll lef[L];
ll righ[L];

ll merge(ll a, ll b)
{
    return max(a, b);
}

void build(ll pos, ll tl, ll tr, ll type)
{
    // cout << pos << " " << tl << " " << tr << endl;
    if(tl == tr)
    {
        seg[pos][type] = (type ? suff[tl] : pref[tl]);
        return;
    }

    ll mid = tl + (tr - tl)/2;
    build(2 * pos, tl, mid, type);
    build(2 * pos + 1, mid + 1, tr, type);
    seg[pos][type] = merge(seg[2*pos][type], seg[2*pos+1][type]);
}

ll query(ll pos, ll tl, ll tr, ll l, ll r, ll type)
{   
    if(tl > r || tr < l)
    {
        return -1e18;
    }

    if(tl >= l && tr <= r)
    {
        return seg[pos][type];
    }

    ll mid = tl + (tr - tl)/2;
    return merge(query(2 * pos, tl, mid, l, r, type), query(2 * pos + 1, mid + 1, tr, l, r, type));
}

void solve()
{
    ll n = nxt();
    
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for(ll i = 1; i <= n; i++)
    {
        pref[i] = pref[i-1] + a[i];
    }

    for(ll i = n - 1; i > 0; i--)
    {
        suff[i] = suff[i+1] + a[i];
    }

    build(1, 1, n, 0);
    build(1, 1, n, 1);

    stack <pll> s;

    for(ll i = 1; i <= n; i++)
    {
        while(!s.empty() && s.top().ff <= a[i])
        {
            s.pop();
        }

        if(!s.empty())
        {
            lef[i] = s.top().ss;
        }

        s.push(mp(a[i], i));
    }

    while(!s.empty())
    {
        s.pop();
    }


    for(ll i = n; i > 0; i--)
    {
        while(!s.empty() && s.top().ff <= a[i])
        {
            s.pop();
        }

        if(!s.empty())
        {
            righ[i] = s.top().ss;
        }

        else
        {
            righ[i] = n + 1;
        }

        s.push(mp(a[i], i));
    }

    ll ans = 0;

    for(ll i = 1; i <= n; i++)
    {
        ll l = lef[i] + 1, r = righ[i] - 1;

        ll cur = 0;

        if(l < i)
        {
            cur += max(0LL, query(1, 1, n, l, i - 1, 1) - suff[i]);
        }

        if(r > i)
        {
            cur += max(0LL, query(1, 1, n, i + 1, r, 0) - pref[i]);
        }

        // cout << cur << " " << mp(l, r) << endl;

        ans = max(ans, cur);
    }

    cout << ans << endl;
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