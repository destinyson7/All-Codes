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
    string s;

    vector <string> v;

    ll siz = 0;

    while(cin >> s)
    {
        siz = sz(s);
        v.pb(s);
    }

    vector <string> copy = v;

    for(ll i = 0; i < siz; i++)
    {
        ll cnt1 = 0, cnt0 = 0;

        vector <string> ones, zeros;

        for(auto s: v)
        {
            if(s[i] == '1')
            {
                cnt1++;
                ones.pb(s);
            }

            else
            {
                cnt0++;
                zeros.pb(s);
            }
        }

        if(cnt1 >= cnt0)
        {
            v = ones;
        }

        else
        {
            v = zeros;
        }

        if(sz(v) == 1)
        {
            break;
        }
    }

    ll oxy = 0;
    ll pow = 1;

    for(ll i = siz - 1; i >= 0; i--)
    {
        if(v[0][i] == '1')
        {
            oxy += pow;
        }

        pow *= 2;
    }

    v = copy;

    for(ll i = 0; i < siz; i++)
    {
        ll cnt1 = 0, cnt0 = 0;

        vector <string> ones, zeros;

        for(auto s: v)
        {
            if(s[i] == '1')
            {
                cnt1++;
                ones.pb(s);
            }

            else
            {
                cnt0++;
                zeros.pb(s);
            }
        }

        if(cnt1 >= cnt0)
        {
            v = zeros;
        }

        else
        {
            v = ones;
        }

        if(sz(v) == 1)
        {
            break;
        }
    }

    ll co2 = 0;
    pow = 1;

    for(ll i = siz - 1; i >= 0; i--)
    {
        if(v[0][i] == '1')
        {
            co2 += pow;
        }

        pow *= 2;
    }

    ll ans = oxy * co2;

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}