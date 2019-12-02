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

ll mod = 1e9+7;

void multiply(ll a[2][2], ll b[2][2])
{
    ll x = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    ll y = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    ll z = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    ll w = a[1][0]*b[0][1] + a[1][1]*b[1][1];

    a[0][0] = x%mod;
    a[0][1] = y%mod;
    a[1][0] = z%mod;
    a[1][1] = w%mod;
}

ll multiplier[2][2] = {{1, 1}, {1, 0}};

void modexpMatrix(ll a[2][2], ll b, ll mod)
{
    if(!b || b==1)
    {
        return;
    }

    modexpMatrix(a, b/2, mod);
    multiply(a, a);

    if(b&1)
    {
        multiply(a, multiplier);
    }
}

ll fibo(ll n)
{
    ll base[2][2] = {{1, 1}, {1, 0}};

    if(n == 0)
    {
        return 0;
    }

    modexpMatrix(base, n-1, mod);

    return base[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    cout << fibo(n) << endl;

    return 0;
}