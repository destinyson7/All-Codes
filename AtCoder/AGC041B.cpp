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

bool can(ll index, basic_string <ll> a, ll n, ll m, ll v, ll p)
{
    if(v < p)
    {
        if(a[index] + m >= a[n-p])
        {
            return true;
        }

        return false;
    }

    ll voted = m;

    for(ll i=0; i<n; i++)
    {
        if(i == index)
        {
            continue;
        }

        if(i > n - p)
        {
            voted += m;
        }

        else if(a[i] > a[index] + m)
        {
            return false;
        }

        else
        {
            voted += max(0LL, min(m, a[index] + m - a[i]));
        }
    }

    return (voted >= m*v);
}

void solve()
{
    ll n = nxt(), m = nxt(), v = nxt(), p = nxt();
    basic_string <ll> a(n, 0);
    generate(all(a), nxt);
    sort(all(a));

    ll low = 0, high = n;
    ll ans = -1;

    while(low <= high)
    {
        ll mid = low + (high - low)/2;

        if(can(mid, a, n, m, v, p))
        {
            ans = mid;
            high = mid-1;
        }

        else
        {
            low = mid + 1;
        }
    }

    assert(ans != -1);

    cout << n - ans << endl;
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