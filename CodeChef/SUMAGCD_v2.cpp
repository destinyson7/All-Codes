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

ll a[L];
ll uniq[L];
ll g[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;;

    while(T--)
    {
        ll N;
        cin >> N;

        set <ll> s;

        for(ll i=0; i<N; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }

        ll ind = 0;
        for(auto i : s)
        {
            uniq[ind++] = i;
        }

        if(uniq[0] == uniq[ind-1])
        {
            cout << 2*uniq[0] << endl;
            continue;
        }

        g[0] = uniq[0];

        // cout << ind << endl;

        for(ll i=1; i<ind-1; i++)
        {
            g[i] = gcd(g[i-1], uniq[i]);
        }

        ll ans = g[ind-2] + uniq[ind-1];
        ll cur = uniq[ind-1];

        for(ll i=ind-2; i>=1; i--)
        {
            cur = gcd(gcd(uniq[0], uniq[i+1]), cur);
            ans = max(gcd(g[i-1], cur) + uniq[i], ans);
        }

        cout << ans << endl;
    }

    return 0;
}