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

const ll L = 1e2+5;

bool c[L];
bool g[L];

ll dp[L][3];

ll rest = 0, contest = 1, gym = 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        if(a&1)
        {
            c[i] = true;
        }

        if(a >= 2)
        {
            g[i] = true;
        }
    }

    for(ll i=0; i<n; i++)
    {
        if(!i)
        {
            dp[i][rest] = 1;

            if(c[i])
            {
                dp[i][contest] = 0;
            }

            else
            {
                dp[i][contest] = 1e15;
            }

            if(g[i])
            {
                dp[i][gym] = 0;
            }

            else
            {
                dp[i][gym] = 1e15;
            }
        }

        else
        {
            dp[i][rest] = 1 + min(dp[i-1][rest], min(dp[i-1][contest], dp[i-1][gym]));
            
            if(c[i])
            {
                dp[i][contest] = min(dp[i-1][rest], dp[i-1][gym]);
            }

            else
            {
                dp[i][contest] = 1e15;
            }

            if(g[i])
            {
                dp[i][gym] = min(dp[i-1][rest], dp[i-1][contest]);
            }

            else
            {
                dp[i][gym] = 1e15;
            }
        }
    }

    cout << min(dp[n-1][rest], min(dp[n-1][contest], dp[n-1][gym])) << endl;

    return 0;
}