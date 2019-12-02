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

ll cnt[10];

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

        cnt[a]++;
    }

    ll ans = cnt[4];

    if(cnt[2]%2 == 0)
    {
        ans+=(cnt[2]/2);
        
        if(cnt[1] > cnt[3])
        {
            ans+=cnt[3];

            cnt[1]-=cnt[3];

            if(cnt[1]%4 == 0)
            {
                ans+=(cnt[1]/4);
            }

            else
            {
                ans+=(cnt[1]/4 + 1);
            }
        }

        else
        {
            ans+=cnt[1];

            cnt[3]-=cnt[1];

            ans+=cnt[3];
        }
    }

    else
    {
        ans+=(cnt[2]/2);

        if(cnt[1] > cnt[3])
        {
            ans+=cnt[3];

            cnt[1]-=cnt[3];

            if(cnt[1]%4<=2)
            {
                ans+=(cnt[1]/4);
                ans++;
            }

            else
            {
                ans+=(cnt[1]/4);
                ans+=2;
            }
        }

        else
        {
            ans+=cnt[1];

            cnt[3]-=cnt[1];

            ans+=cnt[3];

            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}