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

const ll MAX = 2e5+5;

inline ll left(ll p) { return p << 1; }
inline ll right(ll p) { return (p << 1) + 1;} 

struct Node {
    ll cnt = 0;
    ll lazy = -1e15;
    void resetNode() {
        cnt = 0;
        lazy = 1e15;
    }
    void combine(Node &a, Node &b) {
        cnt = a.cnt + b.cnt;
    }
};

ll N;
ll A[MAX];
Node st[3 * MAX + 7];

void build(ll p, ll l, ll r) {
    if (l == r) {
        st[p].cnt = (A[l] == 0 ? 1 : 0);
        return;
    }
    ll mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p].combine(st[left(p)], st[right(p)]);
}

void pushUp(ll p) {
    st[p].combine(st[left(p)], st[right(p)]);
}

void pushDown(ll p, ll l, ll r) {
    if (st[p].lazy == 1e15) return;
    ll mid = (l + r) >> 1;
    if (st[p].lazy == 0) {
        st[left(p)].cnt = (ll)(mid-l+1);
        st[right(p)].cnt = (ll)(r-mid+1);
    }
    st[p].lazy = st[p].lazy = st[p].lazy;
    st[p].lazy = 1e15;
}

void updateRangeLazy(ll p, ll l, ll r, ll i, ll j, ll val) {
    if (i == l && j == r) {
        st[p].cnt = (ll)(r - l + 1) * (val == 0 ? 1 : 0);
        if (l != r) st[p].lazy = val;
        return;
    }
    pushDown(p, l, r);
    ll mid = (l + r) >> 1;
    if (j <= mid) updateRangeLazy(left(p), l, mid, i, j, val);
    else if (i > mid) updateRangeLazy(right(p), mid + 1, r, i, j, val);
    else {
        updateRangeLazy(left(p), l, mid, i, mid, val);
        updateRangeLazy(right(p), mid + 1, r, mid + 1, j, val);
    }
    pushUp(p);
}

ll queryLazy(ll p, ll l, ll r, ll i, ll j) {
    if (i == l && j == r) return st[p].cnt;

    pushDown(p, l, r);

    ll mid = (l + r) >> 1;
    if (j <= mid) return queryLazy(left(p), l, mid, i, j);
    if (i > mid) return queryLazy(right(p), mid + 1, r, i, j);

    ll tmp1 = queryLazy(left(p), l, mid, i, mid);
    ll tmp2 = queryLazy(right(p), mid + 1, r, mid+1, j);
    return tmp1 + tmp2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        cin >> A[i];
    }


    return 0;
}