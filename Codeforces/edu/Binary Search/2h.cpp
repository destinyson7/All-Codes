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

const ll L = 2e5 + 5;
string s;
ll nb, ns, nc;
ll pb, ps, pc;
ll rb, rs, rc;
ll r;

bool check(ll num)
{
    ll totb = num * rb;
    ll tots = num * rs;
    ll totc = num * rc;

    ll needb = max(0LL, totb - nb);
    ll needs = max(0LL, tots - ns);
    ll needc = max(0LL, totc - nc);

    ll money = pb * needb + ps * needs + pc * needc;

    return (r >= money);
}

void solve()
{
    cin >> s;

    for(ll i = 0; i < sz(s); i++)
    {
        if(s[i] == 'B')
        {
            rb++;
        }

        else if(s[i] == 'S')
        {
            rs++;
        }

        else
        {
            rc++;
        }
    }

    nb = nxt(), ns = nxt(), nc = nxt();
    pb = nxt(), ps = nxt(), pc = nxt();
    r = nxt();

    ll low = 0, high = 1e15;
    ll ans = 0;

    while(low <= high)
    {
        ll mid = low + (high - low)/2;

        if(check(mid))
        {
            ans = mid;
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

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
