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

const ll L = 1e3+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll p, q, l, r;
    cin >> p >> q >> l >> r;

    vector <ll> f(L, 0);
    vector <ll> s(L, 0);

    for(ll i=0; i<p; i++)
    {
        ll a, b;
        cin >> a >> b;

        for(ll j=a; j<=b; j++)
        {
            f[j] = 1;
        }
    }

    for(ll i=0; i<q; i++)
    {
        ll c, d;
        cin >> c >> d;

        for(ll j=c; j<=d; j++)
        {
            s[j] = 1;
        }
    }

    ll cnt = 0;

    for(ll i=l; i<=r; i++)
    {
        for(ll j=i; j<L; j++)
        {
            if(f[j] && s[j-i])
            {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}