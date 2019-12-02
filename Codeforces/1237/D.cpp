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
ll noOOfTracks[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    vector <ll> a;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }

    ll minn = 1e15;
    ll maxx = 0;
    for(ll i=0; i<n; i++)
    {
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }

    double half = (double)maxx/(double)2.0;

    if(half <= (double)minn)
    {
        for(ll i=0; i<n; i++)
        {
            cout << -1 << " ";
        }
        cout << endl;

        return 0;
    }

    ll where = 0;
    for(ll i=0; i<n; i++)
    {
        if(a[i] > a[where])
        {
            where = i;
        }
    }

    ll cur = 0;

    // cout << where << endl;
    for(ll i=where; ; i++)
    {
        if(cur == n)
        {
            break;
        }

        if(2*a[(i+1)%n] <= a[where])
        {
            noOOfTracks[where] = cur+1;

            // cout << where << " " << cur+1 << endl;
            break;
        }

        cur++;
    }

    ll cur2 = 1;

    for(ll i=where-1; ; i--)
    {
        if(cur2 == n)
        {
            break;
        }

        if(a[(i%n+n)%n] >= 2*a[((i+1)%n+n)%n])
        {
            noOOfTracks[(i%n+n)%n] = 1;
        }

        else
        {
            noOOfTracks[(i%n+n)%n] = 1 + noOOfTracks[((i+1)%n+n)%n];
        }

        cur2++;
    }

    for(ll i=0; i<n; i++)
    {
        cout << noOOfTracks[i] << " ";
    }
    cout << endl;

    return 0;
}