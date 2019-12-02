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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll n;
        cin >> n;

        string s;
        cin >> s;

        ll req = 0;

        if(n%4 == 0)
        {
            req = n/4;
            req*=3;
        }

        else
        {
            req = (3*n)/4 + 1;
        }

        for(ll i=0; i<n; i++)
        {
            if(s[i]=='P')
            {
                req--;
            }
        }

        if(req<=0)
        {
            cout << 0 << endl;
        }

        else
        {
            ll ans = req;
            for(ll i=2; i<n-2; i++)
            {
                if(s[i]=='A')
                {
                    if(s[i-1]=='P' || s[i-2]=='P')
                    {
                        if(s[i+1]=='P' || s[i+2]=='P')
                        {
                            req--;

                            // if(req>0)
                            // {
                            //     ans++;
                            // }
                        }
                    }
                }
            }

            if(req<=0)
            {
                cout << ans << endl;
            }

            else
            {
                cout << -1 << endl;
            }
        }

    }

    return 0;
}