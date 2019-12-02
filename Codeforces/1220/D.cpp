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

const ll L = 55+5;
const ll M = 2e5+5;

ll b[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    ll g = 0;

    vector <ll> store(L+5, 0);

    for(ll i=0; i<n; i++)
    {
        cin >> b[i];
        g = gcd(g, b[i]);
    }

    for(ll i=0; i<n; i++)
    {
        for(ll j=1; j<=L; j++)
        {
            if((b[i] % (1LL << j)) == (1LL << (j-1)))
            {
                store[j]++;
            }
        }
    }

    ll from = 0, keep = -1;

    for(ll j=1; j<=L; j++)
    {
        if(store[j] > keep)
        {
            keep = store[j];
            from = j;
        }
    }

    cout << n-keep << endl;

    for(ll i=0; i<n; i++)
    {
        if((b[i] % (1LL << from)) != (1LL << (from-1)))
        {
            cout << b[i] << " ";
        }
    }
    cout << endl;

    return 0;
}