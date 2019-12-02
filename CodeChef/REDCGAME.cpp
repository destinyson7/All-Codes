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

const ll L = 50+5;

ll a[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        for(ll i=0; i<L; i++)
        {
            a[i] = 0;
        }

        ll n, k;
        cin >> n >> k;

        vector <ll> v;

        ll ans = 0;
        
        for(ll i=0; i<n; i++)
        {
            cin >> a[i];

            if(a[i] > k)
            {
                v.pb(a[i]-k);

                ans += k;
            }

            else
            {
                ans += a[i];
            }
        }

        sort(all(v));

        ll len = sz(v);

        if(len == 0)
        {
            cout << ans << endl;
            continue;
        }

        if(len == 1)
        {
            cout << ans + v[0] << endl;
            continue;
        }

        else
        {
            ll sum = 0;
            for(ll i=0; i<len-2; i++)
            {
                sum += v[i];
            }

            if(sum < v[len-2])
            {
                cout << ans + v[len-1] - v[len-2] + sum << endl;
                continue;
            }

            else
            {
                if((sum - v[len-2]) & 1)
                {
                    ans--;
                }

                cout << ans + v[len-1] << endl;
                continue;
            }
        }
    }

    return 0;
}