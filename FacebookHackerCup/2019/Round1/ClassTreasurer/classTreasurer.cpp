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
    
    ll T;
    cin >> T;

    for(ll t=1; t<=T; t++)
    {
        ll N, K;
        cin >> N >> K;

        string v;
        cin >> v;

        ll ans = 0;
        ll m = -1e15;

        for(ll i=N-1; i>=0; i--)
        {
            if(K==0 && v[i]=='B')
            {
                ans = (ans+modexp(2, i+1, mod))%mod;
            }

            if(v[i] == 'B' && !m)
            {
                ans = (ans+modexp(2, i+1, mod))%mod;

                m = max(m-1, -K-1);
            }

            else if(v[i] == 'A')
            {
                m = max(m-1, -K-1);
            }

            else
            {
                m = max(m+1, -K+1);
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}