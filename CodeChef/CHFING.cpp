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
const ll mod = 1e9+7;

ll modmul(ll a, ll b, ll c)
{
    ll ans = 0;

    a%=mod;

    while(b)
    {
        if(b&1)
        {
            ans = (ans+a)%c;
        }

        a = (a+a)%mod;
        b>>=1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll T;
    cin >> T;

    while(T--)
    {
        ull N, K;
        cin >> N >> K;

        N--;
        K--;

        ull cur = K/N + ((K%N) ? 1:0);

        ull ans = modmul(cur, K%mod, mod);
        
        ull sub = ((cur&1) ? modmul((cur-1)/2, cur%mod, mod):modmul(cur/2, (cur-1)%mod, mod));
        
        sub = modmul(sub, N%mod, mod);

        ans+=mod;
        ans-=sub;
        ans%=mod;

        cout << ans << endl;
    }


    return 0;
}