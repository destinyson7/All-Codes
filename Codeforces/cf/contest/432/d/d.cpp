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

vector <ll> z_function(string s)
{
    ll n = sz(s);
    vector <ll> z(n, 0);

    ll l = 0, r = 0;
    for(ll i = 1; i < n; i++)
    {
        if(i <= r)
        {
            z[i] = min(z[i - l], r - i + 1);
        }

        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }

        if(i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

void solve()
{
    string s;
    cin >> s;

    ll n = sz(s);

    vector <ll> z = z_function(s);
    z[0] = n;

    set <ll> matching_z;
    map <ll, ll> freq;

    for(ll i = 0; i < n; i++)
    {
        // cout << i << " " << z[i] << endl;

        if(i + z[i] == n)
        {
            // cout << "*" << endl;
            matching_z.insert(z[i]);
        }

        freq[z[i]]++;
    }

    vector <pll> pref_sum;

    for(auto i: freq)
    {
        pref_sum.pb(i);
    }

    pref_sum.pb(mp(0, 0));

    ll len = sz(pref_sum);

    map <ll, ll> new_freq;

    for(ll i = len - 2; i >= 0; i--)
    {
        pref_sum[i].ss += pref_sum[i + 1].ss;
        new_freq[pref_sum[i].ff] = pref_sum[i].ss;
    }

    cout << sz(matching_z) << endl;

    for(auto i: matching_z)
    {
        cout << i << " " << new_freq[i] << endl;
    }
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
