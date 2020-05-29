#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef int ll;
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

const ll L = 2e5+5;
ll a[L];

map <pll, ll> dp;

ll cal(ll i, ll j)
{
    if(i == j)
    {
        return a[i];
    }

    if(dp.count(mp(i, j)))
    {
        return dp[mp(i, j)];
    }

    if(i == j)
    {
        dp[mp(i, j)] = a[i];
        return a[i];
    }

    ll ans = cal(i, j-1);

    if ((j-i+1) & 1)
    {
        ans += (j-i+1) * a[j];
    }

    else
    {
        ans -= (j-i+1) * a[j];
    }

    dp[mp(i, j)] = ans;
    // cout << i << " " << j << " " << ans << endl;
    return ans;
}

void solve()
{
    dp.clear();

    ll n = nxt(), q = nxt();
    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll final = 0;

    while(q--)
    {
        char c;
        ll l, r;
        cin >> c >> l >> r;

        if(c == 'U')
        {
            dp.clear();
            a[l-1] = r;
        }

        else
        {
            l--, r--;
            final += cal(l, r); 
        }

        // cout << final << endl;
    }

    cout << final << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    for(ll i=1; i<=T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}