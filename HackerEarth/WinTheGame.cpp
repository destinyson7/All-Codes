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

// float dp[L];

float solve(ll R, ll G)
{
    if(R == 0 || G == 0 || G == -1)
    {
        return (float)1;
    }

    float t1 = solve(R, G-2);
    float t2 = (float)(G-1)/(R+G-1);

    float ans = (float)R/(R+G) + ((float)G/(R+G))*t1*t2;
    // cout << R << " " << G << " " << ans << endl;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll R, G;
        cin >> R >> G;

        // for(ll i=0; i<L; i++)
        // {
        //     dp[i] = -1;
        // }

        cout << fixed << setprecision(6) << solve(R, G) << endl;
    }

    return 0;
}