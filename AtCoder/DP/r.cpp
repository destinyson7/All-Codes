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

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

const ll L = 50+5;
const ll mod = 1e9 + 7;

typedef struct Matrix {
    ll mat[L][L];
} matrix;

matrix multiply(matrix A, matrix B, ll mod)
{
    Matrix ans;

    for(ll i=0; i<L; i++)
    {
        for(ll j=0; j<L; j++)
        {
            ans.mat[i][j] = 0;

            for(ll k=0; k<L; k++)
            {
                ans.mat[i][j] += ((A.mat[i][k] * B.mat[k][j])%mod);
                ans.mat[i][j] %= mod;
            }
        }
    }

    return ans;
}

matrix identity()
{
    matrix ans;

    for(ll i=0; i<L; i++)
    {
        for(ll j=0; j<L; j++)
        {
            ans.mat[i][j] = 0;

            if(i == j)
            {
                ans.mat[i][j]++;
            }
        }
    }

    return ans;
}

matrix modexp(matrix A, ll b, ll mod)
{
    matrix ans = identity();

    while(b)
    {
        if(b & 1)
        {
            ans = multiply(ans, A, mod);
        }

        A = multiply(A, A, mod);
        b >>= 1;
    }

    return ans;
}

void solve()
{
    ll n = nxt(), k = nxt();

    matrix a;

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            cin >> a.mat[i][j];
        }
    }

    matrix ans = modexp(a, k, mod);

    ll total = 0;

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            total += ans.mat[i][j];
            total %= mod;
        }
    }

    cout << total << endl;
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