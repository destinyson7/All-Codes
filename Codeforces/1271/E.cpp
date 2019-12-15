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

// map <ll, ll> done;

ll n;

ll dp(ll x)
{
    if(x > n)
    {
        return 0;
    }

    // if(done.find(x) != done.end())
    // {
    //     return done[x];
    // }

    // cout << "**" << endl;

    ll res = 1;

    if(x & 1)
    {
        res += dp(x*2);
    }

    else
    {
        res += dp(x+1);
        res += dp(x*2);
    }

    // done[x] = res;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll k;
    cin >> n >> k;

    ll low = 1, high = n;
    // ll ans = 0;

    while(low <= high)
    {
        ll mid = low + (high-low)/2;

        // cout << mid << " * " << endl;

        ll check = dp(mid);

        if(check >= k)
        {
            // ans = mid;
            low = mid+1;
        }

        else
        {
            if(mid & 1)
            {
                check = dp(mid+1);

                if(check >= k)
                {
                    // ans = mid+1;
                    low = mid+2;
                }

                else
                {
                    high = mid-1;
                }
            }

            else
            {
                high = mid-1;
            }
        }
    }

    cout << low-1 << endl;

    return 0;
}