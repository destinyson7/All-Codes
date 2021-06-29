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

const ll L = 1e2 + 5;
const ll mod = 1e2;

ll n;
ll a[L];
ll prefix[L];
ll dp[L][L];

ll res(ll i, ll j)
{
    if(i == j)
    {
        return dp[i][j] = 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    ll ans = 1e15;

    for(ll k = i; k < j; k++)
    {
        ll sum = ((prefix[k] - prefix[i - 1]) % mod + mod)%mod;
        sum *= (((prefix[j] - prefix[k]) % mod + mod)%mod);
        ans = min(ans, res(i, k) + res(k + 1, j) + sum);
    }

    return dp[i][j] = ans;
}

void solve()
{
    // n = nxt();

    for(ll i = 1; i <= n; i++)
    {
        a[i] = nxt();
        prefix[i] = prefix[i - 1] + a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << res(1, n) << endl;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // T = nxt();

    while(cin >> n)
    {
        solve();
    }

    return 0;
}
