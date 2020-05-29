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
double dp[L][4];

double distance(ll a, ll b, ll x, ll y)
{
    return sqrtl((a - x) * (a - x) + (b - y) * (b - y));
}

void solve()
{
    ll ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    ll n = nxt();

    for(ll i=0; i<L; i++)
    {
        for(ll j=0; j<4; j++)
        {
            dp[i][j] = (double)1e18;
        }
    }

    dp[0][0] = 0.0;

    for(ll i=0; i<n; i++)
    {
        ll x = nxt(), y = nxt();

        for(ll j=0; j<4; j++)
        {
            if(dp[i][j] > 1e17)
            {
                continue;
            }

            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 2 * distance(tx, ty, x, y));

            for(ll k=0; k<2; k++)
            {
                if(!((1LL << k) & j))
                {
                    dp[i+1][j | (1LL << k)] = min(dp[i+1][j | (1LL << k)], dp[i][j] + distance(x, y, tx, ty) + distance(((k&1) ? bx : ax), ((k&1) ? by : ay), x, y));
                }
            }
        }
    }

    double ans = 1e18;

    for(ll i=1; i<4; i++)
    {
        ans = min(ans, dp[n][i]);
    }

    cout << fixed << setprecision(10) << ans << endl;
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