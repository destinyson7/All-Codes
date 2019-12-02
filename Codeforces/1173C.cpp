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

const ll L = 2e5+5;

ll a[L];
ll b[L];
ll pos[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=1; i<=n; i++)
    {
        cin >> a[i];
        pos[a[i]] = 0;
    }

    for(ll i=1; i<=n; i++)
    {
        cin >> b[i];
        pos[b[i]] = i;
    }

    if(pos[1])
    {
        ll i =2;
        for(i=2; i<=n; i++)
        {
            if(pos[i] != pos[1]+i-1)
            {
                break;
            }
        }

        if(pos[i-1] == n)
        {
            bool f = false;
            ll now = 0;
            for(ll j=i; j<=n; j++)
            {
                if(pos[j] > now)
                {
                    f = true;
                    break;
                }

                now++;
            }

            if(!f)
            {
                cout << n - (i-1) << endl;
                return 0;
            }
        }
    }

    bool f = false;

    for(ll i=1; i<=n; i++)
    {
        if(pos[i] >= i)
        {
            f = true;
            break;
        }
    }

    if(f)
    {
        ll ans = 0;
        for(ll i=1; i<=n; i++)
        {
            ans = max(ans, pos[i]-i+1);
        }

        cout << ans+n << endl;
    }

    else
    {
        cout << n << endl;
    }

    return 0;
}