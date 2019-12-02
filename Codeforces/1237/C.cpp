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

const ll L = 5e4+5;

vector <pair<pll, pll>> pts, nextt, againn;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    for(ll i=1; i<=n; i++)
    {
        pair <pll, pll> p;
        p.ss.ss = i;
        cin >> p.ff.ff >> p.ff.ss >> p.ss.ff;
        pts.pb(p);
    }

    sort(all(pts));

    for(ll i=0; i<n; i++)
    {
        if(i == n-1)
        {
            nextt.pb(pts[i]);
            break;
        }

        if(pts[i].ff.ff == pts[i+1].ff.ff && (pts[i].ss.ff == pts[i+1].ss.ff || pts[i].ff.ss == pts[i+1].ff.ss))
        {
            cout << pts[i].ss.ss << " " << pts[i+1].ss.ss << endl;
            i++;
        }

        else
        {
            nextt.pb(pts[i]);
        }
    }

    ll len = sz(nextt);

    for(ll i=0; i<len; i++)
    {
        if(i == len-1)
        {
            againn.pb(nextt[i]);
            break;
        }

        if(nextt[i].ff.ff == nextt[i+1].ff.ff)
        {
            cout << nextt[i].ss.ss << " " << nextt[i+1].ss.ss << endl;
            i++;
        }

        else
        {
            againn.pb(nextt[i]);
        }
    }
    
    ll len2 = sz(againn)-1;

    for(ll i=0; i<len2; i++)
    {
        cout << againn[i].ss.ss << " " << againn[i+1].ss.ss << endl;
        i++;
    }

    return 0;
}