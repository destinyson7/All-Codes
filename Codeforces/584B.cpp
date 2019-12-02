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
const ll mod = 1e9+7;

ll modexp(ll a, ll b, ll c)
{
    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%mod;
        }

        a = (a*a)%mod;
        b>>=1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    ll ans = modexp(3, 3*n, mod);

    ll sub = modexp(7, n, mod);

    ans = (ans-sub+mod)%mod;

    cout << ans << endl;

    return 0;
}