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

    vector < set <pll> > v1(L), v2(L);

    map <pll, ll> m;

    ll N;
    cin >> N;

    ll cur = 0;

    for(ll i=0; i<N; i++)
    {
        ll x, y, v;
        cin >> x >> y >> v;

        if(!v1[x].empty() && !v2[y].empty())
        {
            ll temp = 0;

            auto it1 = v1[x].upper_bound(mp(y, v));
            auto it2 = v1[x].lower_bound(mp(y, v));
            auto it3 = v2[y].upper_bound(mp(x, v));
            auto it4 = v2[y].lower_bound(mp(x, v));
            
        }

        else if(!v1[x].empty())
        {

        }

        else if(!v2[y].empty())
        {

        }
        
        cout << cur << endl;
        v1[x].insert(mp(y, v));
        v1[y].insert(mp(x, v));
    }

    return 0;
}