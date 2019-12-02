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

const ll L = 1e3+5;

vector <bool> isPrime(L, true);
vector <ll> store;

void sieve()
{
    isPrime[1] = false;

    for(ll i=2; i<L; i++)
    {
        if(isPrime[i])
        {
            store.pb(i);
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
 
    ll n, k;
    cin >> n >> k;

    ll cnt = 0;

    sieve();

    for(ll i=2; i<=n; i++)
    {
        if(isPrime[i])
        {
            ll t = i-1;
            for(ll j=0; j<sz(store)-1; j++)
            {
                if(store[j] + store[j+1] > t)
                {
                    break;
                }

                else if(store[j] + store[j+1] == t)
                {
                    cnt++;
                    break;
                }
            }            
        }

        if(cnt>=k)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;

    return 0;
}