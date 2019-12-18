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

const ll L = 3e4+5;

typedef struct node
{
    ll sum;
    ll min_prefix_sum;
} node;
    
string s;
node seg[4*L];

node merge(node a, node b)
{
    node x;
    x.sum = a.sum + b.sum;
    x.min_prefix_sum = min(a.min_prefix_sum, a.sum + b.min_prefix_sum);

    return x;
}

void build(ll pos, ll tl, ll tr)
{
    if(tl == tr)
    {
        if(s[tl] == '(')
        {
            seg[pos].sum = 1;
            seg[pos].min_prefix_sum = 1;
        }

        else
        {
            seg[pos].sum = -1;
            seg[pos].min_prefix_sum = -1;
        }

        return;
    }

    ll mid = tl + (tr-tl)/2;

    build(2*pos+1, tl, mid);
    build(2*pos+2, mid+1, tr);

    seg[pos] = merge(seg[2*pos+1], seg[2*pos+2]);
}

void update(ll pos, ll tl, ll tr, ll idx)
{
    if(tl == tr)
    {
        seg[pos].sum *= (-1);
        seg[pos].min_prefix_sum *= (-1);

        return;
    }

    ll mid = tl + (tr-tl)/2;

    if(tl <= idx && idx <= mid)
    {
        update(2*pos+1, tl, mid, idx);
    }

    else
    {
        update(2*pos+2, mid+1, tr, idx);
    }

    seg[pos] = merge(seg[2*pos+1], seg[2*pos+2]);
}

void solve(ll tc)
{
    ll n;;
    cin >> n;

    // string s;
    cin >> s;

    for(ll i=0; i<=4*n; i++)
    {
        seg[i].sum = 0;
        seg[i].min_prefix_sum = 0;
    }

    build(0, 0, n-1);

    ll m;
    cin >> m;

    cout << "Test " << tc << ":" << endl;

    while(m--)
    {
        ll k;
        cin >> k;

        if(k == 0)
        {
            if(seg[0].sum == 0 && seg[0].min_prefix_sum == 0)
            {
                cout << "YES" << endl;
            }

            else
            {
                cout << "NO" << endl;
            }
        }

        else
        {
            k--;

            update(0, 0, n-1, k);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(ll i=1; i<=10; i++)
    {
        solve(i);
    }

    return 0;
}