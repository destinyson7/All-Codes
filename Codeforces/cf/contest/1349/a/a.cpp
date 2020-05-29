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

ll lcm(ll a, ll b)
{
    return (a/gcd(a, b)) * b;
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

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

const ll L = 3e5+5;

set <ll> s;

void factors(ll n)
{
    map <ll, ll> cnt;
    
    ll cur = 1;
    while(n%2 == 0)
    {   
        n >>= 1;
        cur *= 2;
        cnt[cur]++;
    }

    for(ll i=3; i*i <= n; i++)
    {
        ll cur = 1;
        while(n % i == 0)
        {
            n /= i;
            cur *= i;
            cnt[cur]++;
        }
    }

    if(n > 2)
    {
        cnt[n]++;
    }
}

vector <ll> least[L];
ll f[L];
ll nx[L];
ll p[L];

void cal(ll a, ll b)
{
    f[a]++;

    if(b < nx[a])
    {
        p[a] = nx[a];
        nx[a] = b;
    }

    else if(b < p[a])
    {
        p[a] = b;
    }
}

void sieve()
{
    for(ll i=2; i<L; i++)
    {
        if(!sz(least[i]))
        {
            for(ll j=i; j<L; j+=i)
            {
                least[j].pb(i);
            }
        }
    }
}

void solve()
{
    ll n = nxt();
    basic_string <ll> a(n, 0);
    generate(all(a), nxt);

    sieve();

    for(ll i=0; i<L; i++)
    {
        p[i] = 100;
        nx[i] = 100;
    }

    // cout << sz(least[2]) << endl;

    // for(ll i=0; i<n; i++)
    // {
    //     factors(i);
    // }

    for(ll i=0; i<n; i++)
    {
        ll temp = a[i];
        for(auto j: least[a[i]])
        {
            ll factors = 0;

            while(temp % j == 0)
            {
                temp /= j;
                factors++;
            }

            cal(j, factors);
            s.insert(j);
        }
    }

    ll final = 1;

    for(auto i: s)
    {
        if(f[i] == n - 1)
        {
            final *= (ll)powl(i, nx[i]);
        }

        else if(f[i] == n)
        {
            final *= (ll)powl(i, p[i]);
        }
    }

    cout << final << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    // T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}