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

ll exp_new(ll a, ll b)
{
    // a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            // ans = (ans*a)%c;
            ans = (ans*a);
        }

        // a = (a*a)%c;
        a = (a*a);
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

const ll L = 5e5 + 5;
const ll mod = 1e9 + 7;

// Fenwick Tree Template from cp-algorithms: https://cp-algorithms.com/data_structures/fenwick.html

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    ll n;

    FenwickTree(ll n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<ll> a)
        : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(ll idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

// ll a[L][5];

ll fun(ll num, ll p)
{
    if(num == 0)
    {
        return 0;
    }

    ll ans = 0;

    while(num % p == 0)
    {
        num /= p;
        ans++;
    }

    return ans;
}

void solve()
{
    ll n = nxt(), q = nxt(), p = nxt();

    vector <ll> v[5];

    for(ll j = 0; j < 5; j++)
    {
        v[j].pb(0);
    }

    for(ll i = 1; i <= n; i++)
    {
        ll temp = nxt();

        for(ll j = 1; j <= 4; j++)
        {
            ll cur1 = fun(exp_new(temp, j) - exp_new(temp % p, j), p);
            v[j].pb(cur1);
        }
        // a[i] = fun(exp_new(a[i], s)
    }

    FenwickTree tree1 = FenwickTree(v[1]);
    FenwickTree tree2 = FenwickTree(v[2]);
    FenwickTree tree3 = FenwickTree(v[3]);
    FenwickTree tree4 = FenwickTree(v[4]);

    while(q--)
    {
        ll type = nxt();

        if(type == 1)
        {
            ll pos = nxt(), val = nxt();

            ll newv1 = fun(exp_new(val, 1) - exp_new(val % p, 1), p);
            ll newv2 = fun(exp_new(val, 2) - exp_new(val % p, 2), p);
            ll newv3 = fun(exp_new(val, 3) - exp_new(val % p, 3), p);
            ll newv4 = fun(exp_new(val, 4) - exp_new(val % p, 4), p);

            tree1.add(pos, newv1 - v[1][pos]);
            tree2.add(pos, newv2 - v[2][pos]);
            tree3.add(pos, newv3 - v[3][pos]);
            tree4.add(pos, newv4 - v[4][pos]);

            v[1][pos] = newv1;
            v[2][pos] = newv2;
            v[3][pos] = newv3;
            v[4][pos] = newv4;

            // a[pos] = val;
        }

        else
        {
            ll s = nxt(), l = nxt(), r = nxt();

            if(s == 1)
            {
                cout << tree1.sum(l, r) << " ";
            }

            if(s == 2)
            {
                cout << tree2.sum(l, r) << " ";
            }

            if(s == 3)
            {
                cout << tree3.sum(l, r) << " ";
            }

            if(s == 4)
            {
                cout << tree4.sum(l, r) << " ";
            }

        }
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    T = nxt();

    for(ll i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
