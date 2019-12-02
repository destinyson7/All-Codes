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

vector <vector<ll>> solve(ll n)
{
    if(n==2)
    {
        vector <ll> v1 = {1, 2};
        vector <ll> v2 = {2, 1};

        vector <vector<ll>> re;
        re.pb(v1);
        re.pb(v2);

        return re;
    }

    vector <vector<ll>> ans = solve(n-1);

    // cout << ans << endl;

    vector <vector<ll>> ret;

    for(ll j=0; j<sz(ans); j++)
    {
        for(ll i=0; i<n; i++)
        {
            ret.pb(ans[j]);
        }
    }

    // cout << ret << " " << n << endl;

    ll fact = 1;

    for(ll i=1; i<=n; i++)
    {
        fact*=i;
    }

    ll j=0;
    for(ll i=0; i<fact/n; i++)
    {
        // for(ll j=0; j<n; j++)
        // {

            if(i%2 == 0)
            {
                // ll cnt = 0;
                for(ll k=n-1; k>=0; k--)
                {
                    ret[j].insert(ret[j].begin()+k, n);
                    // cnt++;
                    j++;
                }
            }

            else
            {
                for(ll k=0; k<n; k++)
                {
                    ret[j].insert(ret[j].begin()+k, n);
                    j++;
                }
            }
        // }
    }

    // cout << ret << endl;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    ll n;
    cin >> n;

    if(n==1)
    {
        cout << 1 << endl;
        return 0;
    }

    set <vector <ll>> s;

    vector <vector<ll>> print = solve(n);

    for(ll i=0; i<sz(print); i++)
    {
        s.insert(print[i]);
        for(ll j=0; j<sz(print[i]); j++)
        {
            cout << print[i][j] << " ";
        }
        cout << endl;
    }

    // cout << sz(s) << endl;
    // cout << v << endl;
    // vector <ll> v;

    // for(ll i=0; i<n; i++)
    // {
    //     v.pb(i+1);
    // }

    // ll fact = 1;

    // for(ll i=1; i<=n; i++)
    // {
    //     fact*=i;
    // }



    return 0;
}   