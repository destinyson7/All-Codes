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

// Using long long exceeds memory limit. Using ints

const ll L = 1e3 + 5;
const ll M = 1e5 + 5;

ll dp[M][L];
ll n, x;

ll h[L], s[L];

// ll res(ll ind, ll cur_price)
// {
//     // if(cur_price < 0)
//     // {
//     //     return 0;
//     // }

//     if(ind == 0)
//     {
//         return 0;
//     }

//     if(dp[ind][cur_price] != -1)
//     {
//         return dp[ind][cur_price];
//     }

//     dp[ind][cur_price] = res(ind - 1, cur_price);

//     if(cur_price >= h[ind])
//     {
//         dp[ind][cur_price] = max(dp[ind][cur_price], res(ind - 1, cur_price - h[ind]) + s[ind]);
//     }

//     return dp[ind][cur_price];
// }

void solve()
{
    n = nxt(), x = nxt();

    for(ll i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for(ll i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    for(ll j = 0; j <= x; j++)
    {
        dp[j][0] = 0;
    }

    for(ll j = 0; j <= x; j++)
    {
        for(ll i = 1; i <= n; i++)
        {
            dp[j][i] = dp[j][i - 1];

            if(j >= h[i])
            {
                dp[j][i] = max(dp[j][i], dp[j - h[i]][i - 1] + s[i]);
            }
        }
    }

    cout << dp[x][n] << endl;
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
