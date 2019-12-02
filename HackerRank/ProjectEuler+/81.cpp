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

const ll L = 1e3+5;

ll a[L][L];
ll dp[L][L];

ll N;

ll solve(ll i, ll j)
{
    // cout << i << " " << j << " " << dp[i][j] << endl;

    if(i == N-1 && j == N-1)
    {
        return a[i][j];
    }

    if(i>=N || j>=N)
    {
        return 1e15;
    }

    if(dp[i][j]>=0)
    {
        return dp[i][j];
    }

    dp[i][j] = a[i][j] + min(solve(i+1, j), solve(i, j+1));

    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // ll N;
    cin >> N;

    for(ll i=0; i<N; i++)
    {
        for(ll j=0; j<N; j++)
        {
            cin >> a[i][j];
            dp[i][j] = -1;
        }
    }

    cout << solve(0, 0) << endl;

    return 0;
}