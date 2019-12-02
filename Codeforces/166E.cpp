#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e7+5;

ll dp[2][L];

ll mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll n;
    cin >> n;

    dp[1][0] = 1;

    for(ll i=1; i<=n; i++)
    {
        dp[1][i] = (dp[0][i-1]*3)%mod;
        dp[0][i] = (dp[0][i-1]*2%mod + dp[1][i-1]%mod)%mod;

        // cout << dp[0][i] << " " << dp[1][i] << endl;
    }

    cout << dp[1][n] << endl;   

    return 0;
}