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

const ll L = 1e6+5;

vector <bool> isPrime(L, true);

void sieve()
{
    isPrime[1] = false;

    for(ll i=2; i<L; i++)
    {
        if(isPrime[i])
        {
            for(ll j=2*i; j<L; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    sieve();

    ll n;
    cin >> n;

    while(n--)
    {
        ll a;
        cin >> a;

        double b = sqrt(a);
        double c = (ll)b;
        ll d = (ll)c;

        if(b==c && isPrime[d])
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}