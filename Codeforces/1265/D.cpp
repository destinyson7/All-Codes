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

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll tempa = a;

    if(b < tempa)
    {
        if(c == 0 && d == 0 && a == b+1)
        {
            cout << "YES" << endl;
            for(ll i=0; i<b; i++)
            {
                cout << 0 << " " << 1 << " ";
            }
            cout << 0 << endl;
            return 0;
        }

        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    ll tempb = b-a-1;

    ll tempd = d;

    if(c < tempd)
    {
        if(d == c+1 && b == 0 && a == 0)
        {
            cout << "YES" << endl;
            for(ll i=0; i<c; i++)
            {
                cout << 3 << " " << 2 << " ";
            }
            cout << 3 << endl;
            return 0;
        }

        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    ll tempc = c-d-1;

    if(tempb == tempc || abs(tempb-tempc) == 1)
    {
        cout << "YES" << endl;

        if(tempb == tempc)
        {
            for(ll i=0; i<a; i++)
            {
                cout << 0 << " " << 1 << " ";
            }

            b -= a;

            for(ll i=0; i<b; i++)
            {
                cout << 2 << " " << 1 << " ";
            }

            c -= b;

            for(ll i=0; i<d; i++)
            {
                cout << 2 << " " << 3 << " ";
            }
            cout << endl;
            // cout << 2 << endl;
        }

        else if(tempb > tempc)
        {
            cout << 1 << " ";

            for(ll i=0; i<a; i++)
            {
                cout << 0 << " " << 1 << " ";
            }

            b -= (a+1);

            for(ll i=0; i<b; i++)
            {
                cout << 2 << " " << 1 << " ";
            }

            c -= b;

            for(ll i=0; i<d; i++)
            {
                cout << 2 << " " << 3 << " ";
            }

            cout << endl;
        }

        else
        {
            for(ll i=0; i<a; i++)
            {
                cout << 0 << " " << 1 << " ";
            }

            b -= a;

            for(ll i=0; i<b; i++)
            {
                cout << 2 << " " << 1 << " ";
            }

            c -= b;

            for(ll i=0; i<d; i++)
            {
                cout << 2 << " " << 3 << " ";
            }

            cout << 2 << endl;
        }
    }

    else
    {
        cout << "NO" << endl;
        return 0;
    }

    return 0;
}