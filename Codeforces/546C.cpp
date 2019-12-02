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

    ll k1;
    cin >> k1;

    queue <ll> f, s;

    for(ll i=0; i<k1; i++)
    {
        ll t;
        cin >> t;

        f.push(t);
    }

    ll k2;
    cin >> k2;

    for(ll i=0; i<k2; i++)
    {
        ll t;
        cin >> t;

        s.push(t);
    }

    // queue <ll> copy1 = f, copy2 = s;

    ll cnt = 0;

    ll m = 1e7;

    while(m--)
    {
        if(f.empty())
        {
            cout << cnt << " 2" << endl;
            return 0;
        }

        else if(s.empty())
        {
            cout << cnt << " 1" << endl;
            return 0;
        }

        if(f.front() > s.front())
        {
            f.push(s.front());
            f.push(f.front());

            f.pop();
            s.pop();
        }

        else
        {
            s.push(f.front());
            s.push(s.front());

            f.pop();
            s.pop();
        }

        cnt++;

        // if(f == copy1 && s == copy2)
        // {
        //     cout << -1 << endl;
        //     return 0;
        // }
    }

    cout << -1 << endl;

    return 0;
}