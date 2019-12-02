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

const ll L = 1e2+5;
const ll M = 1e5+5;

ll w[L], v[L];
ll ans[L][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, W;
    cin >> N >> W;
    
    for(ll i=1; i<=N; i++)
    {
        cin >> w[i] >> v[i];
    }

    for(ll i=0; i<=N; i++)
    {
        for(ll j=0; j<=W; j++)
        {
            if(!i || !j)
            {
                ans[i][j] = 0;
            }

            else if(j < w[i])
            {
                ans[i][j] = ans[i-1][j];
            }

            else
            {
                ans[i][j] = max(v[i]+ans[i-1][j-w[i]], ans[i-1][j]);
            }

            // cout << ans[i][j] << " ";
        }
        // cout << endl;
    }

    cout << ans[N][W] << endl;

    return 0;
}