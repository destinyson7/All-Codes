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

    vector <ll> f, s, t;

    for(ll i=1; i<=n; i++)
    {
        ll ty;
        cin >> ty;

        if(ty == 1)
        {
            f.pb(i);
        }

        else if(ty == 2)
        {
            s.pb(i);
        }

        else
        {
            t.pb(i);
        }
    }

    ll a = sz(f), b = sz(s), c = sz(t);

    cout << min(a, min(b, c)) << endl;

    for(ll i=0; ; i++)
    {
        if(i == a || i == b || i == c)
        {
            break;
        }

        cout << f[i] << " " << s[i] << " " << t[i] << endl;
    }




    return 0;
}