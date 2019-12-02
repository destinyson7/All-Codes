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

const ll L = 1e2+5;

typedef struct pt
{
    ll x, y;
} pt;

pt pts[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    for(ll i=0; i<n; i++)
    {
        cin >> pts[i].x >> pts[i].y;
    }

    float dis = 0;

    for(ll i=1; i<n; i++)
    {
        ll f = pts[i].y - pts[i-1].y;
        ll s = pts[i].x - pts[i-1].x;

        f = f*f + s*s;

        dis+=sqrtl(f);
    }

    dis*=k;

    dis/=50;

    cout << fixed << setprecision(8) << dis << endl;

    return 0;
}