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

void solve()
{
    ll n;
    cin >> n;

    vector <ll> q;
    set <ll> s;

    for(ll i=0; i<n; i++)
    {
        s.insert(i+1);

        ll a;
        cin >> a;

        q.pb(a);
    }

    vector <ll> p(n, 0);
    
    p[0] = q[0];
    s.erase(q[0]);

    for(ll i=1; i<n; i++)
    {
        if(q[i] != q[i-1])
        {
            p[i] = q[i];
            s.erase(q[i]);
        }

        else if(q[i] < i+1)
        {
            cout << -1 << endl;
            return;
        }
    }

    for(ll i=0; i<n; i++)
    {
        if(p[i] == 0)
        {
            p[i] = *s.begin();
            s.erase(s.begin());
        }
    }

    ll cur = -1;
    for(ll i=0; i<n; i++)
    {
        cur = max(cur, p[i]);

        if(cur != q[i])
        {
            cout << -1 << endl;
            return;
        }
    }

    for(ll i=0; i<n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        solve();
    }    

    return 0;
}