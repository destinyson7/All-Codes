#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) 
{
    os << "{ ";
    for(auto& y : x) 
    {
        os << y << " ";
    }
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) 
{
    return os << "[" << p.ff << ", " << p.ss << "]";
}

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

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
        b >>= 1;
    }

    return ans;
}

ll modmul(ll a, ll b, ll c)
{   
    a%=c;

    ll ans = 0;

    while(b)
    {
        if(b&1)
        {
            ans = (ans+a)%c;
        }

        a = (a+a)%c;
        b >>= 1;
    }

    return ans;
}

const ll L = 1e5+5;
const ll mod = 1e9+7;

// vector <bool> isPrime

vector <ll> primes;

void primeFactors(ll n)
{
    if(n%2 == 0)
    {
        primes.pb(2);

        while(n%2 == 0)
        {
            n/=2;
        }
    }

    for(ll i=3; i*i <= n; i+=2)
    {
        if(n%i == 0)
        {
            primes.pb(i);

            while(n%i == 0)
            {
                n/=i;
            }
        }
    }

    if(n > 2)
    {
        primes.pb(n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll x, n;
    cin >> x >> n;

    primeFactors(x);

    ll len = sz(primes);

    ll ans = 1;

    for(ll i=0; i<len; i++)
    {
        ll temp = primes[i];

        ll cur = temp;

        while(cur <= n)
        {
            ll times = n/cur;

            ans*=modexp(temp, times, mod);
            ans%=mod;
            // ans = modmul(ans, modexp(temp, times, mod), mod);

            if(n/cur >= temp)
            {
                cur*=temp;
            }

            else
            {
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}