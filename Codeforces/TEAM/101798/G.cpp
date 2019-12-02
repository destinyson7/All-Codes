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

    vector <ll> v;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        v.pb(a);
    }

    if(n == 2)
    {
        cout << abs(v[0] - v[1]) << endl;
        return 0;
    }

    sort(all(v));

    vector <ll> ans(n, 0);

    // bool f = false;

    // ll s = 0, e = n-1;

    // deque <ll> q;

    // for(ll i=0; i<n; i++)
    // {
    //     q.pb(v[i]);
    // }

    // for(ll i=0; i<n; i+=4)
    // {
    //     if(!f)
    //     {
    //         ans[s] = q.front();
    //         q.pop_front();
            
    //         ans[s+1] = q.back();
    //         q.pop_back();

    //         ans[e] = q.back();
    //         q.pop_back();

    //         ans[e-1] = q.front();
    //         q.pop_front();

    //         s+=2;
    //         e-=2;
    //     }


    //     else
    //     {
    //         ans[e] = q.back();
    //         q.pop_back();

    //         ans[e-1] = q.front();
    //         q.pop_front();

    //         ans[s] = q.front();
    //         q.pop_front();
            
    //         ans[s+1] = q.back();
    //         q.pop_back();

    //         s+=2;
    //         e-=2;
    //     }

    //     f^=1;
    // }

    // cout << ans << endl;

    // ll goals = 0;

    // vector <ll> a;
    // while(n > 1)
    // {
    //     a = ans;
    //     ans.clear();
    //     for(ll i=0; i<n; i+=2)
    //     {
    //         goals += abs(a[i] - a[i+1]);

    //         // cout << goals << endl;

    //         ans.pb(max(a[i], a[i+1]));
    //     }

    //     n/=2;
    // }

    // ll goals = 0;

    // ll h = 1;

    // vector <ll> x(n, 0);

    // for(ll i=n-2; i>=0; i--)
    // {
    //     for(; i>)
    // }

    // // ll x = 0;

    // for(ll i = 0; i < n-1; i++)
    // {
    //     // goals += abs(v[n-1-i+x] - v[i]);
    // }

    ll goals = 0;

    vector <ll> a;

    while(n > 1)
    {
        a = v;

        sort(all(a));

        v.clear();

        for(ll i=0; i<n/2; i++)
        {
            goals += (a[n-1-i] - a[i]);
            v.pb(a[n-1-i]);
        }

        // cout << v << endl;

        n/=2;
    }

    cout << goals << endl;


    return 0;
}