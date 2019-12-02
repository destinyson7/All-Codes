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

const ll L = 55;
const ll M = 255;

ll c[L];
ll dp[L][M];

ll m;

ll solve(ll pos, ll rem)
{
    // cout << pos << " " << rem << endl;
    if(pos == m)
    {
        return rem == 0;
    }

    if(rem < 0)
    {
        return 0;
    }

    if(dp[pos][rem]>=0)
    {
        return dp[pos][rem];
    }

    dp[pos][rem] = solve(pos, rem-c[pos]) + solve(pos+1, rem);

    return dp[pos][rem];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n >> m;

    for(ll i=0; i<m; i++)
    {
        cin >> c[i];
    }

    for(ll i=0; i<L; i++)
    {
        for(ll j=0; j<M; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << solve(0, n) << endl;

    return 0;
}