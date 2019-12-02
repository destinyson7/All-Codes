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
    
    ll n;
    cin >> n;

    ll b = 0;
    ll c = 0;
    ll d = 0;
    ll e = 0;
    ll f = 0;
    ll g = 0;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        if(a == 4)
        {
            b++;
        }

        else if(a == 8)
        {
            c++;

            c = min(b, c);
        }

        else if(a == 15)
        {
            d++;

            d = min(b, min(c, d));
        }

        else if(a == 16)
        {
            e++;

            e = min(b, min(c, min(d, e)));
        }

        else if(a == 23)
        {
            f++;

            f = min(b, min(c, min(d, min(e, f))));
        }

        else
        {
            g++;

            g = min(b, min(c, min(d, min(e, min(f, g)))));
        }
    }

    ll ans = min(b, min(c, min(d, min(e, min(f, g)))));

    cout << n - 6*ans << endl;

    return 0;
}