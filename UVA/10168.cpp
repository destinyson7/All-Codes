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

const ll L = 1e7+5;

vector <bool> isPrime(L, true);
// vector <ll> primes;

void sieve()
{
    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i=2; i*i<L; i++)
    {
        if(isPrime[i])
        {
            // primes.pb(i);
            for(ll j=2*i; j<L; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void solve(ll N)
{
    if(N < 8)
    {
        cout << "Impossible." << endl;
        return;
    }

    if(N & 1)
    {
        N -= 5;

        cout << "2 3 ";
    }

    else
    {
        N-=4;
        
        cout << "2 2 ";
    }
    
    for(ll i=2; i<N; i++)
    {
        if(isPrime[i] && isPrime[N-i])
        {
            cout << i << " " << N-i << endl;
            return;
        }
    }

    cout << "Impossible." << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    sieve();

    ll N;

    while(cin >> N)
    {
        solve(N);
    }

    return 0;
}