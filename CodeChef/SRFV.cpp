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

const ll L = 1e5+5;

ll dp[L][2];
ll a[L];

void init()
{
    for(ll i=0; i<L; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        init();

        ll N;
        cin >> N;

        for(ll i=1; i<=N; i++)
        {
            cin >> a[i];
        }

        dp[0][0] = 0;
        dp[0][1] = 0;

        dp[1][0] = a[1];
        dp[1][1] = a[1];

        for(ll i=2; i<=N; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + i*a[i];
            dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + i*a[i-1] + (i-1)*a[i];
        }

        cout << max(dp[N][0], dp[N][1]) << endl;
    }


    return 0;
}