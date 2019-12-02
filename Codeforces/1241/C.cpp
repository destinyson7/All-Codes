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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll q;
    cin >> q;

    while(q--)
    {
        ll n;
        cin >> n;

        vector <ll> p(n+1, 0);

        for(ll i=1; i<=n; i++)
        {
            ll t;
            cin >> t;
            p[i] = t/100;
        }

        ll x, a;
        cin >> x >> a;

        ll y, b;
        cin >> y >> b;

        ll k;
        cin >> k;

        sort(all(p));

        vector <ll> pref(n+1, 0);

        for(ll i=1; i<=n; i++)
        {
            pref[i] = pref[i-1] + p[i];
        }

        ll lcm = (a*b)/gcd(a, b);
        ll low = 1, high = n;

        ll res = 1e15;

        while(low <= high)
        {
            ll mid = low + (high-low)/2;

            ll req = x*(pref[n - (mid/lcm)] - pref[n - (mid/a)]) + y*(pref[n - (mid/a)] - pref[n - (mid/a) - (mid/b) + (mid/lcm)]);
            req = max(req, y*(pref[n-(mid/lcm)] - pref[n - mid/b]) + x*(pref[n - mid/b] - pref[n - mid/a - mid/b + (mid/lcm)]));
            
            req += ((pref[n] - pref[n - (mid/lcm)])*(x + y));

            if(req >= k)
            {
                high = mid-1;
                res = min(mid, res);
            }

            else
            {
                low = mid + 1;
            }
        }

        if(res != 1e15)
        {
            cout << res << endl;
        }

        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}