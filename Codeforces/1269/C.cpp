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
ll s[L];

void print(ll n)
{
    cout << n << endl;

    for(ll i=0; i<n; i++)
    {
        cout << s[i];
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    string a;
    cin >> a;

    for(ll i=0; i<n; i++)
    {
        f[i] = a[i] - 48;
    }

    for(ll i=0; i<k; i++)
    {
        s[i] = f[i];

        for(ll j=i+k; j<n; j += k)
        {
            s[j] = s[i];
        }
    }

    bool less = false;

    ll pos = -1;

    for(ll i=0; i<n; i++)
    {
        if(s[i] < f[i])
        {
            less = true;
            break;
        }

        else if(s[i] > f[i])
        {
            break;
        }
    }

    if(!less)
    {
        // for(ll i=pos+1; )
        print(n);
        return 0;
    }

    else
    {
        for(ll i=k-1; i>=0; i--)
        {
            if(f[i] != 9)
            {
                f[i]++;
                break;
            }

            else
            {
                f[i] = 0;
            }
        }

        for(ll i=0; i<k; i++)
        {
            for(ll j=i+k; j<n; j+=k)
            {
                f[j] = f[i];
            }
        }

        cout << n << endl;
        for(ll i=0; i<n; i++)
        {
            cout << f[i];
        }
        cout << endl;
    }


    return 0;
}