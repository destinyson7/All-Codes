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

const ll L = 1e4 + 5;
const ll mod = 1e9 + 7;

ll n;
ll dp[2][L];
ll freq[L];

bool isPrime[L];

void sieve()
{
    for(ll i = 2; i < L; i++)
    {
        isPrime[i] = true;
    }

    for(ll i = 2; i < L; i++)
    {
        if(isPrime[i])
        {
            for(ll j = 2 * i; j < L; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void solve()
{
    n = nxt();

    for(ll i = 0; i < 2; i++)
    {
        for(ll j = 0; j < L; j++)
        {
            dp[i][j] = 0;
            freq[j] = 0;
        }
    }

    for(ll i = 0; i < n; i++)
    {
        freq[nxt()]++;
    }

    ll cur = 1;
    dp[0][0] = 1;

    for(ll i = 3500; i <= 4500; i++)
    {
        for(ll j = 0; j < (1LL << 13); j++)
        {
            dp[cur][j] = dp[cur ^ 1][j] * (1 + freq[i] / 2) + dp[cur ^ 1][j ^ i] * ((freq[i] + 1) / 2);
            dp[cur][j] %= mod;
        }

        cur ^= 1;
    }

    ll ans = 0;

    for(ll j = 0; j < (1LL << 13); j++)
    {
        if(isPrime[j])
        {
            // cout << "*" << endl;
            ans += dp[cur ^ 1][j];

            // if(dp[cur ^ 1][j] > 0)
            // {
            //     cout << j << " " << dp[cur ^ 1][j] << endl;
            // }

            ans %= mod;
        }
    }

    cout << ans << endl;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    sieve();

    ll T = 1;
    T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}
