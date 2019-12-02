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

const ll L = 1e2+5;

ll b[L][L];
ll a[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll m, n;
    cin >> m >> n;

    for(ll i=0; i<m; i++)
    {
        for(ll j=0; j<n; j++)
        {
            cin >> b[i][j];
        }
    }

    for(ll i=0; i<m; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(b[i][j] == 1)
            {
                bool f = false;
                
                for(ll k=0; k<m; k++)
                {
                    if(b[k][j] == 0)
                    {
                        f = true;
                        break;
                    }
                }

                for(ll k=0; k<n; k++)
                {
                    if(b[i][k] == 0)
                    {
                        f = true;
                        break;
                    }
                }

                if(!f)
                {
                    a[i][j] = 1;
                }
            }
        }
    }

    for(ll i=0; i<m; i++)
    {
        for(ll j=0; j<n; j++)
        {
            ll c = 0;

            for(ll k=0; k<m; k++)
            {
                c |= a[k][j];
            }

            for(ll k=0; k<n; k++)
            {
                c |= a[i][k];
            }

            if(c != b[i][j])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    for(ll i=0; i<m; i++)
    {
        for(ll j=0; j<n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}