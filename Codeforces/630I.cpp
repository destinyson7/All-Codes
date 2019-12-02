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

const ll M = 80;

ll fact[M];

void factorial()
{
    fact[0] = 1;

    for(ll i=1; i<M; i++)
    {
        fact[i] = fact[i-1]*i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    ll ans = 24*(1LL<<(2*n-6));

    if(n>=4)
    {
        ans+=((n-3)*36*(1LL<<(2*n-8)));
    } 

    cout << ans << endl;



    return 0;
}