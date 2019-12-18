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

const ll L = 1e5+5;

ll seg[4*L];
ll lazy[4*L];

ll merge(ll a, ll b)
{
    return (a+b);
}

void update(ll pos, ll tl, ll tr, ll l, ll r)
{
    if(lazy[pos] != 0)
    {
        if(lazy[pos] & 1)
        {
            seg[pos] = (tr-tl+1 - seg[pos]);
        }

        if(tl != tr)
        {
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }

        lazy[pos] = 0;
    }

    if(tr < l || tl > r)
    {
        return;
    }

    if(tl >= l && tr <= r)
    {
        seg[pos] = (tr-tl+1 - seg[pos]);

        if(tl != tr)
        {
            lazy[2*pos]++;
            lazy[2*pos+1]++;
        }

        return;
    }

    ll mid = tl + (tr-tl)/2;

    update(2*pos, tl, mid, l, r);
    update(2*pos+1, mid+1, tr, l, r);

    seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
}

ll query(ll pos, ll tl, ll tr, ll l, ll r)
{
    if(lazy[pos] != 0)
    {
        if(lazy[pos] & 1)
        {
            seg[pos] = (tr-tl+1 - seg[pos]);
        }

        if(tl != tr)
        {
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }

        lazy[pos] = 0;
    }

    if(tr < l || tl > r)
    {
        return 0;
    }

    if(tl >= l && tr <= r)
    {
        // cout << tl << " " << tr << " " << seg[pos] << endl;

        return seg[pos];
    }

    ll mid = tl + (tr-tl)/2;

    return merge(query(2*pos, tl, mid, l, r), query(2*pos+1, mid+1, tr, l, r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, M;
    cin >> N >> M;

    assert(N <= L);

    while(M--)
    {
        ll type, l, r;
        cin >> type >> l >> r;

        if(type == 0)
        {
            update(1, 1, N, l, r);
        }

        else
        {
            cout << query(1, 1, N, l, r) << endl;
        }
    }

    return 0;
}