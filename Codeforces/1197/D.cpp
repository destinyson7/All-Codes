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
     
    const ll L = 3e5+5;
    const ll M = 1e1+5;
     
    ll dp[L][M];
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        
        ll n, m, k;
        cin >> n >> m >> k;
     
        vector <ll> a;
     
        for(ll i=0; i<n; i++)
        {
            ll t;
            cin >> t;
     
            a.pb(t);
        }
     
        ll res = 0;
        
        if(m == 1)
        {
            for(ll i=0; i<n; i++)
            {
                dp[i+1][0] = dp[i][m-1] + a[i] - 1*k;
     
                res = max(res, dp[i+1][0]);
     
                for(ll j=1; j<m; j++)
                {
                    if(j == i+1)
                    {
                        break;
                    }
     
                    dp[i+1][j] = dp[i][j-1] + a[i];
     
                    res = max(res, dp[i+1][j]);
                }
     
                dp[i+1][0] = max(dp[i+1][0], a[i]-k);
     
                res = max(res, dp[i+1][0]);
            }
            
            cout << res << endl;
            
            return 0;
        }
     
        for(ll i=0; i<n; i++)
        {
            dp[i+1][1] = dp[i][0] + a[i] - 1*k;
            dp[i+1][1] = max(dp[i+1][1], a[i]-k);
     
            res = max(res, dp[i+1][1]);
     
            for(ll j=2; j<=min(i+1, m); j++)
            {
                if(j == 1)
                {
                    break;
                }
     
                if(j == m)
                {
                    j = 0;
                }
     
                dp[i+1][j] = dp[i][(m+j-1)%m] + a[i];
     
                res = max(res, dp[i+1][j]);
            }
        }
     
        cout << res << endl;
     
        return 0;
    }