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
double dp[L][L][L];

void solve()
{
    ll n = nxt();
    basic_string <ll> a(n, 0);
    generate(all(a), nxt);

    vector <ll> cnt(4, 0);

    for(ll i=0; i<n; i++)
    {
        cnt[a[i]]++;
    }

    for(ll c=0; c<=n; c++)
    {
        for(ll b=0; b<=n; b++)
        {
            for(ll a=0; a<=n; a++)
            {
                if(a+b+c > n)
                {
                    continue;
                }

                if(a + b + c == 0)
                {
                    continue;
                }

                dp[a][b][c] = 1;

                if(a)
                {
                    dp[a][b][c] += dp[a-1][b][c] * (double)a/n;
                }

                if(b)
                {
                    dp[a][b][c] += dp[a+1][b-1][c] * (double)b/n;
                }

                if(c)
                {
                    dp[a][b][c] += dp[a][b+1][c-1] * (double)c/n;
                }

                dp[a][b][c] *= (double)n/(a+b+c);
            }
        }
    }

    cout << fixed << setprecision(10) << dp[cnt[1]][cnt[2]][cnt[3]] << endl;
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