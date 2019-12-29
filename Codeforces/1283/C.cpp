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
ll f[L];
bool got[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    vector <ll> x;

    for(ll i=1; i<=n; i++)
    {
        cin >> f[i];

        if(f[i])
        {
            got[f[i]] = true;
        }

        else
        {
            x.pb(i);
        }
    }

    sort(all(x));

    vector <ll> didnt;

    for(ll i=1; i<=n; i++)
    {
        if(!got[i])
        {
            didnt.pb(i);
        }
    }

    ll len = x.size(); 

    ll temp = x.back();
    // x.pop_back();
    x.insert(x.begin(), temp);

    temp = didnt.back();
    // didnt.pop_back();
    didnt.insert(didnt.begin(), temp);

    for(ll i=0; i<len; i++)
    {
        if(x[i] == didnt[i])
        {
            swap(x[i], x[i+1]);
        }
    }

    for(ll i=0; i<len-1; i++)
    {
        f[x[i]] = didnt[i];
    }


    for(ll i=1; i<=n; i++)
    {
        // assert(f[i] != i && f[i] > 0);
        cout << f[i] << " ";
    }
    cout << endl;

    return 0;
}