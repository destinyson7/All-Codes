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

typedef struct node
{
    ll first_max;
    ll second_max;
} node;

ll a[L];
node seg[4*L];

node merge(node a, node b)
{
    vector <ll> temp;
    temp.pb(a.first_max);
    temp.pb(a.second_max);
    temp.pb(b.first_max);
    temp.pb(b.second_max);

    sort(all(temp));
    reverse(all(temp));

    node x;
    x.first_max = temp[0];
    x.second_max = temp[1];

    // cout << x.first_max << " * " << x.second_max << endl;

    return x;
}

void build(ll pos, ll tl, ll tr)
{
    if(tl == tr)
    {
        seg[pos].first_max = a[tl];
        seg[pos].second_max = -1;
        
        return;
    }

    ll mid = tl + (tr-tl)/2;

    build(2*pos, tl, mid);
    build(2*pos+1, mid+1, tr);

    seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
}

void update(ll pos, ll tl, ll tr, ll idx, ll val)
{
    if(tl == tr)
    {
        seg[pos].first_max = val;
        seg[pos].second_max = -1;
        
        return;
    }

    ll mid = tl + (tr-tl)/2;

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

node query(ll pos, ll tl, ll tr, ll l, ll r)
{
    if(tr < l || tl > r)
    {
        node x;
        x.first_max = -1;
        x.second_max = -1;

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

    ll N;
    cin >> N;

    for(ll i=1; i<=N; i++)
    {
        cin >> a[i];
    }

    build(1, 1, N);

    ll Q;
    cin >> Q;

    while(Q--)
    {
        char type;
        cin >> type;

        if(type == 'U')
        {
            ll idx, val;
            cin >> idx >> val;

            update(1, 1, N, idx, val);
        }

        else
        {
            ll l, r;
            cin >> l >> r;

            node res = query(1, 1, N, l, r);

            cout << res.first_max + res.second_max << endl;
        }
    }


    return 0;
}