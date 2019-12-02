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
    
    ll n, x, y;
    cin >> n >> x >> y;

    vector <ll> p;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        p.pb(t);
    }


   for(ll i=0; i<n; i++)
   {
        bool f = true;

        for(ll j=i-1; j>=0 && j>=i-x; j--)
        {
            if(p[j] <= p[i])
            {
                f = false;
                break;
            }
        }

        // cout << i+1 << " " << (f==true) << endl;

        for(ll j=i+1; j<=i+y && j<n; j++)
        {
            if(p[j] <= p[i])
            {
                f = false;
                break;
            }
        }

        if(f)
        {
            cout << i+1 << endl;
            return 0;
        }
   }

   // cout << x << endl;

    return 0;
}