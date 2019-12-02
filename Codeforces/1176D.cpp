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

const ll L = 2750135;
const ll M = 4e5+5;

vector <bool> isPrime(L, true);
vector <ll> primes;
// ll greatestDiv[L];
vector <ll> b(M);
vector <ll> a;
ll cnt[L];

vector <bool> done(M);


void sieve()
{
    primes.pb(-1);
    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i=2; i<L; i++)
    {
        if(isPrime[i])
        {
            primes.pb(i);
            for(ll j=2*i; j<L; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }

    // cout << isPrime[2750131] << endl;  
}

ll findGreatestDiv(ll num)
{
    for(ll i=2; i*i<=num; i++)
    {
        if(num%i==0)
        {
            return num/i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    sieve();
    // cout << "here" << endl;

    // for(ll i=0; i<10; i++)
    // {
    //     cout << primes[i] << endl;
    // }

    ll n;
    cin >> n;

    for(ll i=0; i<2*n; i++)
    {
        cin >> b[i];
    }

    // cout << lower_bound(all(primes), 5) - primes.begin() << endl;

    sort(b.begin(), b.begin()+2*n);
    // reverse(b, b+2*n);

    for(ll i=2*n-1; i>=0; i--)
    {
        // cout << b[i] << " " << done[i] << " " << i << endl;
        if(!done[i])
        {
            if(isPrime[b[i]])
            {
                done[i] = true;

                // a.pb(i);

                ll p = lower_bound(all(primes), b[i]) - primes.begin();

                ll ind = lower_bound(b.begin(), b.begin()+2*n, p) - b.begin();

                // cout << i << " " << b[i] << " if " << p << " " << ind << endl;

                done[ind + cnt[p]] = true;
                cnt[p]++;
                a.pb(p);
            }

            else
            {
                done[i] = true;

                a.pb(b[i]);

                ll p = findGreatestDiv(b[i]);

                ll ind = lower_bound(b.begin(), b.begin()+2*n, p) - b.begin();

                // cout << i << " " << b[i] << " else " << p << " " << ind << endl;

                done[ind + cnt[p]] = true;
                cnt[p]++;
                // a.pb(p);
            }
        }
    }

    // cout << endl;

    for(ll i=0; i<sz(a); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}