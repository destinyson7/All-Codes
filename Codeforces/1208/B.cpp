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

    ll n;
    cin >> n;

    vector <pll> p;
    vector <ll> a;

    for(ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);

        p.pb(mp(t, i));
    }

    sort(all(p));

    a[p[0].ss] = 0;
    ll cur = 0;

    for(ll i=1; i<n; i++)
    {
        if(p[i].ff == p[i-1].ff)
        {
            a[p[i].ss] = cur;
        }

        else
        {
            a[p[i].ss] = ++cur;
        }
    }

    vector <ll> posi(L, 0);

    ll st = -1, en = -1;

    for(ll i = 0; i < n; i++)
    {
        if(posi[a[i]] == 1)
        {
            st = i;
            break;
        }

        posi[a[i]] = 1;
    }

    if(st == -1)
    {
        cout << 0 << endl;
        // break;
        return 0;
    }

    for(ll i = n-1; i>=st; i--)
    {
        if(posi[a[i]] == 1)
        {
            en = i;
            break;
        }

        posi[a[i]] = 1;
    }

    vector <ll> next(L, 0);

    ll st2 = -1, en2 = -1;

    for(ll i = n-1; i>=0; i--)
    {
        if(next[a[i]] == 1)
        {
            en2 = i;
            break;
        }

        next[a[i]] = 1;
    }

    if(en2 == -1)
    {
        cout << 0 << endl;
        return 0;
    }

    for(ll i = 0; i<=en2; i++)
    {
        if(next[a[i]] == 1)
        {
            st2 = i;
            break;
        }

        next[a[i]] = 1;
    }

    cout << min(en-st+1, en2-st2+1) << endl;


    return 0;
}