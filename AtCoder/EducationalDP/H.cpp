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

char a[L][L];
ll dp[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll H, W;
    cin >> H >> W;

    for(ll i=1; i<=H; i++)
    {
        for(ll j=1; j<=W; j++)
        {
            cin >> a[i][j];
        }
    }

    ll mod = 1e9+7;

    dp[1][1] = 1;

    for(ll i=0; i<=H; i++)
    {
        for(ll j=0; j<=W; j++)
        {
            if(!i || !j)
            {
                dp[i][j] = 0;
            }

            else
            {
                if(a[i][j]=='.')
                {
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]%=mod;
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]%=mod;
                }

                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }

    cout << dp[H][W] << endl;

    return 0;
}