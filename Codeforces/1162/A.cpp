#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 55;
vector <ll> maxi(L);
vector <ll> flag(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, h, m;
    cin >> n >> h >> m;

    for(ll i=0; i<=n; i++)
    {
        maxi[i] = h;
    }

    for(ll i=0; i<m; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;

        for(ll j=l; j<=r; j++)
        {
            maxi[j] = min(maxi[j], x);
        }
    }

    ll ans = 0;

    ll temp = h;
    for(ll i=n; i>=1; i--)
    {
        // if(flag[i]==1)
        // {
        //     temp = maxi[i];
        // }

        ans+=(maxi[i]*maxi[i]);
    }

    cout << ans << endl;

    return 0;
}