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

const ll L = 5e3+5;

ll fact[L];
ll permute[L][L];

ll mod = 998244353;

ll modmul(ll a, ll b, ll c)
{
    ll ans = 0;

    a%=c;

    while(b)
    {
        if(b&1)
        {
            ans = (ans+a)%c;
        }

        b>>=1;
        a = (a+a)%c;
    }

    return ans;
}

ll C(ll n, ll r, ll mod)
{    
    if(n==r)
    {
        return 1;
    }
    
    else if(n<r)
    {
        return 0;
    }

    if(r==1)
    {
        return permute[n][1];
    }

    if(permute[n][r]!=(-1))
    {
        return permute[n][r];
    }

    permute[n][r] = (C(n-1, r-1, mod) + C(n-1, r, mod))%mod;
    return permute[n][r];
}

void factorial()
{
    fact[0] = 1;
    for(ll i=1; i<L; i++)
    {
        fact[i] = modmul(fact[i-1], i, mod);
    }
}

ll calc(ll m, ll n)
{
    ll t = min(n, m);

    ll ans = 0;

    for(ll i=0; i<=t; i++)
    {
        ans += modmul(C(n, i, mod), modmul(C(m, i, mod), fact[i], mod), mod);  
        ans%=mod;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;   

    factorial(); 

    for(ll i=0; i<L; i++)
    {
        for(ll j=0; j<L; j++)
        {
            permute[i][j]=-1;
        }
    }

    for(ll d=0; d<L; d++)
    {
        permute[d][0]=1;
        permute[d][1]=d;
    }

    ll ans = calc(a, b);
    // cout << ans << endl;
    ans = modmul(ans, calc(a, c), mod);
    // cout << ans << endl;
    ans = modmul(ans, calc(b, c), mod);

    cout << ans << endl;

    return 0;
}