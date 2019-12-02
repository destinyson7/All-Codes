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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll q;
    cin >> q;

    while(q--)
    {
        ll n;
        cin >> n;

        ll f = 1e5;
        ll s  = f;
        ll t = -f;
        ll e = -f;

        for(ll i=0; i<n; i++)
        {
            ll x, y;
            cin >> x >> y;

            ll a;
            cin >> a;

            if(!a)
            {
                t = max(t, x);
            }

            cin >> a;

            if(!a)
            {
                s = min(s, y);
            }

            cin >> a;

            if(!a)
            {
                f = min(f, x);
            }

            cin >> a;

            if(!a)
            {
                e = max(e, y);
            }
        }

        if(f < t || s < e)
        {
            cout << 0 << endl;
        }

        else
        {
            cout << "1 " << t << " " << s << endl;
        }
    }   


    return 0;
}