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

const ll L = 5e3+5;

vector <pll> intervals;
ll cnt[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, q;
    cin >> n >> q;

    for(ll i=0; i<q; i++)
    {
        ll l, r;
        cin >> l >> r;

        l--;
        r--;

        intervals.pb(mp(l, r));

        for(ll j=l; j<=r; j++)
        {
            cnt[j]++;
        }
    }

    ll ans = 0;

    for(ll i=0; i<q; i++)
    {
        ll l = intervals[i].ff;
        ll r = intervals[i].ss;

        for(ll j=l; j<=r; j++)
        {
            cnt[j]--;
        }

        ll cur = 0;

        vector <ll> ones(L, 0);

        for(ll j=0; j<n; j++)
        {
            if(cnt[j] > 0)
            {
                cur++;
            }

            if(cnt[j]==1)
            {
                ones[j]++;
            }
        }

        for(ll j=1; j<n; j++)
        {
            ones[j]+=ones[j-1];
        }

        for(ll j=i+1; j<q; j++)
        {
            ll l2 = intervals[j].ff;
            ll r2 = intervals[j].ss;
            
            ll lost = 0;

            if(l2)
            {
                lost = ones[r2] - ones[l2-1];
            } 

            else
            {
                lost = ones[r2];
            }

            ans = max(ans, cur - lost);
        }

        for(ll j=l; j<=r; j++)
        {
            cnt[j]++;
        }
    }

    cout << ans << endl;

    return 0;
}