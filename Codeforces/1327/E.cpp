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

const ll L = 2e5+15;
const ll mod = 998244353;

void solve()
{
    ll n = nxt();   

    basic_string <ll> v;
    
    for(ll i=0; i<10; i++)
    {
        v.pb(0);
    }

    v.pb(1);

    ll sum = 1;

    // cout << "**" << endl;

    for(ll i=11; i<L; i++)
    {
        ll x = ((modexp(10, i-11, mod) - v[i-11])%mod + mod)%mod;
        x += sum;
        x %= mod;

        x *= 9;
        x %= mod;

        // cout << i << " " << x << endl;
        v.pb(x);
        sum += x;
        sum %= mod;

    }

    // cout << "here" << endl;

    basic_string <ll> ans;

    for(ll i=0; i<n-1; i++)
    {
        ll x = (n-i-2) * modexp(10, n-i-2, mod);
        x %= mod;
        x *= 9;
        x %= mod;
        x *= 9;
        x %= mod;

        x += ((180*modexp(10, n-i-2, mod))%mod);
        x %= mod;

        ans += x;
    }

    ans += 10;

    for(ll i=0; i<n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    // T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}