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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector <vector <ll>> v;

    for(ll i=0; i<m; i++)
    {
        vector <ll> temp;
        for(ll j=0; j<n; j++)
        {
            ll a;
            cin >> a;

            temp.pb(a);
        }

        v.pb(temp);
    }

    vector <ll> ans;
    ll minn = 1e15;

    for(ll i=0; i<n-1; i++)
    {
        // cout << "** " << i << endl;
        
        vector <ll> f, s;

        for(ll j=0; j<m; j++)
        {
            f.pb(v[j][i]);
            s.pb(v[j][n-1]);
        }

        vector <pll> p;

        ll temp1 = 0, temp2 = 0;
        for(ll j=0; j<m; j++)
        {
            temp1 += f[j];
            temp2 += s[j];

            p.pb(mp(f[j]-s[j], j));
        }

        // cout << "*** " << i << endl;

        if(temp1 >= temp2)
        {
            cout << 0 << endl;
            return 0;
        }

        sort(all(p));

        vector <bool> take(m+5, true);

        vector <ll> cur_remove;

        for(ll j=0; j<m; j++)
        {
            cur_remove.pb(p[j].ss);
            take[p[j].ss] = false;

            ll cntf = 0, cnts = 0;
            for(ll k=0; k<m; k++)
            {
                if(take[k] == true)
                {
                    cntf += f[k];
                    cnts += s[k];
                }
            }

            if(cntf >= cnts)
            {
                break;
            }
        }

        if(sz(cur_remove) < minn)
        {
            minn = sz(cur_remove);
            ans = cur_remove;
        }
    }

    cout << minn << endl;

    for(auto i: ans)
    {
        cout << i+1 << " ";
    }
    cout << endl;

    return 0;
}