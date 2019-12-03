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

ll lcm(ll a, ll b)
{
    return ((a*b)/gcd(a, b));
}

const ll L = 1e5+5;

void solve(ll N, ll M)
{
    vector <ll> a;

    for(ll i=0; i<M; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }

    ll total_subsets = (1LL << M);

    ll ans = 0;

    for(ll i=0; i<total_subsets; i++)
    {
        ll currently_included = 0;
        ll l = 1;

        for(ll j=0; j<M; j++)
        {
            if(i & (1LL << j))
            {
                currently_included++;

                l = lcm(l, a[j]);
            }
        }

        if(currently_included & 1)
        {
            ans -= (N/l);
        }

        else
        {
            ans += (N/l);
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, M;
    
    while(cin >> N >> M)
    {
        solve(N, M);
    }

    return 0;
}