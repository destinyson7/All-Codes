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

bool on[L];
vector <ll> factors[L];
ll check[L];
vector <ll> of[L];
vector <bool> isPrime(L, true);

void sieve(ll n)
{
    isPrime[0] = false;
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

void getFactors(ll n)
{
    sieve(n);

    for(ll i=2; i<=n; i++)
    {
        for(ll j=2; j*j<=i; j++)
        {
            if(i%j==0)
            {
                if(isPrime[j])
                {
                    factors[i].pb(j);
                    // of[j].pb(i);

                }
             
                if(j != i/j && isPrime[i/j])
                {
                    factors[i].pb(i/j);
                    // of[i/j].pb(i);
                }
            }
        }

        if(isPrime[i])
        {
            factors[i].pb(i);
            // of[i].pb(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    getFactors(n);

    while(m--)
    {
        char type;
        ll id;

        cin >> type >> id;

        if(type == '+')
        {
            if(on[id])
            {
                cout << "Already on" << endl;
            }

            else
            {
                bool f = false;
                ll conflict = -1;

                // cout << "id " << id << " size" << sz(factors[id]) << endl;
                for(auto i: factors[id])
                {
                    // cout << id << " " << i << endl;

                    if(check[i])
                    {
                        // cout << i << " checked" << endl;
                        conflict = check[i];

                        f=true;
                        break;
                    }
                }

                if(f)
                {
                    cout << "Conflict with " << conflict << endl;
                }

                else
                {
                    on[id] = true;
                    cout << "Success" << endl;

                    for(auto i: factors[id])
                    {
                        // cout << id << " " << i << endl;
                        check[i] = id;;
                    }
                }
            }
        }

        else
        {
            if(!on[id])
            {
                cout << "Already off" << endl;
            }

            else
            {
                on[id] = false;
                cout << "Success" << endl;

                for(auto i: factors[id])
                {
                    check[i] = false;
                }
            }
        }
    }

    return 0;
}