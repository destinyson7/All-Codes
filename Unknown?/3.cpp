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

#define pb push_backs
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
    ll w = nxt(), n = nxt();
    basic_string <ll> x(w, 0);
    generate(all(x), nxt);

    sort(all(x));

    ll ans = 1e18;

    for(ll i=0; i<min(w, 1000LL); i++)
    {
        ll target = x[i];
        ll cur = 0;

        for(ll j=0; j<w; j++)
        {
            if(x[j] < target)
            {
                cur += min(target - x[j], x[j] + n - target);
            }

            else
            {
                cur += min(x[j] - target, n - x[j] + target);
            }            
        }

        ans = min(ans, cur);
    }

    for(ll i=w-1; i>=max(0LL, w-1000LL); i--)
    {
        ll target = x[i];
        ll cur = 0;

        for(ll j=0; j<w; j++)
        {
            if(x[j] < target)
            {
                cur += min(target - x[j], x[j] + n - target);
            }

            else
            {
                cur += min(x[j] - target, n - x[j] + target);
            }            
        }

        ans = min(ans, cur);
    }

    for(ll i=max(0LL, w/2-500LL); i<=min(w-1, w/2+500LL); i++)
    {
        ll target = x[i];
        ll cur = 0;

        for(ll j=0; j<w; j++)
        {
            if(x[j] < target)
            {
                cur += min(target - x[j], x[j] + n - target);
            }

            else
            {
                cur += min(x[j] - target, n - x[j] + target);
            }            
        }

        ans = min(ans, cur);
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    for(ll t=1; t<=T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}