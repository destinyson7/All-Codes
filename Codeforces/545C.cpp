#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

const ll L = 1e5+5;

ll l = 0, s = 1, r = 2;

ll dp[L][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    vector <pll> p;

    for(ll i=0; i<n; i++)
    {
        ll x, h;
        cin >> x >> h;

        p.pb(mp(x, h));
    }

    dp[0][s] = 0;
    dp[0][l] = 1;
    dp[0][r] = 1;

    ll f = p[0].ff;
    ll t = p[0].ff + p[0].ss;
    ll o = p[0].ff;

    for(ll i=1; i<n; i++)
    {
        dp[i][s] = max(dp[i-1][s], dp[i-1][l]);

        if(t < p[i].ff)
        {
            dp[i][s] = max(dp[i][s], dp[i-1][r]);
        }

        dp[i][l] = -1e15;

        if(f < p[i].ff - p[i].ss)
        {
            dp[i][l] = max(dp[i][l], 1 + dp[i-1][l]);
        }

        if(o < p[i].ff - p[i].ss)
        {
            dp[i][l] = max(dp[i][l], 1 + dp[i-1][s]);
        }

        if(t < p[i].ff - p[i].ss)
        {
            dp[i][l] = max(dp[i][l], 1 + dp[i-1][r]);
        }

        dp[i][r] = 1 + max(dp[i-1][s], dp[i-1][l]);

        if(t < p[i].ff)
        {
            dp[i][r] = max(dp[i][r], 1 + dp[i-1][r]);
        }

        f = p[i].ff;
        o = p[i].ff;
        t = p[i].ff + p[i].ss;
    }

    cout << max(dp[n-1][s], max(dp[n-1][l], dp[n-1][r])) << endl;

    return 0;
}