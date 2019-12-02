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

vector <pll> p;

vector <pll> f, s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    n>>=1;  

    for(ll i=0; i<n; i++)
    {
        ll a, b;
        cin >> a >> b;

        if(a > b)
        {
            swap(a, b);
        }

        p.pb(mp(a, b));
    }    

    sort(all(p));

    for(ll i=0; i<n; i++)
    {
        if(f.empty() || f.back().ss <= p[i].ff)
        {
            f.pb(mp(p[i].ff, p[i].ss));
        }

        else if(s.empty() || s.back().ss <= p[i].ff)
        {
            s.pb(mp(p[i].ff, p[i].ss));
        }

        else
        {
            cout << -1 << endl;
            return 0;
        }
    }

    reverse(all(s));

    for(ll i=0; i<sz(f); i++)
    {
        cout << f[i].ff << " " << f[i].ss << " ";
    }

    for(ll i=0; i<sz(s); i++)
    {
        cout << s[i].ss << " " << s[i].ff << " ";
    }

    cout << endl;

    return 0;
}