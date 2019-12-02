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

const ll L = 1e5+5;
ll store[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll a1, a2, k1, k2, n;
    // pll p[2];
    cin >> a1;
    cin >> a2;
    cin >> k1;
    cin >> k2;
    cin >> n;

    // p[0].ff = k1;
    // p[0].ss = a2;

    // p[1].ff = k2;
    // p[1].ss = a2;

    // sort(p, p+2);

    // ll m1 = 0, m2 = 0;

    // ll temp = n;
    // ll res = a1*k1 + a2*k2 - a1 - a2;
    // n-=res;

    // m1 = max(0LL, n);
    // n = temp;

    // // cout << n << endl;
    // for(ll i=0; i<a1+a2; i++)
    // {
    //     if(i < p[0].ss)
    //     {
    //         if(n < p[0].ff)
    //         {
    //             cout << m1 << " " << i << endl;
    //             return 0;
    //         }

    //         n-=p[0].ff;
    //     }

    //     else
    //     {
    //         if(n < p[1].ff)
    //         {
    //             cout << m1 << " " << i << endl;
    //             return 0;
    //         }

    //         n-=p[1].ff;
    //     }
    // }

    if(k1 > k2)
    {
        swap(k1, k2);
        swap(a1, a2);
    }

    for(ll i=0; i<a1+a2; i++)
    {
        if(i<a1)
        {
            store[i] = k1;
        }

        else
        {
            store[i] = k2;
        }
    }

    ll m1 = max(0LL, n-(a1*k1+a2*k2)+a1+a2);

    for(ll i=0; i<a2+a1; i++)
    {
        if(n < store[i])
        {
            cout << m1 << " " << i << endl;
            return 0;
        }

        n-=store[i];
    }

    cout << m1 << " " << a1+a2 << endl;


    return 0;
}