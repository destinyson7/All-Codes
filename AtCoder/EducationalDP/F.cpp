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

const ll L = 3e3+10;

ll dp[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, t;
    cin >> s >> t;

    for(ll i=0; i<sz(s); i++)
    {
        for(ll j=0; j<sz(t); j++)
        {
            if(s[i]==t[j])
            {
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
            }

            else
            {
                dp[i+1][j+1] = max(dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1]));
            }
        }
    }

    ll cx = sz(s);
    ll cy = sz(t);

    string res = "";

    while(cx && cy)
    {
        if(dp[cx][cy]==dp[cx-1][cy])
        {
            cx--;
        }

        else if(dp[cx][cy]==dp[cx][cy-1])
        {
            cy--;
        }

        else
        {
            cx--;
            cy--;
            res = s[cx] + res;
        }
    }

    cout << res << endl;

    return 0;
}