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

ll make_all_equal(vector <ll> a)
{
    sort(all(a));

    ll siz = sz(a);

    ll ret = 0;

    if(siz & 1)
    {
        ll mid = a[siz / 2];

        for(ll i = 0; i < siz; i++)
        {
            ret += abs(a[i] - mid);
        }
    }

    else
    {
        ll m1 = a[siz / 2 - 1];
        ll m2 = a[siz / 2];

        ll t1 = 0, t2 = 0;

        for(ll i = 0; i < siz; i++)
        {
            t1 += abs(a[i] - m1);
            t2 += abs(a[i] - m2);
        }

        ret = min(t1, t2);
    }

    return ret;
}

void solve()
{
    ll n = nxt();
    basic_string <ll> a(n, 0);
    generate(all(a), nxt);

    sort(all(a));

    ll ans = 1e18;

    multiset <ll> s;

    for(ll i = 2; i < n; i++)
    {
        ll ff = a[i - 1] - a[0];
        ll ss = a[n - 1] - a[i];

        if(i < n - 1)
        {
            ll diff = abs(ff - ss);
            ans = min(ans, diff);
        }

        auto it = s.upper_bound(ff);

        if(it != s.end())
        {
            ans = min(ans, abs(ff - *it));
        }

        if(it != s.begin())
        {
            ans = min(ans, abs(ff - *--it));
        }

        s.insert(a[n - 1] - a[i - 1]);
    }

    vector <ll> v;

    for(ll i = 1; i <= n - 2; i++)
    {
        v.pb(a[i]);
    }

    v.pb(a[0]);
    ans = min(ans, make_all_equal(v));

    v.pop_back();
    v.pb(a[n - 1]);
    ans = min(ans, make_all_equal(v));

    cout << ans << endl;
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
