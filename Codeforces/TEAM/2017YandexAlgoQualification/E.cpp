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

const ll L = 1e3+5;
const ll mod = 1e9+7;

ll fact[L];
ll invfact[L];

void factorial()
{
    fact[0] = 1;
    invfact[0] = 1;

    for(ll i=1; i<L; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
        invfact[i] = modexp(fact[i], mod-2, mod);
    }
}

ll C(ll n, ll r)
{
    ll res = fact[n];
    res = (res*invfact[r])%mod;
    res = (res*invfact[n-r])%mod;

    return res;
}

map <pair <ll, pll>, bool> done;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    factorial();

    ll n;
    cin >> n;

    ll temp = 0;

    for(ll i=2; i<n-1; i++)
    {
        ll c = n-1-i;

        if(c == 1 || i == 1)
        {
            continue;
        }

        if(c < i)
        {
            break;
        }

        ll cur = C(n-1, i);
        cur = (((cur*fact[i])%mod)*invfact[2])%mod;
        cur = (((cur*fact[n-1-i])%mod)*invfact[2])%mod;

        if(i == n-1-i)
        {
            cur = (cur * invfact[2])%mod;
        }

        temp = (temp+cur)%mod;
    }

    temp = (temp*n)%mod;
    // temp = (temp*invfact[2])%mod;

    ll res = 0;

    for(ll i=0; i<=n; i++)
    {
        for(ll j=i; j<=n; j++)
        {
            ll c = n-2-i-j;

            if(c < 0)
            {
                continue;
            }

            ll z = 0;

            if(i==0)
            {
                z++;
            }

            if(j==0)
            {
                z++;
            }

            if(c==0)
            {
                z++;
            }

            if(z >= 2)
            {
                continue;
            }

            vector <ll> v;
            v.pb(i);
            v.pb(j);
            v.pb(c);
            sort(all(v));

            if(done[mp(v[0], mp(v[1], v[2]))])
            {
                continue;
            }

            done[mp(v[0], mp(v[1], v[2]))] = true;

            ll cur = C(n-2, i);
            cur = (cur*C(n-2-i, j))%mod;
            cur = (cur*C(n-2-i-j, c))%mod;
            cur = (cur*fact[i])%mod;
            cur = (cur*fact[j])%mod;
            cur = (cur*fact[c])%mod;

            if(i == j && j == c)
            {
                cur = (cur * invfact[3])%mod;
            }

            else if(i == j || j == c || c == i)
            {
                cur = (cur * invfact[2])%mod;
            }

            // cout << i << " " << j << " " << c << " " << cur << endl;

            res = (res + cur)%mod;
        }
    }

    res = (res * C(n, 2))%mod;

    // cout << temp << " " << res << endl;

    cout << (temp+res)%mod << endl;

    return 0;
}