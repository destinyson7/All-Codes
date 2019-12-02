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

const ll L = 1e5+5;

ll mod = 1e9+7;

ll dp[L];

ll solve(ll i)
{
    if(!i)
    {
        return 1;
    }

    if(dp[i]>=0)
    {
        return dp[i];
    }

    dp[i] = i*solve(i-1);
    dp[i]%=mod;

    return dp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    for(ll i=0; i<L; i++)
    {
        dp[i] = -1;
    }

    while(T--)
    {
        ll N;
        cin >> N;

        cout << solve(N) << endl;
    }

    return 0;
}
