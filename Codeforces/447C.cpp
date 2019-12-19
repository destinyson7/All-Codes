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

const ll L = 1e5+5;

ll a[L];
ll l[L];
ll r[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    for(ll i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    for(ll i=1; i<=n; i++)
    {
        if(a[i] > a[i-1])
        {
            l[i] = l[i-1] + 1;
        }

        else
        {
            l[i] = 1;
        }

        // cout << l[i] << " ";
    }
    // cout << endl;

    a[n+1] = 1e15;

    for(ll i=n; i>0; i--)
    {
        if(a[i] < a[i+1])
        {
            r[i] = r[i+1] + 1;
        }

        else
        {
            r[i] = 1;
        }

        // cout << r[i] << " ";
    }
    // cout << endl;

    ll ans = 0;

    // a[n+1] = 0;

    for(ll i=1; i<=n; i++)
    {
        if(a[i+1] - a[i-1] >= 2)
        {
            // cout << i << " * " << l[i-1] + 1 + r[i+1] << endl;
            ans = max(ans, l[i-1] + 1 + r[i+1]);
        }

        ans = max(ans, l[i-1]+1);
        ans = max(ans, 1+r[i+1]);
    }

    cout << ans << endl;

    return 0;
}