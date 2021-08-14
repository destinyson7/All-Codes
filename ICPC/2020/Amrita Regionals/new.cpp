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
    vector <ll> v(3);
    cin >> v[0];
    cin >> v[1];
    cin >> v[2];

    bool possible = false;
    ll max_area = 0;
    ll final = 0;

    {
        ll a = v[0];
        ll b = v[1];
        ll c = v[2];

        if(((c + b) >= a) && ((c + b - a) % 2 == 0) && ((c + a) >= b && (c + a - b) <= 2 * a))
        {
            possible = true;

            ll area = ((c + b - a) / 2) * a;

            if(area > max_area)
            {
                max_area = area;
                final = 1;
            }
        }
    }

    {
        ll a = v[1];
        ll b = v[2];
        ll c = v[0];

        if(((c + b) >= a) && ((c + b - a) % 2 == 0) && ((c + a) >= b && (c + a - b) <= 2 * a))
        {
            possible = true;

            ll area = ((c + b - a) / 2) * a;

            if(area > max_area)
            {
                max_area = area;
                final = 2;
            }
        }
    }

    {
        ll a = v[2];
        ll b = v[0];
        ll c = v[1];

        if(((c + b) >= a) && ((c + b - a) % 2 == 0) && ((c + a) >= b && (c + a - b) <= 2 * a))
        {
            possible = true;

            ll area = ((c + b - a) / 2) * a;

            if(area > max_area)
            {
                max_area = area;
                final = 3;
            }
        }
    }

    if(!possible)
    {
        cout << "NO" << endl;
    }

    else
    {
        // cout << final << endl;
        cout << "YES" << endl;

        if(final == 1)
        {
            ll x = (v[2] + v[1] - v[0]) / 2;

            cout << 1 << " " << 1 << endl;
            cout << 1 + v[0] << " " << 1 << endl;
            cout << 1 + v[2] - x << " " << 1 + x << endl;
        }

        else if(final == 2)
        {
            ll x = (v[0] + v[2] - v[1]) / 2;

            cout << 1 + v[0] - x << " " << 1 + x << endl;
            cout << 1 << " " << 1 << endl;
            cout << 1 + v[1] << " " << 1 << endl;
        }

        else if(final == 3)
        {
            ll x = (v[1] + v[0] - v[2]) / 2;

            cout << 1 + v[2] << " " << 1 << endl;
            cout << 1 + v[1] - x << " " << 1 + x << endl;
            cout << 1 << " " << 1 << endl;

        }
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
