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

const ll L = 1e5+5;

vector <ll> a;
vector <pll> p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, S;
    cin >> n >> S;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);

        p.pb(mp(t, i+1));
    }

    sort(all(p));

    ll low = 1;
    ll high = n;

    ll ans = 0;
    ll cost = 0;

    ll cur = 0;

    while(low <= high)
    {
        ll mid = low + (high-low)/2;

        vector <ll> upd;
        cur = 0;

        for(ll i=0; i<n; i++)
        {
            upd.pb(a[i] + mid*(i+1));
        }

        sort(all(upd));

        for(ll i=0; i<mid; i++)
        {
            cur+=upd[i];
        }

        if(cur <= S)
        {
            ans = mid;
            cost  = cur;

            low = mid+1;
        }

        else
        {
            high = mid-1;
        }
    }

    cout << ans << " " << cost << endl;


    return 0;
}