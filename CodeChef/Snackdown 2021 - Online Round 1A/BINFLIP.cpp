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

void solve()
{
    ll n = nxt(), k = nxt();

    if(k == 0)
    {
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }

    if(k % 2 == 0)
    {
        cout << "NO" << endl;
        return;
    }

    ll zero_ind = 1;
    ll one_ind = k;

    vector <ll> indices;

    ll last = 40;

    for(ll bit = 40; bit >= 0; bit--)
    {
        if((1LL << bit) & k)
        {
            last = bit;
            break;
        }
    }

    assert(last < 40);

    for(ll bit = last; bit >= 0 ; bit--)
    {
        if(zero_ind + (1LL << bit) - 1 <= one_ind)
        {
            indices.pb(zero_ind);
            zero_ind += (1LL << bit);
        }

        else
        {
            ll old_one_ind = one_ind;
            one_ind = zero_ind - 1;
            zero_ind = old_one_ind - (1LL << bit) + 1;
            indices.pb(zero_ind);
        }
    }

    ll cur = 1;

    cout << "YES" << endl;
    cout << sz(indices) << endl;
    for(ll i = sz(indices) - 1; i >= 0; i--)
    {
        cout << indices[i] << endl;

        assert((indices[i] + cur - 1) <= n);
        cur *= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}
