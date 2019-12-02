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
    
    ll n, m, k;
    cin >> n;

    vector <ll> x, y, z;

    ll f = 0, s = 0, t = 1e17;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        x.pb(a);

        f = max(f, a);
    }

    cin >> m;

    for(ll i=0; i<m; i++)
    {
        ll a;
        cin >> a;

        y.pb(a);

        s = max(s, a);
    }

    cin >> k;

    for(ll i=0; i<k; i++)
    {
        ll a;
        cin >> a;

        z.pb(a);
        
        t = min(t, a);
    }

    ll A, B;
    cin >> A >> B;

    double num = A*t;
    double den = B*s;

    double div = (double)num/den;

    div++;

    div = 1/div;

    div*=(f*f);

    div = sqrt(div);

    cout << fixed << setprecision(8) << div << endl; 

    return 0;
}