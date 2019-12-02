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

    a%=c;

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

        ll d = 0;

        ll ans = 0;

        for(ll i=N-1; i>=0; i--)
        {
            if(v[i] == 'A')
            {
                d = max(0LL, d-1);
            }

            else if(v[i] == 'B')
            {
                if(d<K)
                {
                    d++;
                }

                else
                {
                    ans = (ans+modexp(2, i+1, mod))%mod;
                    
                    d = max(0LL, d-1);
                }
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }


    return 0;
}