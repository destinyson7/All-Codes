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

const ll L = 3e2+5;
double dp[L][L];
bool good[L][L];

ll w, h, l, u, r, d;

double cal(ll i, ll j)
{
    if(dp[i][j] > -0.5)
    {
        return dp[i][j];
    }

    if(!good[i][j])
    {
        return 0;
    }

    if(i == h - 1)
    {
        dp[i][j] = cal(i, j+1);
    }

    else if(j == w - 1)
    {
        dp[i][j] = cal(i+1, j);
    }

    else
    {
        dp[i][j] = 0.5 * cal(i+1, j) + 0.5 * cal(i, j+1);
    }

    // cout << i << " " << j << " " << dp[i][j] << endl;

    return dp[i][j];
}

void solve()
{
    cin >> w >> h >> l >> u >> r >> d;

    for(ll i=0; i<=h; i++)
    {
        for(ll j=0; j<=w; j++)
        {
            dp[i][j] = (double)(-1.0);
            good[i][j] = true;
        }
    }

    for(ll i=u-1; i<d; i++)
    {
        for(ll j=l-1; j<r; j++)
        {
            good[i][j] = false;
        }
    }

    dp[h-1][w-1] = (double)1.0;

    cout << fixed << setprecision(7) << cal(0, 0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    for(ll i=1; i<=T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}