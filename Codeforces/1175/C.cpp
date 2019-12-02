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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll n, k;
        cin >> n >> k;

        vector <ll> a(L, 0);

        for(ll i=0; i<n; i++)
        {
            cin >> a[i];
        }

        ll ans = 0;

        ll high = a[k] - a[0];

        ll cur = high;
        ll ind = 0;
        ll at = 0;

        for(ll i=k+1; i<n; i++)
        {
            ind++;
            cur = a[i] - a[ind];

            if(high > cur)
            {
                at = ind;
            }

            high = min(high, cur);

        }

        cout << a[at] + high - high/2 << endl;
    }

    return 0;
}