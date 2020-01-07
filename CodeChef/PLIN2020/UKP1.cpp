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

const ll L = 1e8 + 5e7;
ll f[L];

ll cal(ll x)
{
    if(x == 0)
    {
        return f[x] = 0;
    }

    if(f[x] != -1)
    {
        return f[x];
    }

    if(x & 1)
    {
        return f[x] = ((x*(x-1))/2);
    }

    else
    {
        return (f[x] = ((x/2) + cal(x/2)));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(ll i=0; i<L; i++)
    {
        f[i] = -1;
    }

    f[0] = 0;

    map <ll, ll> cnt;

    for(ll i=0; i<2000000; i++)
    {
        cal(i);
        if(f[i] == 8191)
        {
            cout << i << endl;
        }
    }

    for(ll i=1; i<1000000; i++)
    {
        if(cnt[i] > 2)
        {
            cout << i << " ** " << cnt[i] << endl;
        }
    }

    // ll y;
    // cin >> y;

    // bool fl = false;

    // for(ll i=1; i<L; i++)
    // {
    //     if(y == f[i])
    //     {
    //         fl = true;
    //         cout << i << " ";
    //     }
    // }

    // if(!fl)
    // {
    //     cout << -1;
    // }

    // cout << endl;

    return 0;
}