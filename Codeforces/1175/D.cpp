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

const ll L = 3e5+5;

ll a[L];
ll pref[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
    }

    pref[0] = a[0];

    for(ll i=1; i<n; i++)
    {
        pref[i] = a[i] + pref[i-1];
    }

    ll ans = pref[n-1]*k;

    pref[n-1] = 1e15;

    sort(pref, pref+n);


    for(ll i=0; i<k-1; i++)
    {
        ans-=pref[i];
    }

    cout << ans << endl;

    return 0;
}