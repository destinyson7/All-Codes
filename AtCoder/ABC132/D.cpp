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

ll fact[4005];

void factorial()
{
    fact[0] = 1;

    for(ll i=1; i<4005; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
}

ll modexp(ll a, ll b, ll c)
{
    a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b>>=1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    factorial();

    for(ll i=1; i<=k; i++)
    {
        if(n-k-i+1 < 0)
        {
            cout << 0 << endl;
            continue;
        }

        ll ans = fact[k-1];
        ans*=modexp(fact[i-1], mod-2, mod);
        ans%=mod;
        ans*=modexp(fact[k-i], mod-2, mod);
        ans%=mod;

        ll res = fact[n-k+1];
        res*=modexp(fact[i], mod-2, mod);
        res%=mod;
        res*=modexp(fact[n-k-i+1], mod-2, mod);
        res%=mod;

        cout << (ans*res)%mod << endl;
    }

    return 0;
}