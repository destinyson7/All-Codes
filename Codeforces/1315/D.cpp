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

const ll L = 2e5+5;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    vector <ll> a, t;
    map <ll, vector <ll> > repeated;

    for(ll i=0; i<n; i++)
    {
        ll x;
        cin >> x;

        a.pb(x);
    }

    for(ll i=0; i<n; i++)
    {
        ll x;
        cin >> x;

        t.pb(x);
        repeated[a[i]].pb(t[i]);
    }

    repeated[(ll)(2e9)].pb(0);

    ll prev = -1;
    ll ans = 0;
    ll cur = 0;

    multiset <ll> ms;

    for(auto i: repeated)
    {
        if(prev != -1)
        {
            ll tot = 0;
            ll sub = 0;
            vector <ll> to_erase;
            
            for(auto rit = ms.rbegin(); rit != ms.rend(); rit++)
            {
                if((i.ff - prev) == tot)
                {
                    break;
                }

                tot++;
                to_erase.pb(*rit);
            }

            for(auto j: to_erase)
            {
                ll temp = j;
                cur -= temp;
                ans += (sub * temp);
                sub++;
                ms.erase(ms.lower_bound(j));
            }

            if(!ms.empty())
            {
                ans += (cur * (i.ff - prev));
            }
        }

        prev = i.ff;

        for(auto j: i.ss)
        {
            cur += j;
            ms.insert(j);
        }
    }

    cout << ans << endl;

    return 0;
}