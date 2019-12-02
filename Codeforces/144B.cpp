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
    
    ll xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    ll n;
    cin >> n;

    vector < pair <pll, ll> > p;

    for(ll i=0; i<n; i++)
    {
        ll x, y, r;
        cin >> x >> y >> r;

        p.pb(mp(mp(x, y), r));
    }

    ll cnt = 0;

    for(ll i=min(xa, xb); i<=max(xa, xb); i++)
    {
        ll f = i;
        ll s = ya;

        bool flag = false;

        for(ll j=0; j<n; j++)
        {
            ll dis = (p[j].ff.ff-f)*(p[j].ff.ff-f) + (p[j].ff.ss-s)*(p[j].ff.ss-s);

            if(dis <= p[j].ss*p[j].ss)
            {
                flag = true;
                break;
            }
        }

        if(!flag)
        {
            cnt++;
        }
    }

    for(ll i=min(xa, xb); i<=max(xa, xb); i++)
    {
        ll f = i;
        ll s = yb;

        bool flag = false;

        for(ll j=0; j<n; j++)
        {
            ll dis = (p[j].ff.ff-f)*(p[j].ff.ff-f) + (p[j].ff.ss-s)*(p[j].ff.ss-s);

            if(dis <= p[j].ss*p[j].ss)
            {
                flag = true;
                break;
            }
        }

        if(!flag)
        {
            cnt++;
        }
    }

    for(ll i=min(ya, yb)+1; i<max(ya, yb); i++)
    {
        ll f = xa;
        ll s = i;

        bool flag = false;

        for(ll j=0; j<n; j++)
        {
            ll dis = (p[j].ff.ff-f)*(p[j].ff.ff-f) + (p[j].ff.ss-s)*(p[j].ff.ss-s);

            if(dis <= p[j].ss*p[j].ss)
            {
                flag = true;
                break;
            }
        }

        if(!flag)
        {
            cnt++;
        }
    }

    for(ll i=min(ya, yb)+1; i<max(ya, yb); i++)
    {
        ll f = xb;
        ll s = i;

        bool flag = false;

        for(ll j=0; j<n; j++)
        {
            ll dis = (p[j].ff.ff-f)*(p[j].ff.ff-f) + (p[j].ff.ss-s)*(p[j].ff.ss-s);

            if(dis <= p[j].ss*p[j].ss)
            {
                flag = true;
                break;
            }
        }

        if(!flag)
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}