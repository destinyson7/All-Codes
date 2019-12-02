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

vector <pll> p;
ll cnt[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;  

    ll first = 0;
    ll second = 0;

    for(ll i=0; i<m; i++)
    {
        ll a, b;
        cin >> a >> b;

        p.pb(mp(a, b));
    }

    ll f1 = 0, f2 = 0, f3 = 0, f4 = 0;

    f1 = p[0].ff;
    f2 = p[0].ss;
    f3 = -1, f4 = -1;

    for(ll i=1; i<m; i++)
    {
        if(p[i].ff == f1 || p[i].ss == f1 || p[i].ff == f2 || p[i].ss == f2)
        {
            continue;
        }

        f3 = p[i].ff;
        f4 = p[i].ss;
        break;
    }

    if(f3 == -1)
    {
        cout << "YES" << endl;
        return 0;
    }

    ll f5 = f1;
    ll f6 = f3;
    ll F = 1;

    for(ll i=0; i<m; i++)
    {
        if(p[i].ff == f5 || p[i].ss == f5 || p[i].ff == f6 || p[i].ss == f6)
        {
            continue;
        }

        F = 0;
        break;
    }

    if(F)
    {
        cout << "YES" << endl;
        return 0;
    }

    ll f7 = f1;
    ll f8 = f4;
    ll F2 = 1;

    for(ll i=0; i<m; i++)
    {
        if(p[i].ff == f7 || p[i].ss == f7 || p[i].ff == f8 || p[i].ss == f8)
        {
            continue;
        }

        F2 = 0;
        break;
    }

    if(F2)
    {
        cout << "YES" << endl;
        return 0;
    }

    ll f9 = f2;
    ll f10 = f4;
    ll F3 = 1;

    for(ll i=0; i<m; i++)
    {
        if(p[i].ff == f9 || p[i].ss == f9 || p[i].ff == f10 || p[i].ss == f10)
        {
            continue;
        }

        F3 = 0;
        break;
    }

    if(F3)
    {
        cout << "YES" << endl;
        return 0;
    }

    ll f11 = f2;
    ll f12 = f3;
    ll F4 = 1;

    for(ll i=0; i<m; i++)
    {
        if(p[i].ff == f11 || p[i].ss == f11 || p[i].ff == f12 || p[i].ss == f12)
        {
            continue;
        }

        F4 = 0;
        break;
    }

    if(F4)
    {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}