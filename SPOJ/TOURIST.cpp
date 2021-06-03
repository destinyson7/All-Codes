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

ll w, h;
char grid[L][L];
ll dp[L][L][L];

ll rec(ll x1, ll y1, ll x2)
{
    ll y2 = x1 + y1 - x2;

    if(x1 >= h || x2 >= h || y1 >= w || y2 >= w)
    {
        return -1e15;
    }

    if(dp[x1][y1][x2] != -1)
    {
        return dp[x1][y1][x2];
    }

    if(x1 == h - 1 && y1 == w - 1)
    {
        return dp[x1][y1][x2] = (grid[x1][y1] == '*');
    }

    if(grid[x1][y1] == '#' || grid[x2][y2] == '#')
    {
        // cout << mp(x1, y1) << " " << mp(x2, y2) << " " << "-inf" << endl;
        return dp[x1][y1][x2] = -1e15;
    }

    ll cur = 0;

    if(grid[x1][y1] == '*')
    {
        cur++;
    }

    if((x1 != x2 || y1 != y2) && grid[x2][y2] == '*')
    {
        cur++;
    }

    ll one = rec(x1 + 1, y1, x2 + 1);
    ll two = rec(x1 + 1, y1, x2);
    ll three = rec(x1, y1 + 1, x2 + 1);
    ll four = rec(x1, y1 + 1, x2);

    dp[x1][y1][x2] = cur + max({one, two, three, four});

    // cout << mp(x1, y1) << " " << mp(x2, y2) << " " << dp[x1][y1][x2] << endl;
    return dp[x1][y1][x2];
}

void solve()
{
    w = nxt(), h = nxt();

    for(ll i = 0; i <= h; i++)
    {
        for(ll j = 0; j <= w; j++)
        {
            for(ll k = 0; k <= h; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }

    for(ll i = 0; i < h; i++)
    {
        for(ll j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << rec(0, 0, 0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}
