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

const ll L = 1e6+5;

typedef struct node 
{
    ll ans;
    ll left;
    ll right;
} node;

string s;

node seg[4*L];

node merge(node a, node b)
{
    node x;

    x.ans = a.ans + b.ans + min(a.left, b.right);
    x.left = a.left + b.left - min(a.left, b.right);
    x.right = a.right + b.right - min(a.left, b.right);

    return x; 
}

void build(ll pos, ll tl, ll tr)
{
    if(tl == tr)
    {
        node x;
        x.ans = 0, x.left = 0, x.right = 0;

        if(s[tl] == '(')
        {
            x.left = 1;
        }

        else
        {
            x.right = 1;
        }

        seg[pos] = x;
        return;
    }

    ll mid = tl + (tr-tl)/2;

    build(2*pos, tl, mid);
    build(2*pos+1, mid+1, tr);

    seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
}

node query(ll pos, ll tl, ll tr, ll l, ll r)
{
    if(tl > r || tr < l)
    {
        node x;
        x.ans = 0;
        x.left = 0;
        x.right = 0;

        return x;
    }

    if(tl >= l && tr <= r)
    {
        return seg[pos];
    }

    ll mid = tl + (tr-tl)/2;

    return merge(query(2*pos, tl, mid, l, r), query(2*pos+1, mid+1, tr, l, r));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    ll n = sz(s);

    build(1, 0, n-1);

    ll m;
    cin >> m;

    while(m--)
    {
        ll l, r;
        cin >> l >> r;

        l--, r--;

        cout << 2*query(1, 0, n-1, l, r).ans << endl;
    }

    return 0;
}