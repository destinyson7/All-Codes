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

const ll L = 1e6+5;
const ll mod = 1LL << 30;

ll divisors[L];

void fun()
{
    for(ll i=1; i<L; i++)
    {
        for(ll j=i; j<L; j+=i)
        {
            divisors[j]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll a, b, c;
    cin >> a >> b >> c;

    fun();

    ll sum = 0;

    for(ll i=1; i<=a; i++)
    {
        for(ll j=1; j<=b; j++)
        {
            for(ll k=1; k<=c; k++)
            {
                ll num = i*j*k;

                sum = (sum+divisors[num])%mod;
            }
        }
    }

    cout << sum << endl;

    return 0;
}