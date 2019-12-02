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

const ll L1 = 1e5+5;
const ll mod = 1e9+7;
const ll L2 = 2e5+5;

ll modexp(ll a, ll b, ll c)
{
    ll ans = 1;
    
    a%=mod;

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

ll store[L2];

ll testCase()
{
    ll N, M, K;
    cin >> N >> M >> K;

    ll ans = 0;
    ll cur = 0;
    ll res = 0;
    ll first = 1;
    ll second = 1;

    for(ll i=1; i<=min(K, N+M+2); i++)
    {
        cur++;
        assert(cur < L2);
        
        ll temp1 = (modexp(i, N, mod) - modexp(i-1, N, mod) + mod)%mod;
        ll temp2 = (modexp(i, M, mod) - modexp(i-1, M, mod) + mod)%mod;
        
        ans += ((temp1*temp2)%mod);
        ans%=mod;
     
        store[cur] = ans;
    }
    
    if(N+M+2 >= K)
    {
        // assert(false);
        return ans;
    }

    // assert(false);

    for(ll i=1; i<=cur; i++)   
    {
        first = (first*(K-i))%mod;

        // cout << i << " " << first << endl;
    }

    for(ll i=1; i<cur; i++)
    {
        ll temp = modexp(mod-i, mod-2, mod);

        // cout << i << " " << temp << endl;

        second = (second*temp)%mod;
    }

    ll mult = 1;

    for(ll i=1; i<=cur; i++)
    {
        mult = modexp(K-i, mod-2, mod);
        
        mult = (mult*store[i])%mod;
        mult = (mult*second)%mod;
        mult = (mult*first)%mod;

        mult = (mult+mod)%mod;

        // cout << i << " " << mult << endl;

        res+=mult;
        res%=mod;

        ll temp = modexp(i, mod-2, mod);
        second = (second*temp)%mod;
        second = (second*(i-cur))%mod;
    }

    return res;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        cout << testCase() << endl;
    }

    return 0;
}