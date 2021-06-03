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

const ll L = 1e3 + 2;

ll n, m, k;
string s, t;

ll dp[L][L][12][2];

ll rec(ll is, ll it, ll rem, ll cont)
{
    if(is == n || it == m)
    {
        if(rem == 0)
        {
            // cout << is << " " << it << " " << rem << " " << cont << " " << 0 << endl;
            return 0;
        }

        else
        {
            // cout << is << " " << it << " " << rem << " " << cont << " " << "-inf" << endl;
            return -1e15;
        }
    }

    // if(rem == 0 && cont == 0)
    // {
    //     return 0;
    // }

    if(dp[is][it][rem][cont] != -1)
    {
        return dp[is][it][rem][cont];
    }


    if(cont == 1)
    {
        dp[is][it][rem][cont] = rec(is + 1, it, rem, 0);
        dp[is][it][rem][cont] = max(dp[is][it][rem][cont], rec(is, it + 1, rem, 0));
        dp[is][it][rem][cont] = max(dp[is][it][rem][cont], rec(is, it, rem, 0));

        if(s[is] == t[it])
        {
            dp[is][it][rem][cont] = max(dp[is][it][rem][cont], 1 + rec(is + 1, it + 1, rem, 1));
        }
    }

    else
    {
        dp[is][it][rem][cont] = rec(is + 1, it, rem, 0);
        dp[is][it][rem][cont] = max(dp[is][it][rem][cont], rec(is, it + 1, rem, 0));

        if(s[is] == t[it] && rem > 0)
        {
            dp[is][it][rem][cont] = max(dp[is][it][rem][cont], 1 + rec(is + 1, it + 1, rem - 1, 1));
        }
    }

    // cout << is << " " << it << " " << rem << " " << cont << " " << dp[is][it][rem][cont] << endl;
    return dp[is][it][rem][cont];
}

void solve()
{
    for(ll i = 0; i < L; i++)
    {
        for(ll j = 0; j < L; j++)
        {
            for(ll k = 0; k < 12; k++)
            {
                for(ll w = 0; w < 2; w++)
                {
                    dp[i][j][k][w] = -1;
                }
            }
        }
    }

    n = nxt(), m = nxt(), k = nxt();

    cin >> s;
    cin >> t;

    cout << rec(0, 0, k, 0) << endl;

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
