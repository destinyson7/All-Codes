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

ll a[L];
ll cnt[L];
ll dp[L];

ll solve(ll i)
{
    if(!i || i==-1)
    {
        return 0;
    }

    if(dp[i]>=0)
    {
        return dp[i];
    }

    dp[i] = max(solve(i-1), solve(i-2) + cnt[i]*i);

    return dp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<L; i++)
    {
        dp[i] = -1;
    }

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];

        cnt[a[i]]++;
    }

    cout << solve(100000) << endl;

    return 0;
}