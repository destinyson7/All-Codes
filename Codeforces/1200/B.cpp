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

const ll L = 1e5+5;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;

        vector <ll> h;

        for(ll i=0; i<n; i++)
        {
            ll a;
            cin >> a;

            h.pb(a);
        }

        ll cur = m;

        bool f = true;

        for(ll i=0; i<n-1; i++)
        {
            if(h[i] >= h[i+1])
            {
                if(h[i+1] >= k)
                {
                    cur+=(h[i]-h[i+1]+k);
                }

                else
                {
                    cur+=h[i];
                }
            }

            else
            {
                if(h[i+1] - h[i] <= k)
                {
                    if(h[i+1] >= k)
                    {
                        cur+=(h[i] - h[i+1] + k);
                    }

                    else
                    {
                        cur+=h[i];
                    }
                }

                else if(h[i+1] - h[i] - k > cur)
                {
                    // cout << "i " << i << " " << cur << endl;
                    f = false;
                    break;
                }

                else
                {
                    cur-=(h[i+1] - h[i] - k);
                    // h[i+1]-=(h[i+1] - h[i] - k);
                }
            }

            // cout << i << " " << cur << endl;
        }

        if(f)
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}