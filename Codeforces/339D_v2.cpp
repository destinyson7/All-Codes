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

const ll L = (1LL << 17) + 5;

ll a[L];
ll seg[4*L];

ll merge(ll a, ll b, bool f)
{
    if(!f)
    {
        return a^b;
    }

    else
    {
        return a|b;
    }
}

void build(ll pos, ll tl, ll tr, bool f)
{
    // cout << pos << " " << tl << " "  << tr << " " << f << endl;
    if(tl == tr)
    {
        seg[pos] = a[tl];
        return;
    }

    ll mid = tl + (tr-tl)/2;

    build(2*pos, tl, mid, f^1);
    build(2*pos+1, mid+1, tr, f^1);

    seg[pos] = merge(seg[2*pos], seg[2*pos+1], f);
}

void update(ll pos, ll tl, ll tr, ll idx, ll val, bool f)
{
    if(tl == tr)
    {
        seg[pos] = val;
        return;
    }

    ll mid = tl + (tr-tl)/2;

    if(tl <= idx && idx <= mid)
    {
        update(2*pos, tl, mid, idx, val, f^1);
    }

    else
    {
        update(2*pos+1, mid+1, tr, idx, val, f^1);
    }

    seg[pos] = merge(seg[2*pos], seg[2*pos+1], f);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    for(ll i=1; i<=(1LL << n); i++)
    {
        cin >> a[i];
    }

    build(1, 1, (1LL << n), n&1);

    while(m--)
    {
        ll p, b;
        cin >> p >> b;

        update(1, 1, (1LL << n), p, b, n&1);

        cout << seg[1] << endl;
    }

    return 0;
}