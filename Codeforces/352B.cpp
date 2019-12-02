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

const ll L = 1e5;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    vector <pll> p;

    map < ll, vector <ll> > m;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        m[a].pb(i+1);
    }

    vector <pll> store;

    for(ll i=1; i<=L; i++)
    {
        if(sz(m[i]) == 0)
        {
            continue;
        }

        if(sz(m[i]) == 1)
        {
            store.pb(mp(i, 0));
        }

        else
        {
            ll d = m[i][1] - m[i][0];

            bool f = true;

            for(ll j = 0; j<sz(m[i])-1; j++)
            {
                if(m[i][j] + d != m[i][j+1])
                {
                    f = false;
                    break;
                }
            }

            if(f)
            {
                store.pb(mp(i, d));
            }
        }
    }

    cout << sz(store) << endl;

    for(auto i: store)
    {
        cout << i.ff << " " << i.ss << endl;
    }

    return 0;
}