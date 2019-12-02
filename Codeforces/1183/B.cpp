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
        ll n, k;
        cin >> n >> k;

        vector <ll> a;

        for(ll i=0; i<n; i++)
        {
            ll t;
            cin >> t;

            a.pb(t);
        }

        ll f = a[0];
        ll s = a[0];

        for(ll i=1; i<n; i++)
        {
            f = max(a[i], f);
            s = min(a[i], s);
        }

        if(2*k < f-s)
        {
            cout << -1 << endl;
        }
        
        else
        {
            cout << s+k << endl;    
        }
    }


    return 0;
}