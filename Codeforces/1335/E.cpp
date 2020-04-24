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

const ll L = 2e2+5;
vector <ll> v;

ll get()
{
    ll l = 0, r = sz(v) - 1;

    ll ones = accumulate(all(v), 0);
    ll zeros = 0;

    ll ma = ones;

    while(true)
    {
        zeros++;

        bool foundLeft = false, foundRight = false;

        while(l <= r)
        {
            if(v[l] == 0)
            {
                foundLeft = true;
                l++;
                break;
            }

            else
            {
                ones--;
                l++;
            }
        }

        while(l <= r)
        {
            if(v[r] == 0)
            {
                foundRight = true;
                r--;
                break;
            }

            else
            {
                ones--;
                r--;
            }
        }

        if(!foundLeft || !foundRight)
        {
            break;
        }

        ma = max(ma, zeros + ones + zeros);
    }

    return ma;

}

void solve()
{
    ll n = nxt();

    vector <ll> occ[L];

    for(ll i=0; i<n; i++)
    {
        ll a = nxt();
        occ[a].pb(i);
    }

    ll ma = 0;

    for(ll a = 1; a <= 200; a++) 
    {
        for(ll b = 1; b <= 200; b++)
        {
            if(!sz(occ[a]) || !sz(occ[b]))
            {
                continue;
            }

            if(a == b)
            {
                ma = max(ma, sz(occ[a]));
                continue;
            }

            v.clear();

            ll ff = 0, ss = 0;

            while(ff < sz(occ[a]) && ss <  sz(occ[b]))
            {
                if(occ[a][ff] < occ[b][ss])
                {
                    v.pb(0);
                    ff++;
                }

                else
                {
                    v.pb(1);
                    ss++;
                }
            }

            while(ff < sz(occ[a]))
            {
                v.pb(0);
                ff++;
            }

            while(ss < sz(occ[b]))
            {
                v.pb(1);
                ss++;
            }

            ma = max(ma, get());
            // cout << a << " " << b << " " << ma << endl;
        }
    }

    cout << ma << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}