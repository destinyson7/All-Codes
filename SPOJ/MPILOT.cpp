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

const ll L = 1e4 + 5;

ll dp[L][L / 2];
ll n;
ll x[L];
ll y[L];

ll rec(ll i, ll c, ll a)
{
    if(i == 1)
    {
        return dp[i][c] = y[i] + rec(i + 1, c, a + 1);
    }

    if(i == n + 1)
    {
        return 0;
    }

    if(dp[i][c] != -1)
    {
        return dp[i][c];
    }

    if(a == n/2)
    {
        return dp[i][c] = x[i] + rec(i + 1, c + 1, a);
    }

    if(c == a)
    {
        return dp[i][c] = y[i] + rec(i + 1, c, a + 1);
    }

    return dp[i][c] = min(rec(i + 1, c + 1, a) + x[i], rec(i + 1, c, a + 1) + y[i]);
}

void solve()
{
    n = nxt();

    for(ll i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << rec(1, 0, 0) << endl;
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