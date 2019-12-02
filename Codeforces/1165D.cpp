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

const ll L = 1e6+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        vector <ll> d(n, 0);
        vector <ll> factors;

        for(ll i=0; i<n; i++)
        {
            cin >> d[i];
        }

        sort(all(d));

        ll ans = d[0]*d[n-1];

        for(ll i=2; i*i<=ans; i++)
        {
            if(ans%i == 0)
            {
                factors.pb(i);

                if(i*i!=ans)
                {
                    factors.pb(ans/i);
                }
            }
        }

        sort(all(factors));

        if(d == factors)
        {
            cout << ans << endl;
        }

        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}