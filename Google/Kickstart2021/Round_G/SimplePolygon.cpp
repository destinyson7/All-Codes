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

// Shoelace Formula code from: https://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/
ll polygonArea(vector <ll> X, vector <ll> Y, ll n)
{
    // Initialize area
    ll area = 0;

    // Calculate value of shoelace formula
    ll j = n - 1;
    for (ll i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;  // j is previous vertex to i
    }

    // Return absolute value
    return abs(area);
}

void solve()
{
    ll n = nxt(), a = nxt();

    if(n == 5)
    {
        if(a <= 2)
        {
            cout << "IMPOSSIBLE" << endl;
        }

        else
        {
            cout << "POSSIBLE" << endl;
            cout << 0 << " " << 0 << endl;
            cout << 0 << " " << 1 << endl;
            cout << 2 << " " << a - 1 << endl;
            cout << 1 << " " << 1 << endl;
            cout << 1 << " " << 0 << endl;

            vector <ll> ff, ss;
            ff.pb(0);
            ff.pb(0);
            ff.pb(2);
            ff.pb(1);
            ff.pb(1);

            ss.pb(0);
            ss.pb(1);
            ss.pb(a - 1);
            ss.pb(1);
            ss.pb(0);

            assert(polygonArea(ff, ss, n) == a);
        }
    }

    else if(n == 4)
    {
        if(a == 1)
        {
            cout << "IMPOSSIBLE" << endl;
        }

        else if(a % 2 == 1)
        {
            cout << "POSSIBLE" << endl;
            cout << 0 << " " << 0 << endl;
            cout << 0 << " " << 1 << endl;
            cout << 1 << " " << a - 1 << endl;
            cout << 1 << " " << 0 << endl;

            vector <ll> ff, ss;
            ff.pb(0);
            ff.pb(0);
            ff.pb(1);
            ff.pb(1);

            ss.pb(0);
            ss.pb(1);
            ss.pb(a - 1);
            ss.pb(0);

            assert(polygonArea(ff, ss, n) == a);
        }

        else
        {
            cout << "POSSIBLE" << endl;
            cout << 0 << " " << 0 << endl;
            cout << 0 << " " << 1 << endl;
            cout << a / 2 << " " << 1 << endl;
            cout << a / 2 << " " << 0 << endl;

            vector <ll> ff, ss;
            ff.pb(0);
            ff.pb(0);
            ff.pb(a / 2);
            ff.pb(a / 2);

            ss.pb(0);
            ss.pb(1);
            ss.pb(1);
            ss.pb(0);

            assert(polygonArea(ff, ss, n) == a);
        }
    }

    else if(n == 3)
    {
        cout << "POSSIBLE" << endl;
        cout << 0 << " " << 0 << endl;
        cout << 0 << " " << 1 << endl;
        cout << a << " " << 0 << endl;

        vector <ll> ff, ss;
        ff.pb(0);
        ff.pb(0);
        ff.pb(a);

        ss.pb(0);
        ss.pb(1);
        ss.pb(0);

        assert(polygonArea(ff, ss, n) == a);
    }

    else
    {
        assert(false);
    }
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
