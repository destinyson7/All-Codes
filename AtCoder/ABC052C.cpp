#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

vector <ll> prime(L);
vector <ll> factors(L);

void sieve()
{
    prime[1] = 1;

    for(ll i=2; i<L; i++)
    {
        if(prime[i]==0)
        {
            // prime[i] = 1;
            for(ll j=2*i; j<L; j+=i)
            {
                prime[j] = 1;
            }
        }
    }
}

ll modmul(ll a, ll b, ll c)
{
    ll ans = 0;
    a%=c;

    while(b)
    {
        if(b&1)
        {
            ans = (a+ans)%c;
        }

        a = (a+a)%c;
        b>>=1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    sieve();

    ll mod = 1e9+7;

    ll N;
    cin >> N;

    ll ans = 1;
    for(ll i=2; i<=N; i++)
    {
        ll temp = i;
        
        for(ll j=2; j<=i; j++)
        {
            while(temp%j==0)
            {
                factors[j]++;
                temp/=j;
            }
        }
    }

    for(ll i=2; i<=N; i++)
    {
        ans = modmul(ans, factors[i]+1, mod);
    }

    cout << ans << endl;

    return 0;
}