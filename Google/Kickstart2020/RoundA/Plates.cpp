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

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

const ll L = 1e5+5;

void solve(ll tc)
{
    ll N = nxt(), K = nxt(), P = nxt();

    vector <vector<ll>> v;

    for(ll i=0; i<N; i++)
    {
        vector <ll> temp(K);
        generate(all(temp), nxt);
        
        v.pb(temp);
    }

    ll ans = 0;

    while(P > 0)
    {
        vector <pair <pair<double, ll>, pll>> check;

        for(ll i=0; i<sz(v); i++)
        {
            ll sum = 0;

            for(ll j=0; j<min(P, sz(v[i])); j++)
            {
                sum += v[i][j];

                double avg = (double)sum/(double)(j+1);

                check.pb(mp(mp(avg, sum), mp(i, j)));
            }
        }

        sort(all(check));
        reverse(all(check));

        // cout << check[0] << endl;

        ans += check[0].ff.ss;
        P -= (check[0].ss.ss + 1);

        vector <vector<ll>> rep;

        for(ll i=0; i<sz(v); i++)
        {
            if(i != check[0].ss.ff)
            {
                rep.pb(v[i]);
            }

            else
            {
                vector <ll> temp2;

                for(ll j=check[0].ss.ss+1; j<sz(v[i]); j++)
                {
                    temp2.pb(v[i][j]);
                }

                if(!temp2.empty())
                {
                    rep.pb(temp2);
                }
            }
        }

        v = rep;
        // check.clear();
    }

    cout << "Case #" << tc << ": " << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    for(ll i=1; i<=T; i++)
    {
        solve(i);
    }

    return 0;
}