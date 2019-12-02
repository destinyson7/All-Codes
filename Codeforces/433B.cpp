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
 
    ll n;
    cin >> n;

    vector <ll> v, u;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        v.pb(a);
        u.pb(a);
    }   

    sort(all(u));

    for(ll i=1; i<n; i++)
    {
        v[i]+=v[i-1];
        u[i]+=u[i-1];
    }

    ll m;
    cin >> m;

    while(m--)
    {
        ll type, l, r;
        cin >> type >> l >> r;

        if(type == 1)
        {
            ll ans = v[r-1];

            if(l!=1)
            {
                ans-=v[l-2];
            }

            cout << ans << endl;
        }

        else
        {
            ll ans = u[r-1];

            if(l!=1)
            {
                ans-=u[l-2];
            }

            cout << ans << endl;
        }
    }


    return 0;
}