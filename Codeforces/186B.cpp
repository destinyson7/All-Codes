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

bool cmp(pll a, pll b)
{
    if(a.ff == b.ff)
    {
        return a.ss < b.ss;
    }

    return a.ff > b.ff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, t1, t2, k;
    cin >> n >> t1 >> t2 >> k;

    vector <pll> h;

    for(ll i=0; i<n; i++)
    {
        ll a, b;
        cin >> a >> b;

        ll f = 0, s = 0;

        f = (100 - k)*a*t1 + 100*b*t2;
        s = (100 - k)*b*t1 + 100*a*t2;
        
        if(f > s)
        {
            h.pb(mp(f, i+1));
        }

        else
        {
            h.pb(mp(s, i+1));
        }
    }

    sort(all(h), cmp);

    for(ll i=0; i<n; i++)
    {
        cout << h[i].ss << " ";
        cout << fixed << setprecision(2) << 0.01*h[i].ff << endl;
    }

    return 0;
}